#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
50.���ظ���Ӵ�:����һ���ַ���,�ҳ��������ظ��ַ�����Ӵ��ĳ���.
��:"abcabcbb"   ��� :3  ���ظ��ַ�����Ӵ���"abc"  ����Ϊ3
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