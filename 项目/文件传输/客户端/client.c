#define _LARGEFILE64_SOURCE
#define _LARGEFILE_SOURCE
#define _FILE_OFFSET_BITS 64


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<assert.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/stat.h>
#include<sys/types.h>


#define PORT 6000
#define IPSTR "127.0.0.1"
#define LIS_MAX 5

int connect_to_ser();
/*******************客户端*******************
 * stu  5,9   create_socket()  创建套接字 ,
 *
 * *****************************************/

			
void recv_file(int sockfd,char *name);

void send_file(int sockfd,char *name);

int main()
{
	int sockfd = connect_to_ser();
	//assert(sockfd != -1);
	if(sockfd == -1)
	{
		printf("connect to ser \n");
		return 0;
	}
	while(1)
	{
		char buff[128] = {0};
		printf("Connect>>");
		fflush(stdout);

		fgets(buff,128,stdin);//ls , rm a.c  get a.c ,sdsf
		buff[strlen(buff) - 1] = 0;

		if(buff[0] == 0)
		{
			continue;
		}

		char sendbuff[128] = {0};
		strcpy(sendbuff,buff);
		int i = 0;
		char *myargv[10] = {0};
		char *s = strtok(buff," ");
		while(s != NULL)
		{
			myargv[i++] = s;
			s = strtok(NULL," ");
		}
		if(myargv[0] == NULL)
		{
			continue;
		}

		if(strcmp(myargv[0],"exit") == 0)
		{
			break;
		}
		else if(strcmp(myargv[0],"get") == 0)
		{
			if(myargv[1] == NULL)
			{
				continue;
			}
			send(sockfd,sendbuff,strlen(sendbuff),0);
			recv_file(sockfd,myargv[1]);

		}
		else if(strcmp(myargv[0],"put") == 0)
		{
			if(myargv[1] == NULL)
			{
				continue;
			}
			send(sockfd,sendbuff,strlen(sendbuff),0);
			send_file(sockfd,myargv[1]);
		}
		else
		{
			if((strcmp(myargv[0],"ls") == 0) || (strcmp(myargv[0],"rm") == 0) || (strcmp(myargv[0],"mv") == 0))
			{

				send(sockfd,sendbuff,strlen(sendbuff),0);

				char readbuff[4096] = {0};
				recv(sockfd,readbuff,4095,0);
				if(strncmp(readbuff,"ok#",3) != 0)
				{
					printf("err");
					continue;
				}
			
				printf("%s",readbuff + 3);	
			}
			else
			{
				printf("This is err_order\n");
				continue;
			}
		}
	}	
	close(sockfd);
	
}


void recv_file(int sockfd,char *name)
{
	//断点续传
	//先判断本地是否此有文件
	//无同名文件 , 则为普通下载
	//有同名文件文件
	//判断其大小 是否和服务器端相同
	//相同 , 则为普通下载
	//不同 , 则说明是上一次下载中断的 , 需要进行断点续传
	//第二次发送消息 , 附加文件的偏移量
	//将本地文件光标移到最后  , 等待接收服务器端发送的文件
	
	
	int d_fd = open(name,O_WRONLY | O_LARGEFILE);
	if(d_fd != -1)
	{
		//说明有与服务器端同名的文件
		char d_buff[128] = {0};
		if(recv(sockfd,d_buff,127,0) <= 0)
		{
			return;
		}
		if(strncmp(d_buff,"ok#",3) != 0)
		{
			printf("Error:%s\n",d_buff+3);
			return;
		}

		long long d_size = 0;
		printf("d_file size :%s\n",d_buff+3);
		sscanf(d_buff+3,"%lld",&d_size);
		if(d_size == 0)
		{
			send(sockfd,"err_size",8,0);
			return;
		}

		long long fd_size = lseek64(d_fd,0,SEEK_END);


		//同名但是fd_sie == 0



		if(d_size != fd_size)
		{
			printf("local file size:%lld\n",fd_size);
			char d_res_buff[128] = {0};
			sprintf(d_res_buff,"ok#size#%lld",fd_size);
			send(sockfd,d_res_buff,strlen(d_res_buff),0);
			
			char d_recvbuff[1024] = {0};
			long long d_num = 0;
			long long d_curr_size = fd_size;
			
			while((d_num = recv(sockfd,d_recvbuff,1024,0)) > 0)
			{
				write(d_fd,d_recvbuff,d_num);
				d_curr_size += d_num;
				float d_f = d_curr_size * 100.0 / d_size;
				printf("\033[?25l*下载进度*:%.2f%%\r",d_f);
				fflush(stdout);
				if(d_curr_size >= d_size)
				{
					break;
				}
			}
			printf("\n文件下载完成\n");
		}
		close(d_fd);
        return;
	}

	//说明本地没有此文件
		//printf("d_fd=%d\n",d_fd);
	//	printf("Have not this file\n");
	//	return;
	

	
	char buff[128] = {0};
	if(recv(sockfd,buff,127,0) <= 0)		
	{
		return;
	}
	if(strncmp(buff,"ok#",3) != 0)//ok#345
	{
		//前三个字符不是OK#  说明出错	
		printf("Error:%s\n",buff+3);
		return;
	}
	
	long long size = 0;
	printf("file size :%s\n",buff+3);
	sscanf(buff+3,"%lld",&size);
	//是否要下载
	
	//如果文件的大小为0
	if(size == 0)
	{
		send(sockfd,"err",3,0);
		return;
	}

	int fd = open(name,O_WRONLY | O_CREAT | O_LARGEFILE ,0600);
	//多次下载相同的文件,文件名扩展(没写 , 直接覆盖)
	if(fd == -1)
	{
		send(sockfd,"err",3,0);
		return;
	}
	send(sockfd,"ok#",3,0);
	char recvbuff[1024] = {0};
	long long num = 0;
	long long curr_size = 0;
	//printf("111111111\n");
	while((num = recv(sockfd,recvbuff,1024,0)) > 0)
	{
		write(fd,recvbuff,num);
		curr_size += num;
		float f = curr_size * 100.0 / size;
		printf("\033[?25l*下载进度*:%.2f%%\r",f);
		fflush(stdout);

		if(curr_size >= size)
		{
			break;
		}
	}
	printf("\n文件下载完成\n");
	//md5sun 文件名  校验文件是否被修改
	close(fd);	
	
}


