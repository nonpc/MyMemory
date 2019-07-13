//51.字符串转化为IP,不判断ip是否合法
void Show(char *str,int *arr,int len)
{
	printf("%s\n",str);
	printf("==============\n");
	for(int i = 0;i < len ;i++)
	{
		if(arr[i] == '.')
		{
			printf(".");
			continue;
		}
		printf("%d",arr[i]);
	}
	printf("\n");
}

void Fun(char *str)
{
	assert(str != NULL);
	char *p = str;
	int len = strlen(str);
	int *arr = (int *)calloc(len,sizeof(int));
	int *pe = arr;
	while(*p != NULL)
	{
		if(*p == '.')
		{
			*pe = *p;
			p++;
			pe++;
		}
		*pe = *p-48;
		p++;
		pe++;
	}
	Show(str,arr,len);
}

int main()
{
	char str[] = "192.168.0.12";
	//printf("%s\n",str);
	Fun(str);
	return 0;
}
