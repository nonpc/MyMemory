#include<iostream>

using namespace std;

/*
解题思路 : 
	数组中的数字都在 0~n-1 , 的范围内 , 将这些写数字按照从小到大的顺序排列 ,数字 i 将出现在下标 i 的位置
	由于数组由重复的数字 , 同时有些位置就有可能没有数字
*/

bool duplicate(int num[] , int len , int* duplication)
{
	if(num == nullptr || len <= 0)
		return false;
	for(int i = 0; i < len ;++i)
	{
		if(num[i] < 0 || num[i] > len - 1)
			return false;
	}
	for(int i = 0 ; i < len ;++i)
	{
		while(num[i] != i)
		{
			if(num[i] == num[num[i]])
			{
				*duplication = num[i];
				return true;
			}
			//交换 num[i] 和 num[num[i]]
			int tmp = num[i];
			num[i] = num[tmp];
			num[tmp] = tmp;
		}
	}
	return false;
}