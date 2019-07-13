//59.介于0到1000000之间的n个整数，请对他们进行排序，要求时间复杂度为O(n) 
/*
(2018西安场-腾讯面试题)
解题思路:哈希数组,开辟一个含有1000000个元素的数组,使用他们的下标记录数字,
如果有,置为true,如果没有则为false,最后便利一遍哈希数组,输出结果
*/
void Fun(int *arr,int len)
{
	assert(arr != NULL);
	bool tmp[1000000] = {false};
	for(int i = 0;i < len ;i ++)
	{
		tmp[arr[i]] = true; 
	}
	printf("排序后的数据为:\n");
	for(int i = 0; i< 1000000 ;i++)
	{
		if(tmp[i] == false)
		{
			continue;
		}
		printf("%d ",i);
	}
	printf("\n");
}

int main()
{
	int arr[70] = {0};
	srand((unsigned)time(NULL));
	for(int i = 0;i < 70;i++)
	{
		arr[i] = rand()%1000+0;
	}
	int len = sizeof(arr)/sizeof(arr[0]);
	Fun(arr,len);

	return 0;
}
