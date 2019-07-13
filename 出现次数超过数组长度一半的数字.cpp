//26.出现次数超过数组长度一半的数字，如：{1,2,3,2,2,2,5,4,2} 
/*
方法一：
思路：一个数字出现的次数超过数组的一半长度，根据一次划分函数，在数组的中位数上一定是这个数。
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
	Swap(arr,low,rand()%(high-low)+low);//随机生成 基准

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

	int key = Job1(arr,0,len-1,len);//方法一
	printf("%d\n",key);

	return 0;
}

/*
方法二：(一个多于一半数组的数，出现次数比其他数的总和还要多)
思路：在遍历数组的过程中，保存两个值，一个是数组中数字，一个是出现次数。
当遍历到下一个数字时，如果这个数字跟之前保存的数字相同，则次数加1，如果不同，则次数减1。
如果次数为0，则保存下一个数字并把次数设置为1。
*/

int Job3(int *arr,int len)
{
	int sum = 0;
	int top = 1;
	int *brr = (int *)malloc(sizeof(int)*2);
	brr[top] = arr[0];//brr的初始化
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

	int key = Job3(arr,len);//方法二
	printf("%d\n",key);

	return 0;
}
