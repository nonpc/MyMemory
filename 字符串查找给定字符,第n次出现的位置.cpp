//36.字符串查找给定字符,第n次出现的位置
int My_strnchr(const char *str,char ch,int n)
{
	assert(str != NULL);
	int count = 0;
	for(int i = 0;i < strlen(str);i++)
	{
		if(str[i] == ch)
		{
			count++;
			if(count == n)
			{
				return i;
			}
		}
	}
}
