#include<stdio.h>
#include<assert.h>


//23.����ƥ��.({()})  ��({)�� ���� ��([{})]�� ��������Ҫ��
int Job2(char *arr)
{
	int j=0;
	int i=0;
	char temp1[40];
	while(arr[i]!='\0')
	{
		if(arr[i]=='('||arr[i]=='{'||arr[i]=='[')//ֻҪ�������ž�д��
		{
			temp1[j]=arr[i];
			j++;
			i++;
			continue;
		}
		//��һ�γ��������ţ��������ڵı�Ȼ������������
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