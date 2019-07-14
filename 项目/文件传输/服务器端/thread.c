#define _LARGEFILE64_SOURCE
#define _LARGEFILE_SOURCE
#define _FILE_OFFSET_BITS 64

#include"thread.h"
#include<fcntl.h>
#include<signal.h>
#include<sys/stat.h>
#include<sys/types.h>

#define ARGC 10
#define READ_BUFF 4096

/****************服务器端***************
 *
 *
 * ************************************/

void send_file(int c,char* name)
{
	//断点续传
	//对第二次收到客户端发送的消息进行甄别
	//如果后面含有文件的偏移量 , 
	//则说明是上次断开的文件 , 需要进行断点续传
	//按照客户端发送的偏移量进行偏移
	//然后开始传输数据
	
	
	//问题:客户端在传输过中 , 中断传输 ,  会造成服务器端的终止
	//原因: 在send的时候 , 突然中止 , 底层抛出一个SIGPIPE信号 , 
	//如果进程收到一个信号 但事先没有安排捕获它 , 进程就会立刻终止
	//而SIGPIPE的默认处理方式是终端进程
	//解决方法 , 使用signal(SIGPIPE,SIG_IGN); 屏蔽信号
	//头文件#include<signal.h>
	
	
	signal(SIGPIPE,SIG_IGN);
	if(name == NULL)
	{
		send(c,"err_name",8,0);
		return;
	}

	int fd = open(name,O_RDONLY | O_LARGEFILE);
	if(fd == -1)
	{
		send(c,"err",3,0);
		return;
	}

	long long size = lseek64(fd,0,SEEK_END);
	lseek64(fd,0,SEEK_SET);

	char res_buff[128] = {0};
	sprintf(res_buff,"ok#%lld",size);

	send(c,res_buff,strlen(res_buff),0);

	char cli_status[128] = {0};
	if(recv(c,cli_status,127,0) <= 0)
	{
		//客户端强制关闭
		close(fd);
		return;
	}


	if(strncmp(cli_status,"ok#",3) != 0)
	{
		//客户端不想下载
		close(fd);
		return;
	}



	if(strncmp(cli_status+3,"size#",4) == 0)
	{
		long long d_size = 0;
		sscanf(cli_status+8,"%lld",&d_size);
		//printf("d_size:%lld\n",d_size);
		if(d_size < 0)
		{
			send(c,"err_cli_size",12,0);
			return;
		}

		lseek64(fd,d_size,SEEK_SET);

		long long d_num = 0;
		char d_sendbuff[1024] = {0};
		while((d_num = read(fd,d_sendbuff,1024)) >0 )
		{
			send(c,d_sendbuff,d_num,0);
		}
		close(fd);
		return;
	}


	long long num = 0;
	//为什么是1024? 对传输时间有什么影响?
	char sendbuff[1024] = {0};
	while( (num = read(fd,sendbuff,1024)) >0)
	{
		//如果send发的数据很大 , 而且速度快 ,send就会出错
		send(c,sendbuff,num,0);
	}

	close(fd);
	return;
}

