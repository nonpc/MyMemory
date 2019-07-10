#include<stdio.h>
#include<assert.h>


//22.字符串相加Hello world! 102
void Job1()
{
	char arr[40];
	signed char checksum=-1;
	int i=0;
	printf("输入字符串：");
	gets(arr);
	while(arr[i]!='\0')
	{
		checksum+=arr[i];
		i++;
	}
	checksum+='\n';//回车
	printf("输出结果：%s  %d\n",arr,checksum);
}
int main()
{
	Job1();
	return 0;
}