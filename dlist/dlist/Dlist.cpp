#include"Dlist.h"
#include<malloc.h>
#include<assert.h>
ListNode *BuyListNode(int val)
{
	ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->_data=val;
	newNode->_prev = NULL;
	newNode->_next = NULL;

	return newNode;

}
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode*head = BuyListNode(0);
	head->_next = head;
	head->_prev = head;
	return head;
}
// 双向链表尾插
void ListPushBack(ListNode* plist, DataType x)
{
	if (NULL == plist)
		return;
	ListNode *newNode = BuyListNode(x);
	newNode->_prev = plist->_prev;//链接新节点到原链表
	newNode->_next = plist;
	plist->_prev->_next = newNode;//断开原链表，链接新节点的其他俩个指针
	plist->_prev = newNode;
}
// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	//链表不存在--代码是一种非法的情况
	if (NULL == plist)
	{
		assert(0);//assert是一个调试宏，只在debug版本起作用。release版本里面就会优化，assert就没有了
		return ;
	}
	//检测是否为空链表
	if (plist->_next == plist)
		return;
	ListNode *pos = plist->_prev;
	plist->_prev = pos->_prev;//链接
	pos->_prev->_next = plist;
	free(pos);//删除
}
// 双向链表头插
void ListPushFront(ListNode* plist, DataType x)
{
	if (NULL == plist)
		return;
	ListInsert(plist->_next, x);
}
// 双向链表头删
void ListPopFront(ListNode* plist)
{
	if (NULL == plist)
		return;
	ListErase(plist->_next);
}
// 双向链表查找
ListNode* ListFind(ListNode* plist, DataType x)
{
	if (NULL == plist)
		return NULL;
	ListNode *cur = plist->_next;
	while (cur!=plist)
	{
		if (cur->_data== x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, DataType x)
{
	ListNode *newNode = BuyListNode(x);
	newNode->_prev = pos->_prev;//链接后断开
	newNode->_next = pos;
	newNode->_prev->_next = newNode;
	pos->_prev = newNode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	if (NULL == pos)
		return;
	pos->_prev->_prev = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
// 双向链表销毁
void ListDestory(ListNode** plist)
{
	ListNode *cur = NULL;
	if (NULL == plist)
		return ;
	cur = (*plist)->_next;//将链表中的有效结点删除
	while (cur!=*plist)
	{
		(*plist)->_next = cur->_next;
		free(cur);
		cur = (*plist)->_next;
	}
	free(*plist);
	*plist = NULL;
}
void DListTest()
{
	ListNode *head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	ListPopBack(head);
	ListPopBack(head);
	ListPopBack(head);

	ListPushFront(head, 0);
	ListPushFront(head, 1);
	ListPushFront(head, 2);

	ListErase(ListFind(head, 0));

	ListDestory(&head);//链表销毁了，最后plist肯定指向NULL。因此在销毁函数中，要通过形参改变实参指针的指向
}
int main()
{
	DListTest();
	return 0;
}