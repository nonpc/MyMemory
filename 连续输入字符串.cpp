//56.���������ַ���
/*
���������ַ���(�������ΪN,�ַ�������С��100),�밴����Ϊ8���ÿ���ַ���
��������µ��ַ�������.���Ȳ���8���������ַ������ں��油����0,���ַ���������
��:����:
"abc"
"123456789"
���:"abc00000"
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
	printf("������һ���ַ�:\n");
	char arr[100] ;
	scanf("%s",&arr);
	int len = strlen(arr);
	printf("%d\n",len);
	Fun(arr,len);
	return 0;
}
