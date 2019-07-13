//57.�ַ�����ֵ
/*
��һ����Ȥ���ַ�����ֵ���㷽ʽ:ͳ���ַ�����ÿ���ַ����ֵĴ���,Ȼ��������
�ַ�������ƽ������Ϊ�ַ����ļ�ֵ
��:"abacaba"�������4��'a',2��'b',1��'c',��������ַ����ļ�ֵΪ4*4+2*2+1*1=21
�����S���Ƴ����K���ַ�,��Ŀ��õ����ַ���(<=50)��ֵ��С.
*/

int Once(int* arr,int low ,int high)
{
	int tmp = arr[low];
	while(low < high)
	{
		while(low < high && arr[high] >= tmp)
		{
			high--;
		}
		if(low >= high)
		{
			break;
		}
		else
		{
			arr[low] = arr[high];
		}
		while(low < high && arr[low] < tmp)
		{
			low++;
		}
		if(low >= high)
		{
			break;
		}
		else
		{
			arr[high] = arr[low];
		}
	}
	arr[low] = tmp;
	return low;
}

void Qucik(int *arr,int low ,int high)
{
	int par = Once(arr,low,high);
	if(par > low+1)
	{
		Qucik(arr,low,par-1);
	}
	if(par < high-1)
	{
		Qucik(arr,par+1,high);
	}
}

void Show(int *arr,int len)
{
	assert(arr != NULL);
	for(int i = 0; i < len ;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Fun(char *arr,int len ,int key)
{
	assert(arr != NULL);
	int tmp[255] = {0};
	for(int i = 0 ;i < len-1; i++)
	{
		tmp[arr[i]]++;
	}
	int count = 0;
	for(int i =0 ; i < 255;i++)
	{
		if(tmp[i])
		{
			count++;
		}
	}
	int *brr = (int *)malloc(sizeof(int)*count);
	assert(brr != NULL);
	int j = 0;
	for(int i =0 ; i < 256;i++)
	{
		if(tmp[i])
		{
			brr[j++] = tmp[i];
		}
	}
	Qucik(brr,0,count-1);
	Show(brr,count);
	printf("==========================\n");
	for(int i = 0; i < key;i++)
	{
		brr[count-1]--;
		Qucik(brr,0,count-1);
	}
	Show(brr,count);
	int N = 0;
	for(int i = 0;i< count;i++)
	{
		N +=brr[i]*brr[i];
	}
	printf("��С��ֵΪ:%d\n",N);
}

int main()
{
	char arr[] = "abcabcbsafdgjfkjdafscnsdifneeifnefo";
	int len = sizeof(arr)/sizeof(arr[0]);
	int k = 2;
	Fun(arr,len,k);
	return 0;
}
