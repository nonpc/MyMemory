//37.strlen()函数实现
int My_strlen(const char *str)
{
	assert(str != NULL);
	int len = 0;
	while(*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

//38.strchr()函数实现
int My_strchr(const char* str,char ch)
{
	assert(str != NULL);
	int count = 0;
	while(*str != '\0')
	{
		if(*str == ch)
		{
			return count;
		}
		count++;
		str++;
	}
}

//39.strstr()函数实现
int My_strstr(char *str1, char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	char *pb = str1;
	char *pe = str2;
	int i = 0;
	int j = 0;
	while(i < strlen(str1) && j < strlen(str2))
	{
		if(pb[i] == pe[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1;
			j = 0;
		}
	}
	if(j == strlen(str2))
	{
		return i-strlen(str2);
	}
}


int main()
{
	char arr[] = "abcdefghijklmnopqrst";
	char brr[] = "hij";
	printf("%d\n",My_strlen(arr));
	char d = 'd';
	printf("%d\n",My_strstr(arr,brr));

	return 0;
}
