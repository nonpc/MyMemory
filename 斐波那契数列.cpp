#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


/*
��쳲���������ǰ40��

����˼·����ǰ�����ʼ��Ϊ1���ӵ����ʼ���м��㡣
*/
void Fabonacio(int *arr,int len)
{
	assert(arr != NULL && len > 0);
	arr[0] = 1;
	arr[1] = 1;
	for(int i = 2;i < len;i++)
	{
		arr[i] = arr[i-1]+arr[i-2];
	}
}
void Show(int *arr,int len)
{
	for(int i = 0;i < len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[20] = {};
	int len = sizeof(arr)/sizeof(arr[0]);
	Fabonacio(arr,len);
	Show(arr,len);
	return 0;
}

/*
�ݹ�汾��
*/
int Job(int n)
{
	int f3=0;//�������ʼ��
	if(n==2)
	{
		return 1;
	}
	if(n==1)
	{
		return 1;
	}
	else
	{
		f3=Job(n-1)+Job(n-2);//������==ǰ����ĺ�
		return f3;
	}
}
int main()
{
	printf("%d\n",Job(8));
	return 0;
}