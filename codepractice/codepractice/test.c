//#pragma once
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<string.h>
//typedef char BTDataType;
//typedef struct BinaryTreeNode
//{
//	BTDataType val;
//	struct BinaryTreeNode* pleft;
//	struct BinaryTreeNode* pright;
//}BTNode;
//// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//// �������������
//void BinaryTreeInOrder(BTNode* root);
//BTNode* BuyBinaryTreeNode(BTDataType val);
//BTNode* BuyBinaryTreeNode(BTDataType val)
//{
//	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
//	if (NULL == pNewNode)
//	{
//		assert(0);
//		return NULL;
//	}
//	pNewNode->pleft = NULL;
//	pNewNode->pright = NULL;
//	pNewNode->val = val;
//	return pNewNode;
//}
//BTNode* _BinaryTreeCreate(int *array, int size, int *index, BTDataType invaild)
//{
//	BTNode* root = NULL;
//	if (*index < size&&array[*index] != invaild)
//	{
//		root = BuyBinaryTreeNode(array[*index]);
//		++(*index);
//		root->pleft = _BinaryTreeCreate(array, size, index, invaild);
//		++(*index);
//		root->pright = _BinaryTreeCreate(array, size, index, invaild);
//	}
//	return root;
//}
//BTNode* BinaryTreeCreate(int *array, int size, BTDataType invaild)
//{
//	int index = 0;
//	return _BinaryTreeCreate(array, size, &index, invaild);
//}
//// �������������
//void BinaryTreeInOrder(BTNode* root)
//{
//	if (root)
//	{
//		BinaryTreeInOrder(root->pleft);
//		printf("%d", root->val);
//		BinaryTreeInOrder(root->pright);
//	}
//}
//int main()
//{
//	char array[101];
//	while (scanf("%s", &array) != EOF)
//	{
//		BTNode* root = BinaryTreeCreate(array, strlen(array), -1);//��λ�ò�1��ԭ��Ҫ���λ�ò�*
//		printf("������������");
//		BinaryTreeInOrder(root);
//		printf("\n");
//	}
//
//}
#include<stdio.h>
#include<malloc.h>
typedef struct BTNode
{
	struct BTNode* _left;
	struct BTNode* _right;
	char _data;
}BTNode;

BTNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*pi];
		++(*pi);
		root->_left = CreateTree(str, pi);
		++(*pi);
		root->_right = CreateTree(str, pi);
		return root;
	}
}

void InOrder(BTNode* root)
{
	if (root == NULL) return;
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

int main()
{
	char str[100] = { 0 };
	scanf("%s", str);
	int i = 0;
	BTNode* tree = CreateTree(str, &i);
	InOrder(tree);
	return 0;
}
