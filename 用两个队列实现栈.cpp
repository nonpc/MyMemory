//66.��������ʵ��ջ
/*
����˼��:��������q1��q2,�����Ϊ��(�״�ѹ��),��ѹ��q1,
���ֻ��һ��Ϊ��(����ѹ��),��Ԫ��ѹ�벻Ϊ�յ��Ǹ�����
������ʱ,Ҫ����Ԫ�ض���(����Ϊq1)��front+1 ==rear(��rear-1)��Ԫ��ѹ��ն���(����Ϊq2),
��ʱq1�л�ʣ��һ��Ԫ�غͶ�β�Ŀ�Ԫ��,Ȼ�������.����ʵ��ջ���Ƚ����

 */
//'queue.h'
#pragma once
#define SIZE 10
typedef struct Queue
{
	int elem[SIZE];
	int front;
	int rear;
}Queue,*QueueS;

void InitQueueS(QueueS queue);

bool Push(QueueS queue,int val);

bool Pop(QueueS queue,int *rtv);

void Show(QueueS queue);

int GetLength(QueueS queue);

bool IsEmpty(QueueS queue);

void Clear(QueueS queue);

void Destroy(QueueS queue);

void EnterStack(Queue *qu1,Queue *qu2,int val);

int PopStack(Queue *qu1,Queue *qu2);


//'queue.cpp'
#include"queue.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void InitQueueS(QueueS queue)//��ʼ��
{
	assert(queue != NULL);
	queue->front = 0;
	queue->rear = 0;
}

static bool IsFull(QueueS queue)
{
	assert(queue != NULL);
	return (queue->rear+1)%SIZE == queue->front;
}

bool Push(QueueS queue,int val)
{
	assert(queue != NULL);
	if(IsFull(queue))
	{
		return false;
	}
	queue->elem[queue->rear] = val;	
	queue->rear = (queue->rear+1)%SIZE;
	return true;
}

bool Pop(QueueS queue,int *rtv)
{
	assert(queue != NULL && rtv != NULL);
	if(IsEmpty(queue))
	{
		return false;
	}
	if(rtv != NULL)
	{
		*rtv = queue->elem[queue->front];
	}
	queue->front = (queue->front+1)%SIZE;
	return true;
}

void Show(QueueS queue)
{
	assert(queue != NULL);
	for(int i = queue->front ; i != queue->rear;i = (i+1)%SIZE )
	{
		printf("%d ",queue->elem[i]);
	}
	printf("\n");
}

int GetLength(QueueS queue)
{
	assert(queue != NULL);
	return (queue->rear-queue->front+SIZE)%SIZE;
}

bool IsEmpty(QueueS queue)
{
	assert(queue != NULL);
	return queue->front == queue->rear;
}

void Clear(QueueS queue)
{
	assert(queue != NULL);
	queue->front = queue->rear;
}

void Destroy(QueueS queue)
{
	assert(queue != NULL);
	Clear(queue);
}

void EnterStack(Queue *qu1,Queue *qu2,int val)
{
	assert(qu1 != NULL && qu2 != NULL);
	if(IsFull(qu1) || IsFull(qu2))
	{
		return;
	}
	if(IsEmpty(qu1) && IsEmpty(qu2))
	{
		qu1->elem[qu1->rear] = val;
		qu1->rear = (qu1->rear+1)%SIZE;
		return;
	}
	if(IsEmpty(qu1))
	{
		qu2->elem[qu2->rear] = val;
		qu2->rear = (qu2->rear+1)%SIZE;
	}
	else
	{
		qu1->elem[qu1->rear] = val;
		qu1->rear = (qu1->rear+1)%SIZE;
	}
}
int PopStack(Queue *qu1,Queue *qu2)
{
	assert(qu1 != NULL && qu2 != NULL);
	int tmp = 0;
	if(IsEmpty(qu1) && IsEmpty(qu2))
	{
		return 0;
	}
	if(!IsEmpty(qu1))//qu1��Ϊ��,��rear-1��Ԫ�ط���qu2
	{
		while((qu1->front+1)%SIZE != qu1->rear)
		{
			qu2->elem[qu2->rear] = qu1->elem[qu1->front];
			qu2->rear = (qu2->rear+1)%SIZE;
			qu1->front = (qu1->front+1)%SIZE;
		}
		tmp = qu1->elem[qu1->front];
		qu1->front = (qu1->front+1)%SIZE;
	}
	else
	{
		while((qu2->front+1)%SIZE != qu2->rear)
		{
			qu1->elem[qu1->rear] = qu2->elem[qu2->front];
			qu1->rear = (qu1->rear+1)%SIZE;
			qu2->front = (qu2->front+1)%SIZE;
		}
		tmp = qu2->elem[qu2->front];
		qu2->front = (qu2->front+1)%SIZE;
	}
	return tmp;
}


//'Դ.cpp'
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<vld.h>

/*
void EnterStack(Queue *qu1,Queue *qu2,int val)
{}
int PopStack(Queue *qu1,Queue *qu2)
{}
�Ƚ��ȳ�====>�Ƚ����
*/

int main()
{
	Queue qu1;
	Queue qu2;
	InitQueueS(&qu1);
	InitQueueS(&qu2);
	for(int i = 0;i < SIZE;i++)
	{
		EnterStack(&qu1,&qu2,i);//0-8
	}
	Show(&qu1);
	printf("================\n");
	//Show(&qu2);
	int tmp = 0;
	tmp = PopStack(&qu1,&qu2);
	printf("%d\n",tmp);//8
	tmp = PopStack(&qu1,&qu2);
	printf("%d\n",tmp);//7
	tmp = PopStack(&qu1,&qu2);
	printf("%d\n",tmp);//6
	printf("================\n");
	EnterStack(&qu1,&qu2,22);
	EnterStack(&qu1,&qu2,33);
	EnterStack(&qu1,&qu2,44);
	Show(&qu2);
	printf("================\n");
	tmp = PopStack(&qu1,&qu2);
	printf("%d\n",tmp);//44
	return 0;
}
