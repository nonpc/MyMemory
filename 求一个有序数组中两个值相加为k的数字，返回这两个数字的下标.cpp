#include<stdio.h>
#include<assert.h>


//24.��һ����������������ֵ���Ϊk�����֣��������������ֵ��±ꡣ
void Job3(int *arr,int len,int key)
{
	int bgn=0;
	int end=len-1;
	for(int i=0;i<len;i++)//��������(ǰ����1��ͷ)�����Ϊk����k==��һ��Ԫ��+k��ǰһ��Ԫ��
	{
		if(arr[i]==key)
		{
			end=i-1;
			break;
		}
	}
	printf("���������ֵ��±�Ϊ��\n");
	while(arr[bgn]+arr[end]==key&&bgn<=end)
	{
		printf("%d %d\n",bgn,end);
		bgn++;
		end--;
	}
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(arr[0]);
	int key=8;
	printf("keyΪ��%d\n",key);
	Job3(arr,len,key);
	return 0;
}