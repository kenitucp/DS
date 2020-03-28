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
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate()//ֻΪ�˿�����֤������ʽ�Ƿ���ȷ
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
// ����������
void BinaryTreeDestory(BTNode** root);
// �������ڵ����
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
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return 0;
	if (root->pleft == NULL&&root->pright == NULL)
		return 1;
	return BinaryTreeLeafSize(root->pleft) +BinaryTreeLeafSize(root->pright);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root||k<=0)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->pleft, k - 1) + BinaryTreeLevelKSize(root->pright, k - 1);
}
int GetHeight(BTNode* root)//��ȡ�������߶�
{
	if (NULL == root)
		return 0;
	int leftheight = GetHeight(root->pleft);
	int rightheight = GetHeight(root->pright);
	return (leftheight > rightheight) ? (leftheight + 1) : (rightheight + 1);
}
// ����������ֵΪx�Ľڵ�
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
//��ȡNode��˫��
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
	//return GetParent(root->pleft, Node) || GetParent(root->pright, Node);//���ܰ������ַ�ʽ���أ���Ϊ���ص���һ����ٵĽ��

}
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%d", root->val);
		BinaryTreePrevOrder(root->pleft);
		BinaryTreePrevOrder(root->pright);
	}

}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->pleft);
		printf("%d", root->val);
		BinaryTreeInOrder(root->pright);
	}
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->pleft);
		BinaryTreePostOrder(root->pright);
		printf("%d", root->val);
	}
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (NULL == root)
		return ;
	QueuePush(&q, root);//�����
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
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
void test()
{
	BTNode* root = BinaryTreeCreate();
	printf("ǰ����������");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("������������");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("������������");
	BinaryTreePostOrder(root);
	printf("\n");

	printf("�������н�������%d\n", BinaryTreeSize(root));
	printf("��������Ҷ�ӽ�������%d\n", BinaryTreeLeafSize(root));
	printf("�������߶�Ϊ��%d\n", GetHeight(root));
	printf("��������k�������Ϊ��%d\n", BinaryTreeLevelKSize(root,3));
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