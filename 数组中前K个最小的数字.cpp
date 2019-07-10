#include<stdio.h>
#include<assert.h>


//25.数组中前K个最小的数字
int Job(int *arr,int low,int high)
{
	int tmp ;
	while(low < high)
	{
		while(arr[low] > arr[high] && low < high)
		{
			low++;
		}
		while(arr[low] < arr[high] && low < high)
		{
			high--;
		}
	}
	tmp = arr[low];
	return tmp;
}
int main()
{
	int arr[] = {14,5,9,21,11,3,7,19};
	int start = 0;
	int end = 6;//前k个
	int k = Job(arr,start,end-1);
	printf("数组中前%d个最小的数字为：%d\n",end,k);
	return 0;
}