/*************************************************************************
    > File Name: a.c
    > Author: DW*Joker
    > Mail: daemon.love@foxmail.com 
    > Created Time: Wed 15 May 2019 04:49:50 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>
#include<string.h>


int main()
{
	char buff[128] =  {0};
	sprintf(buff,"./my.sh %s","shizhong.mp4");
	system(buff);
	exit(0);
}

/*
int main()
{
	pid_t pid = fork();
	assert(pid != -1);

	if(pid == 0)
	{
		execl("./my.sh","my.sh","shizhong.mp4",(char*)0);

		printf("sssssssss\n");
		exit(0);
	}
	wait(NULL);
	printf("hhhhh\n");


	exit(0);
}

*/
