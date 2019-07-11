#include<stdio.h>
#include<assert.h>


/*
(1) va_list：   定义一个va_list型的变量ap，也就是char *；
(2) va_start：获取到可变参数表的首地址，并将该地址赋给指针ap；
(3) va_arg：  获取当前ap所指向的可变参数，并将指针ap指向下一个可变参数。注意，该宏的第二个参数为类型；
(4) va_end： 结束可变参数的获取。
*/

void Print(int count,...)//10,20
{
	char *p =NULL;
	p = (char *)(&(count))+sizeof(count);
	int tmp = 0;
	for(int i = 0;i < count;i++)
	{
		tmp = *(int *)((p += sizeof(int))-sizeof(int));
		printf("%d\n",tmp);
	}
	p = NULL;
}


//44.可变参数编程,多种输出.void Print(const char *str,...)
void Print(const char *str,...)
{
	char* list = NULL;
	list = (char*)(&str) + sizeof(str);
	int num;
	int ch;
	char *p;
	double d;
	while(*str != '\0')
	{
		if(*str == '%')
		{
			switch(*(str+1))
			{
			case 'd':
				num = ( *(int *)((list += sizeof(int)) - sizeof(int)) );
				printf("%d",num);
				str += 2;
				break;
			case 'c':
				ch = ( *(char *)((list += sizeof(char)) - sizeof(char)) );
				putchar(ch);
				str += 2;
				(char *)list += 3;
				break;
			case 's':
				p = ( *(char **)((list += sizeof(char*)) - sizeof(char*)) );
				printf("%s",p);
				str += 2;
				break;
			case 'f':
				d =( *(double *)((list += sizeof(double)) - sizeof(double)));
				printf("%f",d);
				str += 2;
				break;
			default:
				putchar(*str++);
				break;
			}
		}
		else
		{
			putchar(*str++);
		}
	}
	list = NULL;
}


int main()
{
	Print("%%,%s,%d,%c,%f\n","hello",10,'a',12.5);

	return 0;
}