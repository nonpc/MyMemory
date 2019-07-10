#include<stdio.h>
#include<assert.h>

//70.旋转数组的最小数字
/*
解题思路:
将旋转后的数组看作是两个子数组
设置两个指针,讲他们依次向后走,最终第一个指针会指向第一个数组的最后,
而第二个指针会指向第二个数组的首元素,即此时两个指针是相邻的.
第二个指针所指的位置正是最小的数字
时间复杂度O(logn)

注:要考虑如,{1,0,1,1,1},这样的数组,是{0,1,1,1,1}的旋转数组
如果是这样的情况,只能从头遍历数组
*/

int MinInOrder(int *numbers,int index1,int index2)
{
	int result = numbers[index1];
	for(int i = index1+1; i <= index2;i++)
	{
		if(result > numbers[i])
		{
			result = numbers[i];
		}
	}
	return result;
}

int Min(int *numbers,int len)
{
	assert(numbers != NULL);
	if(len < 0)
	{
		return -1;
	}
	int index1 = 0;
	int index2 = len-1;
	int indexmid = index1;
	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1)
		{
			indexmid = index2;
			break;
		}
		indexmid = (index1 + index2) / 2;
		if(numbers[index1] == numbers[index2] && numbers[indexmid] == numbers[index1])
		{
			return MinInOrder(numbers,index1,index2);
		}
		if(numbers[indexmid] >= numbers[index1])
		{
			index1 = indexmid;
		}
		else if(numbers[indexmid] <= numbers[index2])
		{
			index2 = indexmid;
		}
	}
	return numbers[indexmid];
}

int main()
{
	//int arr[] = {3,4,5,1,2};
	int arr[] = {1,0,1,1,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("Min is %d\n",Min(arr,len));
	return 0;
}