void recv_file(int c,char* name)
{
	//秒传
	//在第一次收到客户端的消息时 , 如果同名 , 
	//则计算文件的MD5值 , 使用system()来实现
	//然后发送给客户端
	//客户端比较本地文件MD5值 ,
	//根据客户端返回的结果 ,
    //如果是"same#file#" , 则确认秒传 	
	//如果不是 , 则为普通传输
	//如果相同 , 客户端将发送一个"same#file#"
	
	
	if(name == NULL)
	{
		send(c,"err_name",8,0);
		return;
	}
	
	int m_fd = open(name,O_RDONLY | O_LARGEFILE);
	if(m_fd != -1)
	{
		//打开成功
		//说明有相同文件
		char md_buff[128] = {0};
		sprintf(md_buff,"./my.sh %s",name);
		system(md_buff);
		int md_fd = open("md5.c",O_RDONLY | O_LARGEFILE);
		if(md_fd == -1)
		{
			printf("err_md_fd\n");
			return;
		}
		char md_res_buff[128] = {0};
		read(md_fd,md_res_buff,127);
		char *s = strtok(md_res_buff," ");
	//	printf("s=%s\n",s);

		close(md_fd);

		char m_res_buff[128] = {0};
		sprintf(m_res_buff,"ok#size#%s",s);
		send(c,m_res_buff,strlen(m_res_buff),0);

		char m_cli_status[128] = {0};
		if(recv(c,m_cli_status,127,0) <= 0)
		{
			return;
		}
		if(strncmp(m_cli_status,"same#file#",10) == 0)
		{
			send(c,"ok#",3,0);
			close(m_fd);
			return;
		}
		close(m_fd);
	}


	int fd = open(name,O_WRONLY | O_CREAT | O_LARGEFILE,0600);
	if(fd == -1)
	{
		send(c,"err",3,0);
		return;
	}

	char res_buff[128] = {0};
	sprintf(res_buff,"ok#%s",name);
	send(c,res_buff,strlen(res_buff),0);

	char cli_status[128] = {0};
	if(recv(c,cli_status,127,0) <= 0)
	{
		close(fd);
		//send(c,"err_recv",8,0);
		return;
	}
	if(strncmp(cli_status,"ok#size#",8) != 0)
	{
		close(fd);
		return;
	}

	long long size = 0;
	sscanf(cli_status+8,"%lld",&size);
	if(size == 0)
	{
		send(c,"err_size",8,0);
		return;
	}
	send(c,"ok#",3,0);

	long long num = 0;
	long long curr_size = 0;
	char recvbuff[1024] = {0};
	while((num = recv(c,recvbuff,1024,0)) > 0)
	{
		write(fd,recvbuff,num);
		curr_size += num;
		if(curr_size >= size)
		{
			break;
		}
	}

	close(fd);

}


void *work_thread(void *arg)
{
	int c = (int)arg;
	//recv
	//send
	while(1)
	{
		char buff[256] = {0};
		int n = recv(c,buff,255,0);//ls , mv a.c b.c , rm a.c
		if(n <= 0)
		{
			printf("one client over\n");
			
			break;
		}
		int i = 0;

		//printf("~~~%s\n",buff);

		char *myargv[ARGC] = {0};
		char *ptr = NULL;
		char *s = strtok_r(buff," ",&ptr);
		while(s != NULL)
		{
			myargv[i++] = s;
			s = strtok_r(NULL," ",&ptr);
		}
		char *cmd = myargv[0];//cdm 放的是命令
		if(cmd == NULL)
		{
			send(c,"err",3,0);
			continue;
		}
		
		//printf("~~~%s,%s\n",cmd,myargv[1]);


		if(strcmp(cmd,"get") == 0)
		{
			//下载
			send_file(c,myargv[1]);

		}
		else if(strcmp(cmd,"put") == 0)
		{
			//上传
			recv_file(c,myargv[1]);
		}
		else
		{
			//创建管道
			//将子进程重定向,  不要将输出打到屏幕 , 而是重定向到管道中 , 让父进程能够读取
			//在通过父进程将子进程反馈的信息 发送给客户端
	
			int pipefd[2];
			pipe(pipefd);

			pid_t pid = fork();
			if(pid == -1)
			{
				send(c,"err",3,0);
				continue;
			}
			if(pid == 0)
			{
			//	printf("hhhhhhhhh\n");

				//重定向
				dup2(pipefd[1],1);
				dup2(pipefd[1],2);
				//printf("%s,%s\n",cmd,myargv);

				execvp(cmd,myargv);
				
				//标准错误输出
				perror("cmd:err");
				exit(0);
			}
			close(pipefd[1]);//彻底关闭管道写端
			wait(NULL);
			char readbuff[READ_BUFF] = {"ok#"};
			read(pipefd[0],readbuff + 3,READ_BUFF - 4);
			//bug  一次读不完 , 或者小于4092就读完 , 要停止 , 设置标志??

			send(c,readbuff,strlen(readbuff),0);
			close(pipefd[0]);

		}

	}
	close(c);
}

int thread_start(int c)
{
	pthread_t id;
	int res = pthread_create(&id,NULL,work_thread,(void*)c);
	if(res != 0)
	{
		return -1;
	}

	return 0;
}

