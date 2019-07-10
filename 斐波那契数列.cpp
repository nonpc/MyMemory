#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


/*
求斐波那契数列前40项

解题思路：将前两项初始化为1，从第三项开始进行计算。
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
递归版本：
*/
int Job(int n)
{
	int f3=0;//第三项初始化
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
		f3=Job(n-1)+Job(n-2);//第三项==前两项的和
		return f3;
	}
}
int main()
{
	printf("%d\n",Job(8));
	return 0;
}