#include"slist.h"


//构建一个新的结点
SLNode* BuyNode(DataType data)
{
	SLNode *newNode = (SLNode*)malloc(sizeof(SLNode));
	if (NULL == newNode)
	{
		printf("申请节点失败\n");
		assert(newNode);
	}

	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}
//尾插
void SLPushBack( SLNode**head, DataType data)
{
	assert(head);//链表是否存在
	SLNode* newNode = BuyNode(data);
	if (NULL == *head)//链表是否为空链表（没有任何结点的链表）
	{
		*head = newNode;//第一个结点的插入方式
	}
	else//链表非空
	{
		SLNode* tail = *head;
		while (tail->next)//1、先去找链表中最后一个结点
		{
			tail = tail->next;
		}
		tail->next = newNode;//2、链接新结点
	}
}
//尾删
void SLPopBack(SLNode**head)
{
	assert(head);//链表是否存在
	//先画图分析考虑常规情况
	//再画图分析考虑非常规情况（边界条件）
	if (NULL == *head)//1、链表是否为空链表（没有任何结点的链表）
		return;
    if ((*head)->next == NULL)//2、链表中只有一个结点
	{
		free(*head);
		*head = NULL;
	}
	SLNode*prev = NULL;
	SLNode*cur = *head;
	//3、链表中有多个结点，借助cur先找到最后一个结点，并保存cur的上一个位置
	while (cur->next)
	{
		prev = cur;//保存cur的上一个位置
		cur = cur->next;
	}
	prev->next = cur->next;//链接
	free(cur);//删除
}

//头插
void SLPushFront(SLNode**head, DataType data)
{
	assert(head);//链表是否存在
	SLNode*  newNode = BuyNode(data);
	newNode->next = *head;//1、链表为空链表或者链表中有多个节点--链接
	*head = newNode;	 
}
//头删
void SLPopFront(SLNode**head)
{
	assert(head);//链表是否存在
	if (NULL == *head)//1、链表是否为空链表（没有任何结点的链表）
		return;
	if ((*head)->next == NULL)//2、链表中只有一个结点
	{
		free(*head);
		*head = NULL;
	}
	SLNode* delNode = *head;//标记尾删的结点
	*head = delNode->next;//链接
	free(delNode);//删除
}

//在POS位置后插入data
void SLInsertAfter(SLNode*pos, int data)//任意位置插入(后面）
{	
	SLNode* newNode = NULL;
	//参数检测
	if (NULL == pos)
		return ;
	newNode = BuyNode(data);
	newNode->next = pos->next;//第一步，新节点的下一个位置指向POS的下一个位置
	pos->next = newNode;//第二步，POS的下一个位置指向新节点
}
void SLErase(SLNode*pos)//任意位置删除
{
	SLNode* delNode = NULL;
	//pos不存在或者pos的下一个位置为空
	if (NULL == pos || NULL == pos->next)
		return;
	delNode = pos->next;
	pos->next = delNode->next;//先链接
	free(delNode);//再删除
}
int SLSize(SLNode*head)
{
	int count = 0;
	SLNode *cur = head;//遍历链表
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;

}
SLNode*SLFind(SLNode*head, int data)
{
	SLNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SLDestroy(SLNode**head)
{
	assert(head);
	SLNode *cur = *head;
	while (cur)//头删
	{
		*head = cur->next;//先链接
		free(cur);//再删除
		cur = *head;
	}
}

void PrintSList(SLNode*head)
{
	SLNode *cur = head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

int main(void)
{
	SLNode *L = NULL;//表示l所代表的单链表中一个元素都没有
	SLPushBack(&L, 1);
	SLPushBack(&L, 2);
	SLPushBack(&L, 3);
	SLPushBack(&L, 4);
	SLPushBack(&L, 5);
	PrintSList(L);

	SLPopBack(&L);
	PrintSList(L);

	SLPopBack(&L);
	PrintSList(L);

	SLPushFront(&L, 6);
	SLPushFront(&L, 4);
	PrintSList(L);

	SLPopBack(&L);
	PrintSList(L);

	SLPopFront(&L);
	PrintSList(L);

	SLInsertAfter(SLFind(L, 3), 6);
	SLInsertAfter(SLFind(L, 3), 8);
	PrintSList(L);
}
