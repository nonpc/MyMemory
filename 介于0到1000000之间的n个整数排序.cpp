//59.����0��1000000֮���n��������������ǽ�������Ҫ��ʱ�临�Ӷ�ΪO(n) 
/*
(2018������-��Ѷ������)
����˼·:��ϣ����,����һ������1000000��Ԫ�ص�����,ʹ�����ǵ��±��¼����,
�����,��Ϊtrue,���û����Ϊfalse,������һ���ϣ����,������
*/
void Fun(int *arr,int len)
{
	assert(arr != NULL);
	bool tmp[1000000] = {false};
	for(int i = 0;i < len ;i ++)
	{
		tmp[arr[i]] = true; 
	}
	printf("����������Ϊ:\n");
	for(int i = 0; i< 1000000 ;i++)
	{
		if(tmp[i] == false)
		{
			continue;
		}
		printf("%d ",i);
	}
	printf("\n");
}

int main()
{
	int arr[70] = {0};
	srand((unsigned)time(NULL));
	for(int i = 0;i < 70;i++)
	{
		arr[i] = rand()%1000+0;
	}
	int len = sizeof(arr)/sizeof(arr[0]);
	Fun(arr,len);

	return 0;
}
