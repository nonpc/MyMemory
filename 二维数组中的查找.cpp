#include<stdio.h>
#include<assert.h>
using namespace std;


//68.��ά�����еĲ���
/*
����˼·:
ʹ������ԭ��,��һ����ά��������Ͻǿ�ʼ
*/
bool Fun(int *matrix,int rows,int cols,int number)
{
	assert(matrix != NULL);
	bool found = false;
	if(rows > 0 && cols >0)
	{
		int row = 0;
		int col = cols-1;
		while(row < rows && col >= 0)
		{
			if(matrix[row*cols+col] == number)
			{
				found = true;
				break;
			}
			else if(matrix[row*cols+col] > number)
			{
				col--;
			}
			else
			{
				row++;
			}
		}
	}
	return found;
}

int main()
{
	int matrix[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	if(Fun(matrix,4,4,7))
	{
		printf("It have found\n");
	}
	else
	{
		printf("It have not found\n");
	}
	return 0;
}