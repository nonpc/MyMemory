//58.合并两个有序的数组  时间复杂度O(n)  空间O（1）
//空间复杂度O(1)是说明空间复杂度与数组规模n没有关系,即开辟固定长度的哈希数组
void Fun(int* arr,int* brr,int len1,int len2)
{
	assert(arr != NULL && brr != NULL);
	bool tmp[255] = {false};
	for(int i = 0; i< len1 ;i++)
	{
		tmp[arr[i]] = true;
	}
	for(int i = 0; i < len2;i++)
	{
		tmp[brr[i]] = true;
	}
	for(int i = 0;i < 255;i++)
	{
		if(tmp[i])
		{
			printf("%d ",(char)i);
		}
	}
	printf("\n");
}

int main()
{
	int arr[] = {1,2,3,4,7,12,14,16};
	int brr[] = {1,3,4,5,6,13,14,16,17};
	int len1 = sizeof(arr)/sizeof(arr[0]);
	int len2 = sizeof(brr)/sizeof(brr[0]);
	Fun(arr,brr,len1,len2);

	return 0;
}
