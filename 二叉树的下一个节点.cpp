#include<iostream>

using namespace std;

/*
题目 : 给定一棵二叉和其中的一个节点 , 如何找出中序遍历的下一个节点?
树中的节点除了有两个分别指向左 , 右子节点的指针 , 还有一个指向父节点的指针
*/

Binary TreeNode* GetNext(Binary TreeNode* pNode)
{
	if(pNode == nullptr)
		return nullptr;
	Binary TreeNode* pNext = nullptr;
	if(pNode->m_pRight != nullptr)
	{
		Binary TreeNode* pRight = pNode->m_pRight;
		while(pRight != nullptr)
		{
			pRight = pRight->m_pLeft;
		}
		pNext = pRight;
	}
	else if(pNode->m_pParent != nullptr)
	{
		Binary TreeNode* pCurrent = pNode;
		Binary TreeNode*  pParent = pNode->m_pParent;
		while(pParent != nullptr && pCurrent == pParent->m_pParent)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}