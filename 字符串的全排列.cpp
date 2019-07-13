//49.×Ö·û´®µÄÈ«ÅÅÁÐ
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

void Swap(char *str1,char *str2)
{
	char tmp ;
	tmp = *str2;
	*str2 = *str1;
	*str1 = tmp;
}

void Job(char *str,char *begin)
{
	assert(str !=NULL && begin != NULL);
	if(*begin == '\0')
	{
		printf("%s\n",str);
	}
	else
	{
		for(char *pCh = begin; *pCh != '\0'; pCh++)
		{
			Swap(&(*begin),&(*pCh) );
			Job(str,begin+1);
			Swap(&(*begin),&(*pCh) );
		}
	}
}

int main()
{
	char str[] = "abc";
	Job(str,str);


	return 0;
}
