//65.两个栈实现队列
/*
解题思想:两个栈是s1和s2,压栈都往s1中压,出栈时,将s1中的元素都压入s2中,
此时s2的栈顶元素是s1中的栈底元素,s2出栈,即可实现队列的先进先出.
 */
//'stack.h'
#pragma once

#define STACK_LEN 10

typedef struct Sqstack
{
	int elem[STACK_LEN];
	int top;
}Sqstack,*Pstack;

void InitStack(Pstack ps);

bool Push(Pstack ps,int val);

bool Pop(Pstack ps,int *rtv);//删除

bool GetTop(Pstack ps,int *rtv);//得到栈顶元素， 但是不删除

bool IsEmpty(Pstack ps);

void Clear(Pstack ps);//top 指针的操作

void Destroy(Pstack ps);//这里没有动态内存分配

void Show(Pstack ps);

void EnterQue(Pstack s1,int val);

int PopQueue(Pstack s1,Pstack s2);


//'stack.cpp' 主函数包括在后面的队列实现栈
#include"stack.h"
#include<stdio.h>
#include<assert.h>

void InitStack(Pstack ps)
{
	assert(ps != NULL);
	ps->top = 0;
}

static bool IsFull(Pstack ps)
{
	assert(ps !=NULL);
	return ps->top == STACK_LEN;
}

bool Push(Pstack ps,int val)
{
	assert(ps != NULL);
	if(IsFull(ps))
	{
		return false;
	}
	ps->elem[ps->top++] = val;
	return true;
}

bool IsEmpty(Pstack ps)
{
	assert(ps != NULL);
	return ps->top == 0;
}

bool Pop(Pstack ps,int *rtv)//删除
{
	assert(ps != NULL);
	if(IsEmpty(ps))
	{
		return false;
	}
	if(rtv != NULL)
	{
		ps->top--;
		*rtv = ps->elem[ps->top];
	}
	return true;
}

bool GetTop(Pstack ps,int *rtv)//得到栈顶元素， 但是不删除
{
	assert(ps != NULL);
	if(IsEmpty(ps))
	{
		return false;
	}
	if(rtv != NULL)
	{
		*rtv = ps->elem[ps->top-1];
	}
	return true;
}

void Clear(Pstack ps)//top 指针的操作
{
	assert(ps != NULL);
	ps->top = 0;
}

void Destroy(Pstack ps)//这里没有动态内存分配
{
	assert(ps != NULL);
	Clear(ps);
}

void Show(Pstack ps)
{
	assert(ps != NULL);
	for(int i = 0;i < ps->top;i++)
	{
		printf("%d ",ps->elem[i]);
	}
	printf("\n");
}

void EnterQue(Pstack s1,int val)
{
	assert(s1 != NULL);
	if(IsFull(s1))
	{
		return ;
	}
	s1->elem[s1->top++] = val;
}
int PopQueue(Pstack s1,Pstack s2)
{
	assert(s1 != NULL && s2 != NULL);
	int tmp = 0;
	if(IsEmpty(s1) && IsEmpty(s2))
	{
		return 0;
	}
	if(!IsEmpty(s2))
	{
		s2->top--;
		tmp = s2->elem[s2->top];
		return tmp;
	}
	else
	{
		while(s1->top != 0)
		{
			s1->top--;
			s2->elem[s2->top++] = s1->elem[s1->top];
		}
		s2->top--;
		tmp = s2->elem[s2->top];
		return tmp;
	}
}

//'源.cpp'
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<vld.h>

/*
void EnterQue(Pstack s1,int val)
{}
int PopQueue(Pstack s1,Pstack s2)
{}
先进后出===>先进先出
*/

int main()
{
	Sqstack sq;
	InitStack(&sq);
	for(int i = 0;i < STACK_LEN;i++)
	{
		EnterQue(&sq,i);//0-9
	}
	Show(&sq);
	printf("================\n");
	int tmp = 0;
	Sqstack sq1;
	InitStack(&sq1);
	tmp = PopQueue(&sq,&sq1);
	printf("%d\n",tmp);//0
	tmp = PopQueue(&sq,&sq1);
	printf("%d\n",tmp);//1
	tmp = PopQueue(&sq,&sq1);
	printf("%d\n",tmp);//2
	tmp = PopQueue(&sq,&sq1);
	printf("%d\n",tmp);//3
	printf("================\n");
	for(int i = 0;i < 6;i++)
	{
		EnterQue(&sq,i+30);//0-9
	}
	tmp = PopQueue(&sq,&sq1);
	printf("%d\n",tmp);//4
	printf("================\n");
	Show(&sq);
	return 0;
}