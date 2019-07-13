//53.银行家算法
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<vld.h>//测试是否含有内存泄漏

/*
Need                 需求矩阵
Allocation          分配矩阵
Request             请求矩阵(实际只需要需求向量,为了方便使用写成了矩阵)
Available           可利用资源向量
progress            进程数
resource            资源数
 */

int **OpenSpace2(int **arr,int progress,int resource)  //动态开辟二维数组
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
	printf("需求矩阵:\t\t分配矩阵:\t\t请求矩阵:\n");
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
	printf("可利用资源向量:\n");
	for(int i = 0; i < resource;i++)
	{
		printf("%d ",Available[i]);
	}
	printf("\n");
}

void Init(int **Need,int **Allocation,int **Request,int * Available,int progress,int resource)//初始化
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
	int k = 0;      //arr的下标
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
					break;    //判断下一个进程是否安全
				}
				if(j+1 == resource) //即Need中[i]向量,所有的值都小于Work向量的值     j为下标,resource为资源数
				{
					finish[i] = true;
					arr[k++] = i;
					for(j = 0;j < resource;j++)
					{
						Work[j] += Allocation[i][j];
					}
					i = -1;   //重新开始扫描
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
			printf("此时处于不安全的状态\n");
			return false;
		}
	}
	free(Work);
	free(finish);
	printf("此时处于安全的状态\n");
	return true;
}

bool Bank(int **Need,int **Allocation,int **Request,int * Available,int progress,int resource,int *arr)
{
	assert(Need != NULL && Allocation != NULL && Request != NULL);
	//bool *finish =(bool*)malloc(sizeof(bool)*progress);
	bool flag = false;
	//assert(finish != NULL);
	int k;
	printf("请输入请求向量进程号(从0开始):");
	int test = scanf("%d",&k);
	while(test == 0 || k >=progress || k < 0 )//输入异常机制
	{
		printf("输入有误,请重试!\n");
		fflush(stdin);    //清除缓存
		printf("请输入请求向量进程号(从0开始):");  
		test = scanf("%d",&k);
	}
	printf("请输入请求向量(回车分隔):\n");
	for(int i = 0; i < resource ;i++)
	{
		int test1 = scanf("%d",&Request[k][i]); 
		if(test1 == 0)   //输入异常机制
		{
			fflush(stdin);    //清除缓存
			printf("输入有误,请重新输入!\n");
			i--;
		}
		if(Request[k][i] > Need[k][i] )
		{
			printf("输入有误,请重新输入!\n");
			i--;
		}
	}
	int j = 0;	
	for( j = 0; j < resource;j++)
	{
		if(Request[k][j] > Available[j])
		{
			printf("尚无足够资源,P%d需等待\n",k);
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
		if(!Safe(Need,Allocation,Request,Available,progress,resource,arr))//如果不安全
		{
			flag = false;
			for( j = 0; j < resource;j++)//恢复资源
			{
				Available[j] +=Request[k][j];
				Allocation[k][j] -= Request[k][j];
				Need[k][j] += Request[k][j];	
			}	
		}
	}
	
	if(flag == false)
	{		
		printf("系统处于不安全状态\n");
		return false;
	}
	else
	{	
		printf("系统处于安全状态\n");
		return true;
	}
}

void Delete(int **Need,int **Allocation,int **Request,int * Available,int progress,int *arr)//释放内存函数
{
	for(int i = 0; i< progress ; i++)//内存释放
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
	bool flag = false;  //最后判断安全序列的标志
	bool flag1  = false;
	printf("请输入进程个数:");   
	int test = scanf("%d",&progress);   //行数
	while(test == 0)//输入异常机制
	{
		printf("输入有误,请重试!\n");
		fflush(stdin);    //清除缓存
		printf("请输入进程个数:");  
		test = scanf("%d",&progress);
	}
	printf("请输入资源个数:");
	int test1 = scanf("%d",&resource);   //列数
	while(test1 == 0)//输入异常机制
	{
		printf("输入有误,请重试!\n");
		fflush(stdin);    //清除缓存
		printf("请输入资源个数:");  
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
	int *arr = (int*)calloc(progress,sizeof(int));         //保存安全序列
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
		printf("安全序列为:\n");
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
