#include<stdio.h>
#include<assert.h>


/*
(1) va_list��   ����һ��va_list�͵ı���ap��Ҳ����char *��
(2) va_start����ȡ���ɱ��������׵�ַ�������õ�ַ����ָ��ap��
(3) va_arg��  ��ȡ��ǰap��ָ��Ŀɱ����������ָ��apָ����һ���ɱ������ע�⣬�ú�ĵڶ�������Ϊ���ͣ�
(4) va_end�� �����ɱ�����Ļ�ȡ��
*/

//43.�ɱ�������,���.int sum(int count,..)
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
