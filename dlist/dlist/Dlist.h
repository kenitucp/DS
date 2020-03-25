#pragma once
#include<stdio.h>
#include<stdlib.h>
// 2����ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
// �������������ͷ���.
ListNode* ListCreate();
// ˫������β��
void ListPushBack(ListNode* plist, DataType x);
// ˫������βɾ
void ListPopBack(ListNode* plist);
// ˫������ͷ��
void ListPushFront(ListNode* plist, DataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* plist);
// ˫���������
ListNode* ListFind(ListNode* plist, DataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, DataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
// ˫����������
void ListDestory(ListNode** plist);