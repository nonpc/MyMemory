//45.�ǳ��淽���Ƚ��������Ĵ�С
int  Max(int a,int b)
{
	return (a - b) >>31 ? -1: (a-b ? 1 : 0);
}
int main()
{
	printf("%d\n",Max(20,30));
	return 0;
}
