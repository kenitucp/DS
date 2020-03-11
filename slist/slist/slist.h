#pragma once
//不带头结点的单链表
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

//尾插/删
void SLPushBack( SLNode**head, DataType data);
void SLPopBack( SLNode**head);

//头插/删
void SLPushFront( SLNode**head, DataType data);
void SLPopFront(SLNode**head);

//在POS位置后插入data
void SLInsertAfter(SLNode*pos, int data);
void SLErase(SLNode*pos);
int SLSize(SLNode*head);
SLNode*SLFind(SLNode*head,int data);
void SLDestroy(SLNode**head);


void PrintSList( SLNode*head);

