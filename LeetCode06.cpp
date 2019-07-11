#include<stdio.h>
#include<assert.h>


//47.LeetCode06:��һ���������ַ������ݸ����������Դ������£������ҽ���Z�������С�
//1.��һ���������ַ������ݸ����������Դ������£������ҽ���Z�������С�
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

/*
����һ:��̬���ٶ�ά����
*/
void Job(char *arr,int row)//                row��    col��
{
	assert(arr != NULL);
	if(row == 1)
	{
		printf("%s\n",arr);
		return ;
	}
	int col = strlen(arr)/(2*row-2)*(row-1);//�������
	int len = strlen(arr) ;
	char **brr;
	brr = (char **)calloc(row,sizeof(char *));//���к���    ����¥�㣬����¥�ƺ�
	for(int i = 0;i < row;i++)
	{
		brr[i] = (char *)calloc(col,sizeof(char));
	}
	int i = 0;
	int j =0;
	int r =0;//��¼����
	int k =0;//��¼arr�ĳ���
	while(k < len)
	{
		i = 0;
		r = 0;
		while(r <row && k < len)//������һ��
		{
			brr[i][j] = arr[k];
			k++;
			i++;
			r++;
		}
		j++;//������һ��
		i = row-2;//��һ�г�ʼ��
		for(int z = row-2;z > 0;z--,i--,k++,j++)//�Ų�����һ��     ��(row-2)��
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
	for(i = 0;i < row;i++)//�ͷţ����ͷ�һά
	{
		brr[i];
	}
	free(brr);//���ͷŶ�ά
}

//������:������ѧ��ϵ���б任
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
	/char arr[] = "LEETCODEISHIRING";//����һ
	//����һ
	int row = 3;
	Job(arr,row);
	//���Զ�
	int row1 = 4;
	Job(arr,row1);
	//������
	int row2 = 1;
	Job(arr,row2);

	char s[] ="LEETCODEISHIRING";//������
	//����һ
	char *brr = NULL;
	int numRows = 3;
	brr = Convert(s,numRows);
	printf("%s\n",brr);
	free(brr);
	//���Զ�
	char *brr1 = NULL;
	int numRows1 = 4;
	brr = Convert(s,numRows1);
	printf("%s\n",brr);
	free(brr1);
	//������
	char *brr2 = NULL;
	int numRows2 = 1;
	brr = Convert(s,numRows2);
	printf("%s\n",brr);
	free(brr2);
	
	return 0;
}