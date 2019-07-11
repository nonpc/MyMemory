#include<stdio.h>
#include<assert.h>


//46.写一个函数返回bool值，来判断给定的字符串A和B（假设都是小写字母），是否是B中的字符都存在于A中，如果是返回true，否则返回false
bool CheckString(const char *A,const char *B)
{
	bool crr[127] = {false};//bool crr[127] = {true};只有第一个是true，后面的是false。如果初始化为false，后面的都是false
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