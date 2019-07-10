#include<stdio.h>
#include<assert.h>


//27.×óÊıµÚ bit Î» ÖÃ 1
void Job(int num,int bit)
{
	int n=  pow((double)2,(32-bit));    //  num | 2^(32-k)
	num = num | n;
	printf("%d\n",num);
}
int main()
{
	Job(5,31);

	return 0;
}