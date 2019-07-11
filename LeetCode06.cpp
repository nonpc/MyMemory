#include<stdio.h>
#include<assert.h>


//47.LeetCode06:将一个给定的字符串根据给定的行数以从上往下，从左到右进行Z字形排列。
//1.将一个给定的字符串根据给定的行数以从上往下，从左到右进行Z字形排列。
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

/*
方法一:动态开辟二维数组
*/
void Job(char *arr,int row)//                row行    col列
{
	assert(arr != NULL);
	if(row == 1)
	{
		printf("%s\n",arr);
		return ;
	}
	int col = strlen(arr)/(2*row-2)*(row-1);//求得列数
	int len = strlen(arr) ;
	char **brr;
	brr = (char **)calloc(row,sizeof(char *));//先行后列    先有楼层，才有楼牌号
	for(int i = 0;i < row;i++)
	{
		brr[i] = (char *)calloc(col,sizeof(char));
	}
	int i = 0;
	int j =0;
	int r =0;//记录列数
	int k =0;//记录arr的长度
	while(k < len)
	{
		i = 0;
		r = 0;
		while(r <row && k < len)//放完整一列
		{
			brr[i][j] = arr[k];
			k++;
			i++;
			r++;
		}
		j++;//进入下一列
		i = row-2;//下一列初始化
		for(int z = row-2;z > 0;z--,i--,k++,j++)//放不完整一列     放(row-2)次
		{
			if(k < len)
			{
				brr[i][j] = arr[k];
			}
		}
	}
	for(i = 0;i < row;i++)
	{
		for(j = 0;j < col;j++)
		{
			printf("%c",brr[i][j]);
		}
		printf("\n");
	}
	for(i = 0;i < row;i++)//释放，先释放一维
	{
		brr[i];
	}
	free(brr);//再释放二维
}

//方法二:根据数学关系进行变换
char* Convert(char* s, int numRows) 
{
	assert(s != NULL);
	if(numRows == 1)
	{
		return s;
	}
    int len = strlen(s)+1;
	char *arr = (char*)malloc(sizeof(char)*len);
	int cycLen = 2 * numRows-2;
	int k = 0;
	for(int i = 0;i < numRows; i++)
	{
		for(int j = i; j < len-1;j += cycLen)
		{
			arr[k++] = s[j];	
			if (i != 0 && i != numRows - 1 && j + cycLen - 2*i < len-1)
			{
				arr[k++]= s[j + cycLen - 2*i];
			}
		}
	}
	arr[k] = '\0';
	return arr;
}

int main()
{
	/char arr[] = "LEETCODEISHIRING";//方法一
	//测试一
	int row = 3;
	Job(arr,row);
	//测试二
	int row1 = 4;
	Job(arr,row1);
	//测试三
	int row2 = 1;
	Job(arr,row2);

	char s[] ="LEETCODEISHIRING";//方法二
	//测试一
	char *brr = NULL;
	int numRows = 3;
	brr = Convert(s,numRows);
	printf("%s\n",brr);
	free(brr);
	//测试二
	char *brr1 = NULL;
	int numRows1 = 4;
	brr = Convert(s,numRows1);
	printf("%s\n",brr);
	free(brr1);
	//测试三
	char *brr2 = NULL;
	int numRows2 = 1;
	brr = Convert(s,numRows2);
	printf("%s\n",brr);
	free(brr2);
	
	return 0;
}