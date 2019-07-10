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