//61.�ҳ��ַ��ķ���
/*
1)����˵����һ����������,����ÿһλȡ��,��֮Ϊ������ķ��롣
�������Ƕ���һ���ַ��ķ��롣�������һ��Сд�ַ���
�������ַ�'a'�ľ��������ķ�����ַ�'z'�ľ�����ͬ;�����һ����д�ַ����������ַ�'A���ģ�
���������ķ�����ַ�'Z���ľ�����ͬ;�������.�����������,���ķ������������
����A�ķ�����Z��d�ķ�����w.
һ���ַ����ķ��붨��Ϊ�������ַ��ķ��롣���ǵ�������Ǽ���������ַ����ķ��롣
2)����˼·���ַ��������������26��Ӣ����ĸ֮��ʱ��
���չ�ʽ������='Z'-( �ַ�-'A');ȥ�������ķ��뼴�ɡ��������Ӣ����ĸ�������ķ�����������
*/
void Fun(char k)//���ַ��ķ���
{
	char n = 0;
	if(k >= 'A' && k <= 'Z')
	{
		n = 'Z'-(k-'A');
		printf("�ַ�%c�ķ���Ϊ:%c\n",k,n);
		return;
	}
	if(k >= 'a' && k <= 'z')
	{
		n = 'z'-(k-'a');
		printf("�ַ�%c�ķ���Ϊ:%c\n",k,n);
		return;
	}
	printf("�ַ�%c�ķ���Ϊ:%c\n",k,k);
	return;
}
void Fun1(char *arr,int len)//���ַ����ķ���
{
	assert(arr != NULL);
	char *brr = (char *)malloc(sizeof(char)*len);
	int i = 0;
	for(int i = 0; i< len ;i++)
	{
		if(arr[i] >= 'A' && arr[i] <= 'Z')
		{
			brr[i] = 'Z'-(arr[i]-'A');
			continue;
		}
		if(arr[i] >= 'a' && arr[i] <= 'z')
		{
			brr[i] = 'z'-(arr[i]-'a');
			continue;
		}
		brr[i] = arr[i];
	}
	printf("�ַ����ķ���Ϊ:%s\n",brr);
	free(brr);
}

int main()
{
	char k = 'A';
	char k1 = 'd';
	Fun(k);
	printf("==================\n");
	Fun(k1);
	printf("==================\n");
	char arr[] = "sajdhAHKJFDHsjdhSDHjfhdf";
	int len = sizeof(arr)/sizeof(arr[0]);
	Fun1(arr,len);
	return 0;
}
