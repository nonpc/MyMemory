#include<stdio.h>
#include<assert.h>

//70.��ת�������С����
/*
����˼·:
����ת������鿴��������������
��������ָ��,���������������,���յ�һ��ָ���ָ���һ����������,
���ڶ���ָ���ָ��ڶ����������Ԫ��,����ʱ����ָ�������ڵ�.
�ڶ���ָ����ָ��λ��������С������
ʱ�临�Ӷ�O(logn)

ע:Ҫ������,{1,0,1,1,1},����������,��{0,1,1,1,1}����ת����
��������������,ֻ�ܴ�ͷ��������
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
