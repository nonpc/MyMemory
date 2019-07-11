#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
50.无重复最长子串:给定一个字符串,找出不含有重复字符的最长子串的长度.
如:"abcabcbb"   输出 :3  无重复字符的最长子串是"abc"  长度为3
*/
int Fun(char *str )
{
	assert(str != NULL);
	int count = 0;
	int max = 0;
	char *pb = str;
	char *pe = str;
	bool tmp[256] = {false};
	while(*pe != '\0')
	{
		if(!tmp[*pe])
		{
			tmp[*pe] = true;
			count++;
			pe++;
		}
		else
		{
			if(count > max)		
			{
				max = count ;		
			}
			count = 0;
			memset(tmp,false,sizeof(tmp));
			pb++;
			pe = pb;
		}
		if(count > max)		
		{
			max = count ;		
		}
	}
	return max;
}

int main()
{
	//char str[] = "abcabcbb";
	//char str[] ="pwwkew" ;
	//char str[] = " ";
	//char str[] = "dvdf";
	//char str[] = "bbbb";
	char str[] = "anviaj";
	int max = Fun(str);
	printf("%d\n",max);
	return 0;
}