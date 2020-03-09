#pragma once//����ͬһ���ļ������չ��
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

// ˳���Ķ�̬�洢
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
void SListPushBack(SList* plt, SLTDataType x);//β��
void SListPopBack(SList* plt);//βɾ
void SListPushFront(SList* plt, SLTDataType x);//ͷ��
void SListPopFront(SList* plt);//ͷɾ
SListNode* SListFind(SList* plt, SLTDataType x);
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ��pos��ǰ����в��� 
void SListInsertFront(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);//ɾ��ĳ��λ�ú�Ľ�� 
void SListErase(SListNode* pos);//ɾ��ĳ��λ�ý�� 
void SListRemove(SList* plt, SLTDataType x);
void SListPrint(SList* plt);
void TestSList();