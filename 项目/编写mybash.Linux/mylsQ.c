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
#define SIZE_MAX 100

int cmp(const void *a,const void *b)
{
	return (strcmp((char*)a,(char*)b));
}

int main()
{
	char path[256] = {0};
	getcwd(path,256);
	DIR *pdir = opendir(path);
	if(pdir == NULL)
	{
		exit(1);
	}
	struct dirent *p = NULL;
	struct stat st;
	int count = 0;
	char s[SIZE_MAX][SIZE_MAX];
	while((p = readdir(pdir)) != NULL)
	{
		if(strncmp(p->d_name,".",1) == 0)
		{
			continue;
		}
		stat(p->d_name,&st);
		if(S_ISDIR(st.st_mode))
		{
			s[count][SIZE_MAX -1] = '9';
		}
		else
		{
			if(st.st_mode&(S_IXUSR | S_IXGRP | S_IXOTH))
			{
				s[count][SIZE_MAX -1] = '8';
			}
		}
		strcpy(s[count++],p->d_name);
	}
	qsort(s,count,sizeof(s[0]),cmp);
	int i = 0;
	for(i = 0;i < count;i++)
	{
		if(s[i][SIZE_MAX -1] == '9')
		{
			printf("\033[1;34m%s  \033[0m",s[i]);
		}
		else
		{
			if(s[i][SIZE_MAX -1] == '8')
			{
				printf("\033[1;32m%s  \033[0m",s[i]);
			}
			else
			{
				printf("%s  ",s[i]);
			}
		}
	}
	printf("\n");
	closedir(pdir);
	exit(0);
}
