#include<stdio.h>
#include<assert.h>

//����ַ����������к�
void Job()
{
	char arr[40];
	int i=0;
	while(gets(arr)!=NULL)
	{
			i++;
			printf("������һ���ַ���");
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