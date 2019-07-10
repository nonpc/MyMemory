#include<stdio.h>
#include<assert.h>


//24.求一个有序数组中两个值相加为k的数字，返回这两个数字的下标。
void Job3(int *arr,int len,int key)
{
	int bgn=0;
	int end=len-1;
	for(int i=0;i<len;i++)//有序数组(前提是1开头)，相加为k，则k==第一个元素+k的前一个元素
	{
		if(arr[i]==key)
		{
			end=i-1;
			break;
		}
	}
	printf("这两个数字的下标为：\n");
	while(arr[bgn]+arr[end]==key&&bgn<=end)
	{
		printf("%d %d\n",bgn,end);
		bgn++;
		end--;
	}
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(arr[0]);
	int key=8;
	printf("key为：%d\n",key);
	Job3(arr,len,key);
	return 0;
}