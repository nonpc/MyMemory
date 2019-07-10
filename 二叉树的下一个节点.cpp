#include<iostream>

using namespace std;

/*
��Ŀ : ����һ�ö�������е�һ���ڵ� , ����ҳ������������һ���ڵ�?
���еĽڵ�����������ֱ�ָ���� , ���ӽڵ��ָ�� , ����һ��ָ�򸸽ڵ��ָ��
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