//29.��ȡ�� bit λ��ֵ
void Job2(int num,int bit)
{
	num = num >>bit-1;//���� (32 - bit) | 1
	printf("%d\n",(num ^ 1 ? 0:1));
}


int main()
{
	Job2(5,3);

	return 0;
}
