#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


//54.����ʵ��������ַ���(ȫΪСдӢ����ĸ)����С���(google)
/*
��"abc"����С���Ϊ"abd","dhz"����С���Ϊ"diz"��
Ҳ���ǴӺ���ǰ����c����һ�����Ծ���abd    ��dhz��zû����һ����ĸ��
�ǾͿ�h����һ����������h����һ��Ϊi,����"dhz"����С���Ϊ"diz"��
*/
void Fun(char *str,int len)
{
	assert(str != NULL);
	int i = len-2 ;
	while(str[i] >= 122)
	{
		i--;	
	}	
	str[i] = (char)(str[i]+1);
}

int main()
{
	char str[] = "abc";
	char str1[] = "diz";
	int len = sizeof(str)/sizeof(str[0]);
	int len1 = sizeof(str1)/sizeof(str1[0]);
	Fun(str,len);
	printf("%s\n",str);
	printf("==============\n");
	Fun(str1,len1);
	printf("%s\n",str1);
	return 0;
}