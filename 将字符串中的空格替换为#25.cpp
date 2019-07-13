//41.将字符串中的空格替换为#25
/*
解题思路:
先遍历一遍字符串,看有几个空格,然后动态开辟新的数组,将字符串从后向前写入新的数组中
*/
int Job(char *arr)
{
	assert(arr != NULL);
	int count = 0;
	while(*arr != '\0')
	{
		if(*arr == ' ')
		{
			count++;
		}
		arr++;
	}
	return count;
}
char* Job1(char *arr,int len,char *brr)
{
	assert(arr != NULL);
	while(*arr != '\0')
	{
		if(*arr == ' ')
		{
			*brr = '#';
			brr++;
			*brr = '2';
			brr++;
			*brr = '5';
			brr++;
			arr++;
		}
		else
		{
			*brr = *arr;
			brr++;
			arr++;
		}
	}
	*brr = '\0';
	return brr;
}


int main()
{
	char arr[] = "i am tulun";
	int len = sizeof(arr)/sizeof(arr[0]);
	char *brr = (char *)malloc(sizeof(char)*(len + Job(arr)*3));
	Job1(arr,len,brr);
	printf("%s\n",brr);

	return 0;
}
