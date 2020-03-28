#include"BinaryTree.h"
#include<malloc.h>
#include<assert.h>
BTNode* BuyBinaryTreeNode(BTDataType val)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->pleft = NULL;
	pNewNode->pright = NULL;
	pNewNode->val = val;
	return pNewNode;
}
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate()//只为了快速验证所给方式是否正确
{
	BTNode* node1 = BuyBinaryTreeNode(1);
	BTNode* node2 = BuyBinaryTreeNode(2);
	BTNode* node3 = BuyBinaryTreeNode(3);
	BTNode* node4 = BuyBinaryTreeNode(4);
	BTNode* node5 = BuyBinaryTreeNode(5);
	BTNode* node6 = BuyBinaryTreeNode(6);
	BTNode* root = node1;
	node1->pleft = node2;
	node2->pleft = node3;
	node1->pright = node4;
	node4->pleft = node5;
	node4->pright = node6;
	return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
//int count = 0;
//int BinaryTreeSize(BTNode* root)
//{
//	if (root)
//	{
//		count++;
//		BinaryTreeSize(root->pleft);
//		BinaryTreeSize(root->pright);
//	}
//	return count;
//}
int BinaryTreeSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	return 1 + BinaryTreeSize(root->pleft) +
		BinaryTreeSize(root->pright);
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	if (root->pleft == NULL&&root->pright == NULL)
		return 1;
	return BinaryTreeLeafSize(root->pleft) +BinaryTreeLeafSize(root->pright);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root||k<=0)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->pleft, k - 1) + BinaryTreeLevelKSize(root->pright, k - 1);
}
int GetHeight(BTNode* root)//获取二叉树高度
{
	if (NULL == root)
		return 0;
	int leftheight = GetHeight(root->pleft);
	int rightheight = GetHeight(root->pright);
	return (leftheight > rightheight) ? (leftheight + 1) : (rightheight + 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* pNode = NULL;
	if (NULL == root)
		return NULL;
	if (root->val == x)
	{
		return root;
	}
	if ((pNode = BinaryTreeFind(root->pleft, x) )|| (pNode = BinaryTreeFind(root->pright, x)))
		return pNode;
	return NULL;
}
//获取Node的双亲
BTNode* GetParent(BTNode* root, BTNode* Node)
{
	BTNode* pParent = NULL;
	if (NULL == root||NULL==Node||Node==root)
		return NULL;
	if (root->pleft == Node || root->pright == Node)
		return root;
	if ((pParent = GetParent(root->pleft, Node)) ||( pParent = GetParent(root->pright, Node)))
		return pParent;
	return NULL;
	//return GetParent(root->pleft, Node) || GetParent(root->pright, Node);//不能按照这种方式返回，因为返回的是一个真假的结果

}
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%d", root->val);
		BinaryTreePrevOrder(root->pleft);
		BinaryTreePrevOrder(root->pright);
	}

}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->pleft);
		printf("%d", root->val);
		BinaryTreeInOrder(root->pright);
	}
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->pleft);
		BinaryTreePostOrder(root->pright);
		printf("%d", root->val);
	}
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (NULL == root)
		return ;
	QueuePush(&q, root);//入队列
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d", front->val);
		if (front->pleft)
		{
			QueuePush(&q, front->pleft);
		}
		if (front->pright)
		{
			QueuePush(&q, front->pright);
		}
	}
	printf("\n");
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void test()
{
	BTNode* root = BinaryTreeCreate();
	printf("前序遍历结果：");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("中序遍历结果：");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("后序遍历结果：");
	BinaryTreePostOrder(root);
	printf("\n");

	printf("二叉树中结点个数：%d\n", BinaryTreeSize(root));
	printf("二叉树中叶子结点个数：%d\n", BinaryTreeLeafSize(root));
	printf("二叉树高度为：%d\n", GetHeight(root));
	printf("二叉树第k层结点个数为：%d\n", BinaryTreeLevelKSize(root,3));
	if (BinaryTreeFind(root, 3))
	{
		printf("3 is in binarytree!!!\n");
	}
	else
	{
		printf("3 is not  in binarytree!!!\n");
	}
	BTNode*parent = GetParent(root, BinaryTreeFind(root,3));
	if (parent)
	{
		printf("3's parent is %d!!!\n",parent->val);
	}
	else
	{
		printf("3 has no parent!!!\n");
	}

}
int main()
{
	test();
	return 0;
}