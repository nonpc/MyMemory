#include<stdio.h>
#include<assert.h>

//21.ɸѡ����100���ڵ���������
void Job1()
{
	int arr[101]={0};
	for(int i=0;i<100;i++)
	{
		arr[i]=i+1;
	}
	for(int j=3;j<100;j++)//�ӵ�����Ԫ�أ���4��ʼ
	{
		for(int i=2;i<j;i++)
		{
			if(arr[j]%i==0)//������ֵΪ0
			{
				arr[j]=0;
			}
		}
	}
	printf("100���ڵ������У�\n");
	for(int i=0;i<100;i++)
	{
		if(arr[i]==0)//Ԫ��Ϊ0������
		{
			continue;
		}
		printf("%d,",arr[i]);
	}
	printf("\n");
}
int main()
{
	Job1();
	return 0;
}
