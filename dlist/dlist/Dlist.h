#pragma once
#include<stdio.h>
#include<stdlib.h>
// 2、带头+双向+循环链表增删查改实现
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
// 创建返回链表的头结点.
ListNode* ListCreate();
// 双向链表尾插
void ListPushBack(ListNode* plist, DataType x);
// 双向链表尾删
void ListPopBack(ListNode* plist);
// 双向链表头插
void ListPushFront(ListNode* plist, DataType x);
// 双向链表头删
void ListPopFront(ListNode* plist);
// 双向链表查找
ListNode* ListFind(ListNode* plist, DataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, DataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);
// 双向链表销毁
void ListDestory(ListNode** plist);