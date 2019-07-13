//35.查找字符ch,在给定字符串出现的最后一次
int My_strrchr(const char *str,char ch)
{
	assert(str != NULL);
	for(int i = strlen(str)-1;i >= 0;i--)
	{
		if(str[i] == ch)
		{
			return i;
		}
	}
}