//26.���ִ����������鳤��һ������֣��磺{1,2,3,2,2,2,5,4,2} 
/*
����һ��
˼·��һ�����ֳ��ֵĴ������������һ�볤�ȣ�����һ�λ��ֺ��������������λ����һ�����������
*/
void Swap(int *arr,int low,int high)
{
	int tmp = arr[low];
	arr[low] = arr[high];
	arr[high] = tmp;
}
int Job1(int *arr,int low,int high,int len)
{
	srand((unsigned int)time(NULL));
	Swap(arr,low,rand()%(high-low)+low);//������� ��׼

	int tmp = arr[low];
	while(low < high)
	{
		while(low < high &&  arr[high] >= tmp)
		{
			high--;
		}
		if(high < low)
		{
			break;
		}
		else
		{
			arr[low] =arr[high];
		}
		while(low < high && arr[low] <= tmp)
		{
			low++;
		}
		if(low > high )
		{
			break;
		}
		else
		{
			arr[high] = arr[low];
		}
	}
	arr[low] = tmp;
	return arr[(len)/2];
}


int main()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);

	int key = Job1(arr,0,len-1,len);//����һ
	printf("%d\n",key);

	return 0;
}

/*
��������(һ������һ��������������ִ��������������ܺͻ�Ҫ��)
˼·���ڱ�������Ĺ����У���������ֵ��һ�������������֣�һ���ǳ��ִ�����
����������һ������ʱ�����������ָ�֮ǰ�����������ͬ���������1�������ͬ���������1��
�������Ϊ0���򱣴���һ�����ֲ��Ѵ�������Ϊ1��
*/

int Job3(int *arr,int len)
{
	int sum = 0;
	int top = 1;
	int *brr = (int *)malloc(sizeof(int)*2);
	brr[top] = arr[0];//brr�ĳ�ʼ��
	brr[sum] = 1;
	for(int i =1;i < len;i++)
	{
		if(brr[top] != arr[i])
		{
			brr[sum]--;
		}
		else
		{
			brr[sum]++;
		}
		if(brr[sum] == 0)
		{
			brr[top] = arr[i];
			brr[sum] = 1;
		}
	}
	return brr[top];
}


int main()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);

	int key = Job3(arr,len);//������
	printf("%d\n",key);

	return 0;
}
