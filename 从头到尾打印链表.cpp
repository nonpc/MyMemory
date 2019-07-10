#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;


//69.��β��ͷ��ӡ����
/*����˼·:
ʹ�õݹ�ķ�ʽ,���������Ľڵ�,Ȼ���������ǰ��Ľڵ�

ע��:
������ǳ�����ʱ��,�ͻᵼ�º������õĲ㼶����,�Ӷ�Ӵ�п��ܵ��º�������ջ���
*/
'list.h'
#pragma once
typedef struct Node
{
	int data;
	struct Node *next;
}Node,*List;
void InitList(List plist);//��ʼ��������

bool Insert_head(List plist,int val);//ͷ�巨

bool Insert_tail(List plist,int val);//β�巨

bool Insert_pos(List plist,int pos,int val);//pos λ�ò���

Node *Search_pre(List plist,int key);//���� key ��ǰ��

bool Delete(List plist,int key);//ɾ�� key ������

bool IsEmpty(List plist);//�Ƿ�Ϊ��

void Destroy(List plist);//�ݻٺ���������ж�̬�����ڴ棩

int GetLength(List plist);//�õ�������ĳ���

void Show(List plist);//��ӡ������

'list.cpp'
#include"list.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

void InitList(List plist)//��ʼ��������
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

bool Insert_head(List plist,int val)//ͷ�巨
{
	assert(plist != NULL);
	Node *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
	return true;
}

bool Insert_tail(List plist,int val)//β�巨
{
	assert(plist != NULL);
	Node *cur = plist;//ָ��ͷ��㴦     ����ǰ����Ϣ��
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	Node *pGet = GetNode(val);
	cur->next = pGet;
	return true;
}

bool Insert_pos(List plist,int pos,int val)//pos λ�ò���
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

Node *Search_pre(List plist,int key)//���� key ��ǰ��
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

bool Delete(List plist,int key)//ɾ�� key ������
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

bool IsEmpty(List plist)//�Ƿ�Ϊ��
{
	if(plist == NULL || plist->next == NULL)
	{
		return true;
	}
	return false;
}

void Destroy(List plist)//�ݻٺ���������ж�̬�����ڴ棩
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

int GetLength(List plist)//�õ�������ĳ���
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

void Show(List plist)//��ӡ������
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