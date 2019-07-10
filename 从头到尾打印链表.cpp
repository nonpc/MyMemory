#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;


//69.从尾到头打印链表
/*解题思路:
使用递归的方式,先输出后面的节点,然后依次输出前面的节点

注意:
当链表非常长的时候,就会导致函数调用的层级很深,从而哟有可能导致函数调用栈溢出
*/
'list.h'
#pragma once
typedef struct Node
{
	int data;
	struct Node *next;
}Node,*List;
void InitList(List plist);//初始化单链表

bool Insert_head(List plist,int val);//头插法

bool Insert_tail(List plist,int val);//尾插法

bool Insert_pos(List plist,int pos,int val);//pos 位置插入

Node *Search_pre(List plist,int key);//查找 key 的前驱

bool Delete(List plist,int key);//删除 key 这个结点

bool IsEmpty(List plist);//是否为空

void Destroy(List plist);//摧毁函数（如果有动态开辟内存）

int GetLength(List plist);//得到单链表的长度

void Show(List plist);//打印单链表

'list.cpp'
#include"list.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

void InitList(List plist)//初始化单链表
{
	assert(plist != NULL);
	plist->next = NULL;
}

static Node *GetNode(int val)
{
	Node* pGet = (Node*)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

bool Insert_head(List plist,int val)//头插法
{
	assert(plist != NULL);
	Node *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
	return true;
}

bool Insert_tail(List plist,int val)//尾插法
{
	assert(plist != NULL);
	Node *cur = plist;//指向头结点处     依赖前驱信息的
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	Node *pGet = GetNode(val);
	cur->next = pGet;
	return true;
}

bool Insert_pos(List plist,int pos,int val)//pos 位置插入
{
	assert(plist != NULL);
	if(pos < 0 || pos > GetLength(plist))
	{
		return false;
	}
	Node *cur = plist;
	for(int i = 0;i <= pos-1;i++)
	{
		cur = cur->next;
	}
	Node *pGet = GetNode(val);
	pGet->next = cur->next;
	cur->next = pGet;
	return true;
}

Node *Search_pre(List plist,int key)//查找 key 的前驱
{
	assert(plist != NULL);
	Node *cur = plist;
	while(cur->next != NULL)
	{
		if(cur->next->data != key)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

bool Delete(List plist,int key)//删除 key 这个结点
{
	assert(plist != NULL);
	if(IsEmpty(plist))
	{
		return false;
	}
	Node *cur = plist;
	while(cur->next != NULL)
	{
		if(cur->next->data == key)
		{
			Node *p = cur->next;
			cur->next = p->next;
			free(p);
			p = NULL;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool IsEmpty(List plist)//是否为空
{
	if(plist == NULL || plist->next == NULL)
	{
		return true;
	}
	return false;
}

void Destroy(List plist)//摧毁函数（如果有动态开辟内存）
{
	assert(plist != NULL);
	if(IsEmpty(plist))
	{
		return;
	}
	Node *cur = plist;
	while(cur->next != NULL)
	{
		Node *p = cur->next;
		cur->next = p->next;
		free(p);
		p = NULL;
	}
	free(cur->next);
	plist->next = NULL;
	return ;
}

int GetLength(List plist)//得到单链表的长度
{
	assert(plist != NULL);
	if(IsEmpty(plist))
	{
		return 0;
	}
	int count = 0;
	Node *cur = plist;
	while (cur->next != NULL)
	{
		count++;
		cur = cur->next;
	}
	count++;
	return count;
}

void Show(List plist)//打印单链表
{
	assert(plist != NULL);
	if(IsEmpty(plist))
	{
		return;
	}
	Node *cur = plist->next;
	while(cur->next != NULL)
	{
		printf("%d \n",cur->data);
		cur = cur->next;
	}
	printf("%d \n",cur->data);
}

'test.cpp'
void Fun(List plist)
{
	assert(plist != NULL);
	if(plist != NULL)
	{
		if(plist->next != NULL)
		{
			Fun(plist->next);
		}
		printf("%d ",plist->data);
	}
	printf("\n");
}

int main()
{
	Node sq;
	InitList(&sq);
	for(int i = 0;i < 4;i++)
	{
		Insert_head(&sq,i+3);
	}
	Show(&sq);
	printf("===========\n");
	Fun(&sq);
	Destroy(&sq);
	return 0;
}