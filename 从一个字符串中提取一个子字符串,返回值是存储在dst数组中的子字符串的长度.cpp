#include<stdio.h>
#include<assert.h>


//30.写一个函数，它从一个字符串中提取一个子字符串,返回值是存储在dst数组中的子字符串的长度
int SubStr(char *dst,char *src,int start,int len)
{
	int count = 0;
	int j ;
	int i ;
	assert(*src != NULL);
	for( i= start,j = 0; i < len ;i++,j++)
	{
		dst[j] = src[i];
		count++;
	}
	dst[j] = '\0';
	return count;
}

int main()
{
	char arr[] = "abcdef";
	char brr[20] ;
	int len = sizeof(arr)/sizeof(arr[0]);
	int start = 2;
	int len1 = SubStr(brr,arr,start-1,len);
	printf("%d %s\n",len1,brr);

	return 0;
}