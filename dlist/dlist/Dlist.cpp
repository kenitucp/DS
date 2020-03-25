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
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode*head = BuyListNode(0);
	head->_next = head;
	head->_prev = head;
	return head;
}
// ˫������β��
void ListPushBack(ListNode* plist, DataType x)
{
	if (NULL == plist)
		return;
	ListNode *newNode = BuyListNode(x);
	newNode->_prev = plist->_prev;//�����½ڵ㵽ԭ����
	newNode->_next = plist;
	plist->_prev->_next = newNode;//�Ͽ�ԭ���������½ڵ����������ָ��
	plist->_prev = newNode;
}
// ˫������βɾ
void ListPopBack(ListNode* plist)
{
	//��������--������һ�ַǷ������
	if (NULL == plist)
	{
		assert(0);//assert��һ�����Ժֻ꣬��debug�汾�����á�release�汾����ͻ��Ż���assert��û����
		return ;
	}
	//����Ƿ�Ϊ������
	if (plist->_next == plist)
		return;
	ListNode *pos = plist->_prev;
	plist->_prev = pos->_prev;//����
	pos->_prev->_next = plist;
	free(pos);//ɾ��
}
// ˫������ͷ��
void ListPushFront(ListNode* plist, DataType x)
{
	if (NULL == plist)
		return;
	ListInsert(plist->_next, x);
}
// ˫������ͷɾ
void ListPopFront(ListNode* plist)
{
	if (NULL == plist)
		return;
	ListErase(plist->_next);
}
// ˫���������
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
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, DataType x)
{
	ListNode *newNode = BuyListNode(x);
	newNode->_prev = pos->_prev;//���Ӻ�Ͽ�
	newNode->_next = pos;
	newNode->_prev->_next = newNode;
	pos->_prev = newNode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	if (NULL == pos)
		return;
	pos->_prev->_prev = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
// ˫����������
void ListDestory(ListNode** plist)
{
	ListNode *cur = NULL;
	if (NULL == plist)
		return ;
	cur = (*plist)->_next;//�������е���Ч���ɾ��
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

	ListDestory(&head);//���������ˣ����plist�϶�ָ��NULL����������ٺ����У�Ҫͨ���βθı�ʵ��ָ���ָ��
}
int main()
{
	DListTest();
	return 0;
}