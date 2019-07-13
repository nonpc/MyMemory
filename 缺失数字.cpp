//62.缺失数字
/*
给定一个包含0,1,2,...n 中n个数的排列,列出0...n中没有出现在序列
中的那个数

解题思路:使用哈希表,记录已有的,输出没有的 
*/
void Fun(int *arr,int len)
{
	assert(arr != NULL);
	bool tmp[100] = {false};
	for(int i = 0; i < len;i++)
	{
		tmp[arr[i]] = true;
	}
	printf("缺失数字为:\n");
	for(int i = 0; i< 100 ;i++)
	{
		if(tmp[i] == false)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}

int main()
{
	int arr[] = {1,5,4,6,2,7,8,9,48,45,31,16,13};
	int len = sizeof(arr)/sizeof(arr[0]);
	Fun(arr,len);
	
	return 0;
}
