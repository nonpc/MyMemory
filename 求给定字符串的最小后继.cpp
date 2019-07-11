#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


//54.编码实现求给定字符串(全为小写英文字母)的最小后继(google)
/*
如"abc"的最小后继为"abd","dhz"的最小后继为"diz"。
也就是从后往前看，c有下一个所以就是abd    而dhz中z没有下一个字母，
那就看h的下一个，最后就是h的下一个为i,所以"dhz"的最小后继为"diz"。
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