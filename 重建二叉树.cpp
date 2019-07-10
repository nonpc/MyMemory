#include<iostream>

using namespace std;

//��Ŀ : ��֪һ��BST����ǰ��������pre���飬������������in���飬�ؽ�������(�ݹ�ʵ��)

/*
ǰ������ĵ�һ������������ĸ��ڵ�
��������ǰ��մ�С�������� , ������������ҵ����ڵ� 
��ߵľ��������� , �ұߵľ���������
Ȼ���õõ������������ĸ��� , ��ǰ���������������ع�
*/

//�����������Ľṹ����
template<typename T>
class BSTree
{
public:
	BSTree():_root(nullptr){}
private:
	// ����BST���ڵ������
	struct BSTNode
	{
		BSTNode(T data=T())
			:_data(data)     //����
			,_left(nullptr)  //����
			,_right(nullptr) //�Һ���
		{}
		T _data;
		BSTNode *_left;
		BSTNode *_right;
	};
	BSTNode *_root; // ָ�����ĸ��ڵ�
};


void rebuildBSTree(int pre[], int len1, int in[], int len2)
{
	this->_root = rebuildBSTree(pre, 0, len1-1, in, 0, len2-1);
}

//�ؽ�
BSTNode* rebuildBSTree(int pre[], int i, int j, int in[], int m, int n)
{	
	if (i > j || m > n)
	{
		return nullptr;
	}
	//ǰ������ĸ��ڵ�
	BSTNode *root = new BSTNode(pre[i]);
	for (int k = m; k <= n; ++k)
	{
		if (pre[i] == in[k]) // ����������ҵ����ڵ���
		{
			root->_left = rebuildBSTree(pre, i+1, i+(k-m), in, m, k-1);
			root->_right = rebuildBSTree(pre, i+(k - m)+1, j, in, k+1, n);
			break;
		}
	}
	//����
	return root;
}

