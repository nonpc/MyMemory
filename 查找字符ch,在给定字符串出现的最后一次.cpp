//35.�����ַ�ch,�ڸ����ַ������ֵ����һ��
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