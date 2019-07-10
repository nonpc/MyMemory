#include<iostream>

using namespace std;

//67.数组中重复的数字
/*
解题思路: 
现在让我们重排这个数组。从头到尾依次扫描这个数组中的每个数字。
当扫描到下标为i的数字时，首先比较这个数字(用m表示)是不是等于i。
如果是，则接着扫描下一个数字;如果不是，则再拿它和第m个数字进行比较。
如果它和第m个数字相等，就找到了一个重复的数字(该数字在下标为i和m的位置都出现了);
如果它和第m个数字不相等，就把第i个数字和第m个数字交换，把m放到属于它的位置。
接下来再重复这个比较、交换的过程，直到我们发现一个重复的数字。

代码中尽管有两重循环,但每个数字最多只要交换两次就能够找到属于它自己的位置,
因此时间复杂度为O(n),空间复杂度为O(1)

这道题还可以使用哈希表来完成,以空间换时间
*/
bool Fun(int *str,int len,int *str1)
{
	int k = 0;//str1下标
	for(int i = 0; i< len;i++)
	{
		if(str[i] < 0 || str[i] > len-1)
		{
			return false;
		}
	}
	for(int i = 0;i<len;i++)
	{
		while(str[i] != i)
		{
			if(str[i] == str[str[i]])
			{
				str1[str[i]] = str[i];//改进,将重复的数字放入数组对应下标的位置
				break;
			}
			int tmp = str[i];
			str[i] = str[tmp];
			str[tmp] = tmp;
		}
	}
	return false;
}

int main()
{
	//int str[] = {2,3,1,0,2,5,3};
	int str[] = {2,4,3,5,4,6,4,1,2,4,5};
	int len = sizeof(str)/sizeof(str[0]);
	int str1[20] = {0};
	Fun(str,len,str1);
	for(int i = 0;i <len;i++)
	{
		printf("%d ",str1[i]);
	}
	printf("\n");
	return 0;
}