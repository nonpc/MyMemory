//41.���ַ����еĿո��滻Ϊ#25
/*
����˼·:
�ȱ���һ���ַ���,���м����ո�,Ȼ��̬�����µ�����,���ַ����Ӻ���ǰд���µ�������
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
