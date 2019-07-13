//55.查找一个字符串中第一个只出现k次的字符
void Fun(char *str,int len,int k)
{
	assert(str != NULL);
	int tmp[265] = {0};
	for(int i = 0; i < len-1;i++)
	{
		if(tmp[str[i]] == k)
		{
			printf("第一个出现%d次的字符为:%c\n",k,str[i]);
			break;
		}
		tmp[str[i]]++;
	}
}

int main()
{
	char str[] = "hajddiieddonucasudwdpuwnceepen";
	int len = sizeof(str)/sizeof(str[0]);
	Fun(str,len,3);
	return 0;
}