#include<stdio.h>
#include<assert.h>

//输出字符串并加上行号
void Job()
{
	char arr[40];
	int i=0;
	while(gets(arr)!=NULL)
	{
			i++;
			printf("请输入一串字符：");
			gets(arr);
			//scanf("%s",arr);
			printf("%d %s\n",i,arr);
	}
}
int main()
{
	Job();
	return 0;
}