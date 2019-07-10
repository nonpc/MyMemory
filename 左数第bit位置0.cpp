#include<stdio.h>
#include<assert.h>


//28.×óÊıµÚ bit Î»ÖÃ 0
void Job1(int num,int bit)
{
	int n=  pow((double)2,(32-bit));//   num ^ 2(32-k)
	num = num ^ n;
	printf("%d\n",num);
}
int main()
{
	Job1(5,30);

	return 0;
}
