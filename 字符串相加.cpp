#include<stdio.h>
#include<assert.h>


//22.�ַ������Hello world! 102
void Job1()
{
	char arr[40];
	signed char checksum=-1;
	int i=0;
	printf("�����ַ�����");
	gets(arr);
	while(arr[i]!='\0')
	{
		checksum+=arr[i];
		i++;
	}
	checksum+='\n';//�س�
	printf("��������%s  %d\n",arr,checksum);
}
int main()
{
	Job1();
	return 0;
}