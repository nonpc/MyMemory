#include<stdio.h>
#include<assert.h>


//30.дһ������������һ���ַ�������ȡһ�����ַ���,����ֵ�Ǵ洢��dst�����е����ַ����ĳ���
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