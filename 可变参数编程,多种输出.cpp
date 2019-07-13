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