void send_file(int sockfd,char *name)
{
	//秒传
	//对服务器发送回的消息进行甄别 ,
	//如果含有MD5值 , 则需要计算本地文件的MD5值 ,使用system()
	//并与服务器端的相比较 , 
	//如果不是 , 则为普通上传
	//如果相同 , 则为秒传 , 
	//客户端将发送一个"same#file#"  ,  确认为相同文件
	
	
	//问题:客户端在传输过中 , 中断传输 ,  会造成服务器端的终止
	//原因: 在send的时候 , 突然中止 , 底层抛出一个SIGPIPE信号 , 
	//如果进程收到一个信号 但事先没有安排捕获它 , 进程就会立刻终止
	//而SIGPIPE的默认处理方式是终端进程
	//解决方法 , 使用signal(SIGPIPE,SIG_IGN); 屏蔽信号
	//头文件#include<signal.h>
	
	signal(SIGPIPE,SIG_IGN);
	
	if(name == NULL)
	{
		printf("send_file:err_name\n");
		return;
	}

	char buff[128] = {0};
	if(recv(sockfd,buff,127,0) <= 0)
	{
		return;
	}
	if(strncmp(buff,"ok#",3) != 0)
	{
		printf("Error:%s\n",buff+3);
		return;
	}
	if(strncmp(buff,"ok#size#",8) == 0)
	{
		
		//甄别
		char m_buff[128] = {0};
		strcpy(m_buff,buff+8);
		//printf("m_buff;%s\n",m_buff);

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
		//printf("s=%s\n",s);

		close(md_fd);
		if(strcmp(m_buff,s) == 0)
		{
			
			//是相同文件
			send(sockfd,"same#file#",10,0);
			char m_cli_status[64] = {0};
			if(recv(sockfd,m_cli_status,63,0) <= 0)
			{
				return;
			}
			if(strncmp(m_cli_status,"ok#",3) != 0)
			{
				return;
			}
			printf("*上传完成*\n");
			return;
		}
	}
	
	int fd = open(name,O_RDONLY | O_LARGEFILE);
	if(fd == -1)
	{
		send(sockfd,"err_file",8,0);
		return;
	}

	long long size = lseek64(fd,0,SEEK_END);
	lseek64(fd,0,SEEK_SET);

	char res_buff[128] = {0};
	sprintf(res_buff,"ok#size#%lld",size);
	send(sockfd,res_buff,strlen(res_buff),0);

	char cli_status[64] = {0};
	if(recv(sockfd,cli_status,63,0) <= 0)
	{
		close(fd);
		return;
	}
	if(strncmp(cli_status,"ok#",3) != 0)
	{
		close(fd);
		return;
	}

	long long num = 0;
	long long curr_size = 0;
	char sendbuff[1024] = {0};
	printf("file size:%d\n",size);
	while((num = read(fd,sendbuff,1024)) > 0)
	{	
		send(sockfd,sendbuff,num,0);
		curr_size += num;
		float f = curr_size * 100.0 /size;
		printf("\033[?25l*上传进度*:%.2f%%\r",f);
		fflush(stdout);
	}
	printf("\n文件上传完成!\n");
	close(fd);

}


int connect_to_ser()
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
	{
		return -1;
	}
	struct sockaddr_in saddr;
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(PORT);
	saddr.sin_addr.s_addr = inet_addr(IPSTR);

	int res = connect(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
	if(res == -1)
	{
		return -1;
	}
	return sockfd;
}
