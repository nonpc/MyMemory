#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<signal.h>
#include<pwd.h>
#include<unistd.h>
#define MYPATH "/home/wb/LINUX/20190302/mybin/"


int main()
{
	while(1)
	{
		struct passwd *pwd;
		pwd = getpwuid(getuid());
		printf("\033[33m[\033[0m");
		printf("\033[33m%s\033[0m",pwd->pw_name);
		printf("\033[33m@localhost \033[0m");

		char name[80];
		getcwd(name,sizeof(name));
	if(name[0]=='/' && name[1] =='\0')
	{
		printf("\033[33m/]$ \033[0m");
	}
	else
	{
		char *nm = strtok(name,"/");
		char *realNM[20] = {0};
		while(nm != NULL)
		{
			realNM[0] = nm;
			nm = strtok(NULL,"/");
		}

		if(strncmp(realNM[0],"wb",2)==0)
		{
			printf("\033[33m~]$ \033[0m");
		}
		else
		{
			printf("\033[33m%s\033[0m",realNM[0]);
			printf("\033[33m]$ \033[0m");
		}
	}
		fflush(stdout);

		char buff[128] = {0};
		fgets(buff,128,stdin);

		buff[strlen(buff)-1] = 0;
		
		char *s = strtok(buff," ");
		if(s == NULL)
		{
			continue;
		}
		char* myargv[10] = {0};
		int i = 0;
		while(s != NULL)
		{
			myargv[i++] = s;
			s = strtok(NULL," ");
		}

		if(myargv[0]==0)
		{
			continue;
		}
		if(strcmp(myargv[0],"exit")==0)
		{
			break;
		}
		else if(strcmp(myargv[0],"cd")==0)
		{
			if(myargv[1] == NULL)
			{
				continue;
			}
			chdir(myargv[1]);
			continue;
		}
		pid_t pid = fork();
		assert(pid != -1);
		if(pid ==0)
		{
			char path[256] = {0};
			if(strncmp(myargv[0],"./",2) != 0 && strncmp(myargv[0],"/",1)!=0)
			{
				strcpy(path,MYPATH);

			}
			strcat(path,MYPATH);
			execv(path,myargv);
			perror("execv error");
			exit(0);
		}
		wait(NULL);
	}
	exit(0);
}
