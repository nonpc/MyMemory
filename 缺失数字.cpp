//62.ȱʧ����
/*
����һ������0,1,2,...n ��n����������,�г�0...n��û�г���������
�е��Ǹ���

����˼·:ʹ�ù�ϣ��,��¼���е�,���û�е� 
*/
void Fun(int *arr,int len)
{
	assert(arr != NULL);
	bool tmp[100] = {false};
	for(int i = 0; i < len;i++)
	{
		tmp[arr[i]] = true;
	}
	printf("ȱʧ����Ϊ:\n");
	for(int i = 0; i< 100 ;i++)
	{
		if(tmp[i] == false)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
}

int main()
{
	int arr[] = {1,5,4,6,2,7,8,9,48,45,31,16,13};
	int len = sizeof(arr)/sizeof(arr[0]);
	Fun(arr,len);
	
	return 0;
}
