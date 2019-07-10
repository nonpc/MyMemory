#include<iostream>

using namespace std;

//题目 : 已知一棵BST树的前序遍历结果pre数组，和中序遍历结果in数组，重建二叉树(递归实现)

/*
前序遍历的第一个数是这棵树的根节点
中序遍历是按照从小到大排列 , 在中序遍历中找到根节点 
左边的就是左子树 , 右边的就是右子树
然后用得到的左右子树的个数 , 用前序遍历的数组进行重构
*/

//二叉搜索树的结构定义
template<typename T>
class BSTree
{
public:
	BSTree():_root(nullptr){}
private:
	// 定义BST树节点的类型
	struct BSTNode
	{
		BSTNode(T data=T())
			:_data(data)     //数据
			,_left(nullptr)  //左孩子
			,_right(nullptr) //右孩子
		{}
		T _data;
		BSTNode *_left;
		BSTNode *_right;
	};
	BSTNode *_root; // 指向树的根节点
};


void rebuildBSTree(int pre[], int len1, int in[], int len2)
{
	this->_root = rebuildBSTree(pre, 0, len1-1, in, 0, len2-1);
}

//重建
BSTNode* rebuildBSTree(int pre[], int i, int j, int in[], int m, int n)
{	
	if (i > j || m > n)
	{
		return nullptr;
	}
	//前序遍历的根节点
	BSTNode *root = new BSTNode(pre[i]);
	for (int k = m; k <= n; ++k)
	{
		if (pre[i] == in[k]) // 中序遍历种找到根节点了
		{
			root->_left = rebuildBSTree(pre, i+1, i+(k-m), in, m, k-1);
			root->_right = rebuildBSTree(pre, i+(k - m)+1, j, in, k+1, n);
			break;
		}
	}
	//更新
	return root;
}

