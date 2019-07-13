//53.���м��㷨
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<vld.h>//�����Ƿ����ڴ�й©

/*
Need                 �������
Allocation          �������
Request             �������(ʵ��ֻ��Ҫ��������,Ϊ�˷���ʹ��д���˾���)
Available           ��������Դ����
progress            ������
resource            ��Դ��
 */

int **OpenSpace2(int **arr,int progress,int resource)  //��̬���ٶ�ά����
{
	arr = (int **)malloc(sizeof(int *)*progress);         
	assert(arr != NULL);
	for(int i = 0; i< progress ; i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*resource);
	}
	assert(arr != NULL);
	return arr;
}

void Show(int **Need,int **Allocation,int **Request ,int * Available,int progress,int resource)
{
	assert(Need != NULL && Allocation != NULL);
	printf("�������:\t\t�������:\t\t�������:\n");
	for(int i = 0; i < progress;i++)		
	{
		for(int j  = 0 ;j< resource; j++)
		{
			printf("%d ",Need[i][j]);
		}
		printf("\t\t\t");
		for(int j  = 0 ;j< resource; j++)
		{
			printf("%d ",Allocation[i][j]);
		}
		printf("\t\t\t");
		for(int j  = 0 ;j< resource; j++)
		{
			printf("%d ",Request[i][j]);
		}
		printf("\n");
	}
	printf("��������Դ����:\n");
	for(int i = 0; i < resource;i++)
	{
		printf("%d ",Available[i]);
	}
	printf("\n");
}

void Init(int **Need,int **Allocation,int **Request,int * Available,int progress,int resource)//��ʼ��
{
	assert(Need != NULL && Allocation != NULL);
	srand((unsigned)time( NULL ) );  	
	for(int i = 0; i < progress;i++)		
	{
		for(int j  = 0 ;j< resource; j++)
		{  
			Need[i][j] = rand()%8+0;
			Allocation[i][j] = rand()%7+0;
			Request[i][j] = 0;
		}
	}
	for(int i = 0; i < resource;i++)
	{
		Available[i] = rand()%10+0;
	}
}


bool Safe(int **Need,int **Allocation,int **Request,int * Available,int progress,int resource,int *arr)
{
	assert(Need != NULL && Allocation != NULL && Available != NULL);
	int k = 0;      //arr���±�
	int *Work = (int *)malloc(sizeof(int)*resource);
	assert(Work != NULL);
	for(int i = 0; i< resource;i++)
	{
		Work[i] = Available[i];
	}
	bool *finish =(bool*)malloc(sizeof(bool)*progress);
	assert(finish != NULL);
	for(int i = 0; i< progress;i++)
	{
		finish[i] = false;
	}
	//Show(Need,Allocation,Request,Available,progress,resource);
	for(int i = 0;i < progress; i++)
	{
		if(!finish[i])
		{
			int j;
			for( j = 0; j < resource;j++)
			{
				if(Need[i][j] > Work[j])  
				{
					break;    //�ж���һ�������Ƿ�ȫ
				}
				if(j+1 == resource) //��Need��[i]����,���е�ֵ��С��Work������ֵ     jΪ�±�,resourceΪ��Դ��
				{
					finish[i] = true;
					arr[k++] = i;
					for(j = 0;j < resource;j++)
					{
						Work[j] += Allocation[i][j];
					}
					i = -1;   //���¿�ʼɨ��
				}
			}
		}
	}
	for(int i = 0; i < progress; i++)
	{
		if(!finish[i])
		{
			free(Work);
			free(finish);
			printf("��ʱ���ڲ���ȫ��״̬\n");
			return false;
		}
	}
	free(Work);
	free(finish);
	printf("��ʱ���ڰ�ȫ��״̬\n");
	return true;
}

