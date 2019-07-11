#include<stdio.h>
#include<assert.h>


//40.等弇撻淝3論
void Identity_matrix(int (*p)[3] ,int row,int col)
{
	for(int i =0;i < row;i++)
	{
		for(int j =0;j < col;j++)
		{
			if(i == j)
			{
				p[i][j] = 1;
			}
			else
			{
				p[i][j] = 0;
			}
		}
	}
	for(int i = 0;i < row; i++)
	{
		for(int j = 0;j < col;j++)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int p[3][3];
	Identity_matrix(p,3,3);
	
	return 0;
}


//等弇撻淝1論
void Identity_matrix(int *p ,int row,int col)
{
	assert(p != NULL);
	p[0] = 1;
	printf("%d\n",p[0]);
}
int main()
{
	int q[1][1];
	Identity_matrix(p,1,1);

	return 0;
}
