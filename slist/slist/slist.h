#pragma once
//����ͷ���ĵ�����
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef struct SLNode
{
	int data;
	struct SLNode* next;
	
}SLNode;

//β��/ɾ
void SLPushBack( SLNode**head, DataType data);
void SLPopBack( SLNode**head);

//ͷ��/ɾ
void SLPushFront( SLNode**head, DataType data);
void SLPopFront(SLNode**head);

//��POSλ�ú����data
void SLInsertAfter(SLNode*pos, int data);
void SLErase(SLNode*pos);
int SLSize(SLNode*head);
SLNode*SLFind(SLNode*head,int data);
void SLDestroy(SLNode**head);


void PrintSList( SLNode*head);

