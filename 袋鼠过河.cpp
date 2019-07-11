#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


//52.袋鼠过河
/*
一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩子，每隔一米就有一个,
每个桩子上都有一个弹簧，袋鼠跳到弹簧上就可以跳的更远。每个弹簧力量不同，
用一个数字代表它的力量，如果弹簧力量为5，就代表袋鼠下一跳最多能够跳5米，
如果为0，就会陷进去无法继续跳跃。河流一共N米宽，袋鼠初始位置就在第一个弹簧上面，
要跳到最后一个弹簧之后就算过河了，给定每个弹簧的力量，
求袋鼠最少需要多少跳能够到达对岸。如果无法到达输出-1 
*/

int Fun(int *arr,int n)
{
	assert(arr != NULL);
	int i = 0;
	int count = 0;
	while(i < n)
	{
		if(arr[i] == 0)
		{
			printf("不能跳出\n");
			return -1;
		}
		else
		{
			if(i == n-1|| i+arr[i] >= n)//落在最后一个柱子,或者当前位置起跳的力度可以到达对岸
			{
				count++;
				printf("可以跳出\n");
				printf("需要跳%d级\n",count);
				return 0;
			}
			count++;
			i += arr[i];
		}
	}
	printf("不能跳出\n");
	return -1;
}

int main()
{
	//int arr[] = {2,0,1,1,1};
	//int arr[] = {4,3,2,1,1,4,2,2,4,6,7};
	//int arr[] = {2,1,0,3,4,5};
	int arr[] = {5,1,2,0,4,2,0,2,0,4,0,0,1,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	Fun(arr,len);
	return 0;
}
