#include<stdio.h>
#include<assert.h>


//46.дһ����������boolֵ�����жϸ������ַ���A��B�����趼��Сд��ĸ�����Ƿ���B�е��ַ���������A�У�����Ƿ���true�����򷵻�false
bool CheckString(const char *A,const char *B)
{
	bool crr[127] = {false};//bool crr[127] = {true};ֻ�е�һ����true���������false�������ʼ��Ϊfalse������Ķ���false
	while(*A != '\0')
	{
		crr[*A] = true;
		A++;
	}
	while(*B != '\0')
	{
		if(!crr[*B])
		{
			return false;
		}
		B++;
	}
	return true;

}

int main()
{
	char arr[] = "abcde";
	char brr[] = "bcd";
	printf("%d\n",CheckString(arr,brr));
	return 0;

}