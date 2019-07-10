#include<stdio.h>
#include<assert.h>

//21.筛选法求100以内的所有素数
void Job1()
{
	int arr[101]={0};
	for(int i=0;i<100;i++)
	{
		arr[i]=i+1;
	}
	for(int j=3;j<100;j++)//从第三个元素，即4开始
	{
		for(int i=2;i<j;i++)
		{
			if(arr[j]%i==0)//素数赋值为0
			{
				arr[j]=0;
			}
		}
	}
	printf("100以内的素数有：\n");
	for(int i=0;i<100;i++)
	{
		if(arr[i]==0)//元素为0的跳过
		{
			continue;
		}
		printf("%d,",arr[i]);
	}
	printf("\n");
}
int main()
{
	Job1();
	return 0;
}
