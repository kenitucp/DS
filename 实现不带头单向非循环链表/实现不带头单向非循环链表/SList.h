#pragma once//避免同一个文件被多次展开
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

// 顺序表的动态存储
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;
void SListInit(SList* plt);
void SListDestory(SList* plt);
SListNode* BuySListNode(SLTDataType x);
void SListPushBack(SList* plt, SLTDataType x);//尾插
void SListPopBack(SList* plt);//尾删
void SListPushFront(SList* plt, SLTDataType x);//头插
void SListPopFront(SList* plt);//头删
SListNode* SListFind(SList* plt, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入 
void SListInsertFront(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);//删除某个位置后的结点 
void SListErase(SListNode* pos);//删除某个位置结点 
void SListRemove(SList* plt, SLTDataType x);
void SListPrint(SList* plt);
void TestSList();