//55.����һ���ַ����е�һ��ֻ����k�ε��ַ�
void Fun(char *str,int len,int k)
{
	assert(str != NULL);
	int tmp[265] = {0};
	for(int i = 0; i < len-1;i++)
	{
		if(tmp[str[i]] == k)
		{
			printf("��һ������%d�ε��ַ�Ϊ:%c\n",k,str[i]);
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