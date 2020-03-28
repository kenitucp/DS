#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* pleft;
	struct BinaryTreeNode* pright;
}BTNode;
//// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// ����������
void BinaryTreeDestory(BTNode** root);
//��ȡ�������ڵ����
int BinaryTreeSize(BTNode* root);
//��ȡ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��ȡ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
//��ȡ�������߶�
int GetHeight(BTNode* root);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//��ȡNode��˫��
BTNode* GetParent(BTNode* root, BTNode* Node);
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);