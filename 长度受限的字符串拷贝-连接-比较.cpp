#include<stdio.h>
#include<assert.h>


//32.长度受限的字符串拷贝
char *My_strcnpy(char *des,const char *src,int n )
{
	assert(des!=NULL&&src!=NULL);
	assert(n>0&&n<strlen(src));
	int i ;
	for(i = 0;i < n && src[i] != '\0';i++)
	{
		des[i] = src[i];
	}
	des[i] = '\0';
	return des;
}


//33.长度受限的字符串连接函数
char *My_strncat(char *des,const char *src,int n )
{
	assert(des!=NULL&&src!=NULL);
	assert(n>0&&n<strlen(src));
	char *pb = des;
	while(*pb != '\0')
	{
		pb++;
	}
	while(*src != '\0')
	{
		*pb = *src;
		pb++;
		src++;
	}
	*pb = '\0';
	return pb;
}


//34.长度受限的字符串比较
int My_strcnmpy(const char *str1,const char *str2,int n)
{
	assert(str1 != NULL && str2 != NULL);
	assert(n>0&&n<strlen(str1)&&n<strlen(str2));
	const char *p1 = str1;
	const char *p2 = str2;
	while(*p1 != '\0' || *p2 != '\0')
	{
		if(*p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
		{
			if(*p1 > *p2)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
}