bool Bank(int **Need,int **Allocation,int **Request,int * Available,int progress,int resource,int *arr)
{
	assert(Need != NULL && Allocation != NULL && Request != NULL);
	//bool *finish =(bool*)malloc(sizeof(bool)*progress);
	bool flag = false;
	//assert(finish != NULL);
	int k;
	printf("�����������������̺�(��0��ʼ):");
	int test = scanf("%d",&k);
	while(test == 0 || k >=progress || k < 0 )//�����쳣����
	{
		printf("��������,������!\n");
		fflush(stdin);    //�������
		printf("�����������������̺�(��0��ʼ):");  
		test = scanf("%d",&k);
	}
	printf("��������������(�س��ָ�):\n");
	for(int i = 0; i < resource ;i++)
	{
		int test1 = scanf("%d",&Request[k][i]); 
		if(test1 == 0)   //�����쳣����
		{
			fflush(stdin);    //�������
			printf("��������,����������!\n");
			i--;
		}
		if(Request[k][i] > Need[k][i] )
		{
			printf("��������,����������!\n");
			i--;
		}
	}
	int j = 0;	
	for( j = 0; j < resource;j++)
	{
		if(Request[k][j] > Available[j])
		{
			printf("�����㹻��Դ,P%d��ȴ�\n",k);
			return false;
		}
		flag = true;	
	}
	if(flag)
	{
		for( j = 0;j < resource;j++)
		{
			Available[j] -=Request[k][j];
			Allocation[k][j] += Request[k][j];
			Need[k][j] -= Request[k][j];
		}
		if(!Safe(Need,Allocation,Request,Available,progress,resource,arr))//�������ȫ
		{
			flag = false;
			for( j = 0; j < resource;j++)//�ָ���Դ
			{
				Available[j] +=Request[k][j];
				Allocation[k][j] -= Request[k][j];
				Need[k][j] += Request[k][j];	
			}	
		}
	}
	
	if(flag == false)
	{		
		printf("ϵͳ���ڲ���ȫ״̬\n");
		return false;
	}
	else
	{	
		printf("ϵͳ���ڰ�ȫ״̬\n");
		return true;
	}
}

void Delete(int **Need,int **Allocation,int **Request,int * Available,int progress,int *arr)//�ͷ��ڴ溯��
{
	for(int i = 0; i< progress ; i++)//�ڴ��ͷ�
	{
		free(Need[i]);
		free(Allocation[i]);
		free(Request[i]);
	}
	free(Need);
	free(Allocation);
	free(Request);
	free(Available);
	free(arr);
}


int  main()
{
	int progress ;
	int resource;
	bool flag = false;  //����жϰ�ȫ���еı�־
	bool flag1  = false;
	printf("��������̸���:");   
	int test = scanf("%d",&progress);   //����
	while(test == 0)//�����쳣����
	{
		printf("��������,������!\n");
		fflush(stdin);    //�������
		printf("��������̸���:");  
		test = scanf("%d",&progress);
	}
	printf("��������Դ����:");
	int test1 = scanf("%d",&resource);   //����
	while(test1 == 0)//�����쳣����
	{
		printf("��������,������!\n");
		fflush(stdin);    //�������
		printf("��������Դ����:");  
		test1 = scanf("%d",&resource);
	}

	int **Need = NULL;
	int **Allocation = NULL;
	int **Request = NULL;
	Need = OpenSpace2(Need,progress,resource);
	Allocation = OpenSpace2(Allocation,progress,resource);
	Request = OpenSpace2(Request,progress,resource);
	

	int *Available = (int *)malloc(sizeof(int)*resource);
	assert(Available != NULL);
	int *arr = (int*)calloc(progress,sizeof(int));         //���氲ȫ����
	assert(arr != NULL);

	Init(Need,Allocation,Request,Available,progress,resource);
	Show(Need,Allocation,Request,Available,progress,resource);
	flag1 = Safe(Need,Allocation,Request,Available,progress,resource,arr);
	if(!flag1)
	{
		Delete(Need,Allocation,Request,Available,progress,arr);
		return 0;
	}
	flag = Bank(Need,Allocation,Request,Available,progress,resource,arr);

	if(flag)
	{
		printf("��ȫ����Ϊ:\n");
		for(int i =0; i< progress;i++)
		{
			printf("P%d ",arr[i]);
		}
		printf("\n");
	}

	//Show(Need,Allocation,Request,Available,progress,resource);
	Delete(Need,Allocation,Request,Available,progress,arr);
	return 0;
}
