/*************************************************************************
    > File Name: myls.c
    > Author: DW*Joker
    > Mail: daemon.love@foxmail.com 
    > Created Time: Sat 02 Mar 2019 08:02:04 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#define SIZE_MAX 100

int cmp(const void *a,const void *b)
{
	return (strcmp((char*)a,(char*)b));
}

int main()
{
	char path[256] = {0};
	getcwd(path,256);  //获得当前工作目录
	DIR *pdir = opendir(path);
	if(pdir == NULL)
	{
		exit(1);
	}
	struct dirent *p = NULL;
	struct stat st;
	int total = 0;
	long block=0;
	char s[SIZE_MAX][SIZE_MAX] = {0};
	int count = 0;
	while((p = readdir(pdir)) != NULL)//计算total
	{
		stat(p->d_name,&st);
		if(strncmp(p->d_name,".",1) == 0)
		{
			continue;
		}
		if(st.st_size <=  4096)
		{
			block++;
		}
		else
		{
			block += (st.st_size/4096) +1;
		}
		strcpy(s[count++],p->d_name);
	}
	qsort(s,count,sizeof(s[0]),cmp);
	closedir(pdir);
	
	total = block*4;
	printf("total %d\n",total);
	int i = 0;
	for(i = 0;i < count;i++)
	{
		pdir = opendir(path);
		while((p = readdir(pdir)) != NULL)
		{
			if(strncmp(p->d_name,".",1) == 0)
			{
				continue;
			}	
			if(strcmp(p->d_name,s[i]) != 0)
			{
				continue;
			}
			stat(p->d_name,&st);
			if(S_ISDIR(st.st_mode))//判断是否为目录
			{
				printf("d");
			}
			if((st.st_mode & S_IFREG) == S_IFREG)//是否为普通文件
			{
				printf("-");
			}
			if((st.st_mode & S_IFLNK) == S_IFLNK)//是否为链接文件
			{
				printf("l");
			}
			if((st.st_mode & S_IFCHR) == S_IFCHR)//是否为字符特殊文件
			{
				printf("c");
			}
			if((st.st_mode & S_IFBLK) == S_IFBLK)//是否为块特殊文件
			{
				printf("b");
			}
			if((st.st_mode & S_IFIFO) == S_IFIFO)//是否为管道或FIFO文件
			{
				printf("p");
			}
			if((st.st_mode & S_IFSOCK) == S_IFSOCK)//是否为套接字文件
			{
				printf("s");
			}
			if((st.st_mode & S_IRUSR) == S_IRUSR)
			{
				printf("r");	
			}
			else
			{
				printf("-");
			}
			if((st.st_mode & S_IWUSR) == S_IWUSR)
			{	
				printf("w");
			}
			else
			{
				printf("-");
			}
			if((st.st_mode & S_IXUSR) == S_IXUSR)
			{
				printf("x");
			}
			else
			{
				printf("-");
			}
			if((st.st_mode & S_IRGRP) == S_IRGRP)
			{
				printf("r");
			}
			else
			{
				printf("-");
			}
			if((st.st_mode & S_IWGRP) == S_IWGRP)
			{
				printf("w");
			}
			else
			{
				printf("-");
			}
			if((st.st_mode & S_IXGRP) == S_IXGRP)
			{
				printf("x");
			}
			else
			{
				printf("-");
			}
			if((st.st_mode & S_IROTH) == S_IROTH)
			{
				printf("r");
			}
			else
			{
				printf("-");
			}
			if((st.st_mode & S_IWOTH) == S_IWOTH)
			{
				printf("w");
			}
			else
			{
				printf("-");
			}
			if((st.st_mode & S_IXOTH) == S_IXOTH)
			{
				printf("x");
			}
			else
			{
				printf("-");
			}
			printf(". ");
			printf("%d ",st.st_nlink);//硬连接数

			struct passwd *pwd;
			pwd = getpwuid(st.st_uid);//所有者用户识别码
			printf("%-4s ",pwd->pw_name);

			struct group *grp;
			grp = getgrgid(st.st_gid);//组识别码
			printf("%-4s ",grp->gr_name);
			printf("%5d ",st.st_size);//以字节为单位的文件容量

			struct tm *t = localtime(&st.st_mtime);//转换为人类可识别的时间
			char *wday[12] = {"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
			printf("%s  %d ",wday[t->tm_mon],t->tm_mday);
			if(t->tm_hour < 10)
			{
				printf("0%d:",t->tm_hour);
			}
			else
			{
				printf("%d:",t->tm_hour);
			}
			if(t->tm_min < 10)
			{
				printf("0%d ",t->tm_min);
			}
			else
			{
				printf("%d ",t->tm_min);
			}

			if(S_ISDIR(st.st_mode))
			{
				printf("\033[1;34m%s \n\033[0m",p->d_name);
			}
			else
			{
				if(st.st_mode&(S_IXUSR | S_IXGRP | S_IXOTH))
				{
					printf("\033[1;32m%s \n\033[0m",p->d_name);
				}
				else
				{
					printf("%s \n",p->d_name);
				}
			}	
		}
		closedir(pdir);
	}
	exit(0);
}
