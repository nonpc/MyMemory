#include<stdio.h>
#include<assert.h>


//23.括号匹配.({()})  “({)” 或者 “([{})]” 都不符合要求
int Job2(char *arr)
{
	int j=0;
	int i=0;
	char temp1[40];
	while(arr[i]!='\0')
	{
		if(arr[i]=='('||arr[i]=='{'||arr[i]=='[')//只要是左括号就写入
		{
			temp1[j]=arr[i];
			j++;
			i++;
			continue;
		}
		//第一次出现右括号，与他相邻的必然是他的左括号
		if(arr[i]==')')
		{
			j--;
			if(temp1[j]=='(')
			{
				i++;
			}
			else
			{
				return -1;
			}
		}
		if(arr[i]=='}')
		{
			j--;
			if(temp1[j]=='{')
			{
				i++;
			}
			else
			{
				return -1;
			}
		}
		if(arr[i]==']')
		{
			j--;
			if(temp1[j]=='[')
			{
				i++;
			}
			else
			{
				return -1;
			}
		}
	}
	return 1;
}


int main()
{
	char arr[]="{([()])()";
	if(Job2(arr)==1)
	{
		printf("ok\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}