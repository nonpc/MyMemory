//56.连续输入字符串
/*
连续输入字符串(输出次数为N,字符串长度小于100),请按长度为8拆分每个字符串
后输出到新的字符串数组.长度不是8整数倍的字符串请在后面补数字0,空字符串不处理
如:输入:
"abc"
"123456789"
输出:"abc00000"
"12345678"
"90000000"
*/
void Fun(char *str,int len)
{
	assert(str != NULL);
	int count = 1;
	if(len > 8)
	{
		for(int i = 0; i < len ;i++)
		{
			if(i == count*8)
			{
				printf("\n");
				count++;
			}
			if(i+1 == len && i != count*8)
			{
				printf("%c",str[i]);
				while(i+1 != count*8)
				{
					printf("0");
					i++;
				}
				printf("\n");
			}
			printf("%c",str[i]);
		}
	}
	else
	{
		int i ;
		for( i = 0;i < len;i++)
		{
			printf("%c",str[i]);
		}
		while(i != 8)
		{
			printf("0");
			i++;
		}
		printf("\n");
	}
}

int main()
{
	printf("请输入一串字符:\n");
	char arr[100] ;
	scanf("%s",&arr);
	int len = strlen(arr);
	printf("%d\n",len);
	Fun(arr,len);
	return 0;
}
