/*
48.LeetCode30:����һ���ַ���S��һЩ������ͬ�ĵ���words,��S��ǡ�ÿ����ҳ�����words�����е��ʵ��Ӵ�����ʼλ�á�
�Ӵ�Ҫ��words�еĵ�����ȫƥ�䣬�м䲻���������ַ���������Ҫ����words�е��ʴ�����˳��
�磺S ="barfoothefoobarman",
words = {"foo","bar"}
�����[0,9]
���ʹ�����0��9��ʼ���Ӵ��ֱ���"barfoo"��"foobar"
�����˳����Ҫ��[9,0]Ҳ����Ч��
*/

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 4


#if 0
int* FindSubstring(char* s, char  (*words)[4],int many, int len, int* brr)
{
	assert(s != NULL && words != NULL && brr != NULL);
	unsigned char arr[255] = {0}; 
	int len1 = strlen(s);
	int k = 0;
	for(int i = 0;i < many;i++)
	{
		for(int j = 0;j < len;j++)
		{
			arr[words[i][j]]++;
		}
	}
	for(int i = 0;i < len1-many*len;i++)
	{
		unsigned char tmp[255] = {0};
		int j ;
		for(j = i; j < i+many*len;j++)
		{
			if(arr[s[j]])
			{
				tmp[s[j]]++;
				if(arr[s[j]] < tmp[s[j]])
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		j = j-i;
		if(j == many*len)
		{
			brr[k] = i;
			k++;
			//i = i+many*len;
		}
	}
	return brr;
}
#endif

//������:����ÿ�����ʳ��ֵ�λ��,ÿ�����ʳ��ֵ�λ��+�ֳ��Ƿ������һ�����ʳ��ֵ�λ��
int* FindSubstring(char* s, char (*words)[SIZE], int many,int size, int* returnSize) 
{
	assert(s != NULL && words != NULL );
	int len = strlen(s);
	int k = 0;
	int l = 0;
	int tmmp[20] = {0};
	for(int i = 0; i < many; i++)
	{
		for(int j = 0 ; j < len-size ; j++)
		{
			char tmp[SIZE];
			strncpy(tmp,&s[j],SIZE-1);
			tmp[SIZE-1] = '\0';
			if(!strcmp(tmp,words[i]))
			{
				tmmp[k++] = j;
			}
		}
	}
	int *arr = (int *)malloc(sizeof(int)*k);
	for (int i = 0; i < k;i++)
	{
		for(int j = 0 ; j < k ;j++)
		{
			if(i == j)
			{
				continue;
			}
			if((tmmp[i] +size) == tmmp[j] )
			{
				arr[l++] = tmmp[i];
			}
		}
	}
	*returnSize = l;
	return arr;
}



int main()
{
	////����һ
	//char arr[][4]={"foo","bar"};//����һ
	//char s[] = "barfoothefoobarman";
	//int *drr = (int *)calloc(2,sizeof(int));
	//drr = FindSubstring(s,arr,2,3,drr);
	//for(int i =0;i<2;i++)
	//{
	//	if(drr[i] == 0 && i != 0)
	//	{
	//		continue;
	//	}
	//	printf("%d\n",drr[i]);
	//}
	////���Զ�
	//char arr1[][4]={"ood","stu"};
	//char s1[] = "goodgoodstudydaydayup";
	//int *drr1 = (int *)calloc(2,sizeof(int));
	//drr1 = FindSubstring(s1,arr1,2,3,drr1);
	//for(int i =0;i<2;i++)
	//{
	//	if(drr1[i] == 0 && i != 0)
	//	{
	//		continue;
	//	}
	//	printf("%d\n",drr1[i]);
	//}
	////������
	//char arr2[][4]={"foo","bar"};
	//char s2[] = "bofarothefoobarman";
	//int *drr2 = (int *)calloc(2,sizeof(int));
	//drr2 = FindSubstring(s2,arr2,2,3,drr2);
	//for(int i =0;i<2;i++)
	//{
	//	if(drr2[i] == 0 && i != 0)
	//	{
	//		continue;
	//	}
	//	printf("%d\n",drr2[i]);
	//}

	char s[] = "barfoothefoobarman";//������
	char words[][SIZE] = {"foo","bar"};
	int *arr = NULL;
	int returnSize ;
	arr = FindSubstring(s,words,2,3,&returnSize);
	for(int i = 0; i < returnSize; i++)
	{
		printf("%d\n",arr[i]);
	}
	free(arr);

	return 0;
}


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 4
//������:����ÿ�����ʳ��ֵ�λ��,�Ӽ�¼��λ�ÿ�ʼʹ�ù�ϣ���������ж�.
int* FindSubstring(char* s, char (*words)[SIZE], int many,int size, int* returnSize) 
{
	assert(s != NULL && words != NULL );
	int len = strlen(s);
	int k = 0;//��ʱ��ŵ��ʳ���λ�õ������±�
	int l = 0;//Ҫ����������±�ֵ
	int tmmp[20] = {0};//��ʱ��ŵ��ʳ���λ�õ�����
	char brr[127] = {0}; //��ϣ��,��ŵ��ʳ��ֵĴ���
	

	for(int i = 0;i < many;i++)
	{
		for(int j = 0;j < size;j++)
		{
			brr[words[i][j]]++;
		}
	}

	for(int i = 0; i < many; i++)//�ȶ��ַ���,��¼���ʳ��ֵ��׵�ַ
	{
		for(int j = 0 ; j < len-size ; j++)
		{
			char tmp[SIZE];//��ʱ��ŵ��ʵ�����
			strncpy(tmp,&s[j],SIZE-1);
			tmp[SIZE-1] = '\0';
			if(!strcmp(tmp,words[i]))
			{
				tmmp[k++] = j;
			}
		}
	}
	
	int *arr = (int *)calloc(k,sizeof(int));

	for(int i =0;i < k;i++)//���ݵ��ʳ��ֵ�λ��,ʹ�ù�ϣ����бȶ�
	{
		char tmp1[127] = {0};
		int j ;
		for(j = tmmp[i]; j < tmmp[i]+many*size;j++)
		{
			if(brr[s[j]])
			{
				tmp1[s[j]]++;
				if(brr[s[j]] < tmp1[s[j]])
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		j = j-tmmp[i];
		if(j == many*size)
		{
			arr[l++] = tmmp[i];//�ȶԳɹ�,�����ʳ��ֵ�λ�ô���
		}
	}
	*returnSize = l;//��������������λ�ø���
	return arr;
}


int main()
{
	//��������һ
	//char s[] = "barfoothefoobarman";
	//����������
	char s[] = "barfoofoothebrofoafoobarman";
	char words[][SIZE] = {"foo","bar"};
	int *arr = NULL;
	int returnSize ;
	arr = FindSubstring(s,words,2,3,&returnSize);
	for(int i = 0; i < returnSize; i++)
	{
		printf("%d\n",arr[i]);
	}
	free(arr);
	arr=NULL;
	return 0;
}
