#include<iostream>

using namespace std;

/*
����˼· : 
	�����е����ֶ��� 0~n-1 , �ķ�Χ�� , ����Щд���ְ��մ�С�����˳������ ,���� i ���������±� i ��λ��
	�����������ظ������� , ͬʱ��Щλ�þ��п���û������
*/

bool duplicate(int num[] , int len , int* duplication)
{
	if(num == nullptr || len <= 0)
		return false;
	for(int i = 0; i < len ;++i)
	{
		if(num[i] < 0 || num[i] > len - 1)
			return false;
	}
	for(int i = 0 ; i < len ;++i)
	{
		while(num[i] != i)
		{
			if(num[i] == num[num[i]])
			{
				*duplication = num[i];
				return true;
			}
			//���� num[i] �� num[num[i]]
			int tmp = num[i];
			num[i] = num[tmp];
			num[tmp] = tmp;
		}
	}
	return false;
}