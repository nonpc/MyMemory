#include<stdio.h>
#include<assert.h>


/*
(1) va_list：   定义一个va_list型的变量ap，也就是char *；
(2) va_start：获取到可变参数表的首地址，并将该地址赋给指针ap；
(3) va_arg：  获取当前ap所指向的可变参数，并将指针ap指向下一个可变参数。注意，该宏的第二个参数为类型；
(4) va_end： 结束可变参数的获取。
*/

//43.可变参数编程,求和.int sum(int count,..)
int Sum(int count,...)
{
	char *p =NULL;
	p = (char *)(&(count))+sizeof(count);
	int sum = 0;
	for(int i = 0;i < count;i++)
	{
		sum += *(int *)((p += sizeof(int))-sizeof(int));
	}
	p = NULL;
	return sum;
}

int main()
{
	printf("%d\n",Sum(2,10,20));

	return 0;
}
