#include<stdio.h>
#include<assert.h>


//31.从一个字符串中除去多于的空格
void Deblank(char *string)
{
	assert(*string != NULL);
	char *pb = string;
	char *pe = string;
	while(*pe != '\0')
	{
		if(*pe == ' ' && *pe++ == ' ')//遇到空格判断后面是否还有空格，有pb走一步，准备覆盖     (pe++)可以修改成pe+1
		{
			pb++;
		}
		while(!isalpha(*pe))//过滤多于空格
		{
			pe++;
		}
		*pb = *pe;//覆盖
		pe++;
		pb++;
	}
	*pb = '\0';
}


int main()
{
	char arr[] = "abc         bcd                 def      dg";
	Deblank(arr);
	printf("%s\n",arr);

	return 0;
}


//另一种方法:考虑前后都有空格
void Deblank(char *string)
{
	assert(*string != NULL);
	char *pb = string;
	char *pe = string;
	while(!(isalpha(*pe)))
	{
		pe++;
		pb++;
	}
	while(*pe != '\0')
	{
		if(*pe == ' ' && *(pe+1) == ' ')//遇到空格判断后面是否还有空格，有pb走一步，准备覆盖
		{
			pb++;
		}
		while(!isalpha(*pe) )//过滤多于空格
		{
			if(*pe == '\0')//末尾有空格
			{
				*(pb-1) = '\0';
				return ;
			}
			pe++;
		}
		*pb = *pe;//覆盖
		pe++;
		pb++;
	}
	*pb = '\0';
}


int main()
{
	char arr[] = "       abc         bcd                 def      dg         ";
	Deblank(arr);
	printf("%s\n",arr);

	return 0;
}