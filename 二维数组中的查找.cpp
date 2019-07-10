#include<stdio.h>
#include<assert.h>
using namespace std;


//68.二维数组中的查找
/*
解题思路:
使用缩放原理,从一个二维数组的右上角开始
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