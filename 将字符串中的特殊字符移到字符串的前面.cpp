#include<stdio.h>
#include<assert.h>


//42.���ַ����е��ַ�'*'�Ƶ��ַ�����ǰ�� ��:"tu**lu**n**ba**by",�����Ϊ:"********tulunbaby"
char* Job2(char * arr,char *brr,int len)
{
	assert(arr != NULL);
	int j = 0;
	for(int i = 0;i < len;i++)
	{
		if(arr[i] == '*')
		{
			brr[j] = arr[i];
			j++;
		}
		else
		{
			continue;
		}
	}
	for(int i = 0;i < len ;i++)
	{
		if(isalpha(arr[i]))
		{
			brr[j] = arr[i];
			j++;
		}
	}
	brr[j] = '\0';
	return brr;
}

int main()
{
	char arr[] = "tu**lu**n**ba**by";
	int len = sizeof(arr)/sizeof(arr[0]);
	char *brr = (char *)malloc(sizeof(char)*len);
	Job2(arr,brr,len);
	printf("%s\n",brr);

	return 0;
}