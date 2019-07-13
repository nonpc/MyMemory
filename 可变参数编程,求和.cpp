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
