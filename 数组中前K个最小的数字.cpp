#include<stdio.h>
#include<assert.h>


//25.������ǰK����С������
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
	int end = 6;//ǰk��
	int k = Job(arr,start,end-1);
	printf("������ǰ%d����С������Ϊ��%d\n",end,k);
	return 0;
}