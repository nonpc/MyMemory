/*
48.LeetCode30:给定一个字符串S和一些长度相同的单词words,在S中恰好可以找出串联words中所有单词的子串的起始位置。
子串要与words中的单词完全匹配，中间不能有其他字符，但不需要考虑words中单词串联的顺序。
如：S ="barfoothefoobarman",
words = {"foo","bar"}
输出：[0,9]
解释从索引0和9开始的子串分别是"barfoo"和"foobar"
输出的顺序不重要，[9,0]也是有效答案
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

//方法二:计算每个单词出现的位置,每个单词出现的位置+字长是否等于下一个单词出现的位置
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
	////测试一
	//char arr[][4]={"foo","bar"};//方法一
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
	////测试二
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
	////测试三
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

	char s[] = "barfoothefoobarman";//方法二
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
//方法三:计算每个单词出现的位置,从记录的位置开始使用哈希表来进行判断.
int* FindSubstring(char* s, char (*words)[SIZE], int many,int size, int* returnSize) 
{
	assert(s != NULL && words != NULL );
	int len = strlen(s);
	int k = 0;//临时存放单词出现位置的数组下标
	int l = 0;//要返回数组的下表值
	int tmmp[20] = {0};//临时存放单词出现位置的数组
	char brr[127] = {0}; //哈希表,存放单词出现的次数
	

	for(int i = 0;i < many;i++)
	{
		for(int j = 0;j < size;j++)
		{
			brr[words[i][j]]++;
		}
	}

	for(int i = 0; i < many; i++)//比对字符串,记录单词出现的首地址
	{
		for(int j = 0 ; j < len-size ; j++)
		{
			char tmp[SIZE];//临时存放单词的数组
			strncpy(tmp,&s[j],SIZE-1);
			tmp[SIZE-1] = '\0';
			if(!strcmp(tmp,words[i]))
			{
				tmmp[k++] = j;
			}
		}
	}
	
	int *arr = (int *)calloc(k,sizeof(int));

	for(int i =0;i < k;i++)//根据单词出现的位置,使用哈希表进行比对
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
			arr[l++] = tmmp[i];//比对成功,将单词出现的位置存入
		}
	}
	*returnSize = l;//返回满足条件的位置个数
	return arr;
}


int main()
{
	//测试用例一
	//char s[] = "barfoothefoobarman";
	//测试用例二
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
