#include"SList.h"

void SListInit(SList* plt)//初始化 
{
	assert(plt);
	plt->_head = NULL;
}
void SListDestory(SList* plt);
SListNode* BuySListNode(SLTDataType x)//创建新节点 
{
	SListNode*newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	return newnode;
}
void SListPushBack(SList* plt, SLTDataType x)//尾插 
{
	assert(plt);
	SListNode*newnode;
	SListNode*cur;
	newnode = BuySListNode(x);
	if (plt->_head == NULL)//1、边界条件：链表为空 
	{
		plt->_head = newnode;
	}
	else//2、链表不为空：先找链表中左后一个结点，再将新节点插入
	{
		cur = plt->_head;
		//先找尾
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		//后链接 
		cur->_next = newnode;
	}
}
void SListPopBack(SList* plt)//尾删 
{
   assert(plt);//1、链表是否存在
   if (plt->_head == NULL)//2、边界条件：链表为空链表 
   {
   	 return ; 
   }
  if (plt->_head->_next == NULL)//3、边界条件：链表中只有一个结点
   {
	  free(plt->_head);
   	    plt->_head==NULL;
   }
   SListNode*cur;
   cur=plt->_head;
   //4、链表中有多个结点
   while(cur->_next->_next!=NULL)//找尾
	  {
	  	cur=cur->_next;	
	  }	
	  free(cur->_next);//删除
	  cur->_next=NULL;//置空
} 
void SListPushFront(SList* plt, SLTDataType x)//头插 
{
   assert(plt);//1、判断链表是否存在
   SListNode *newnode;
   newnode=BuySListNode(x);
   newnode->_next=plt->_head;//2、链表为空，有一个结点，有多个结点
   plt->_head=newnode;
}
void SListPopFront(SList* plt)//头删
{
   assert(plt);//1、判断链表是否存在
   SListNode*cur=plt->_head;
   plt->_head=plt->_head->_next;//2、链表为空，有一个结点，有多个结点
   free(cur);
   cur=NULL;
} 
SListNode* SListFind(SList* plt, SLTDataType x)
{
   assert(plt);
   SListNode*cur=plt->_head;
   while(cur)
   {
   	if(cur->_data==x)
   	{
   	   return cur;	
	}
	cur=cur->_next;
   }
   return NULL;	
}
void SListInsertAfter(SListNode* pos, SLTDataType x)// 在pos的后面进行插入
{
	assert(pos);
	SListNode* next = pos->_next;//用next标记POS的下一个位置
	SListNode* newnode = BuySListNode(x);
	newnode->_next = next;//先链接下一个位置
	pos->_next = newnode;//再链接上一个位置
}
// 在pos的前面进行插入 
void SListInsertFront(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->_next = pos->_next;
	pos->_next = newnode;//先把新节点插入pos后面
	newnode->_data = pos->_data;
	pos->_data = x;//再交换POS和新节点的值（仿佛实现了在POS前插入某个值，但不是直接插入的）
}
void SListEraseAfter(SListNode* pos)//删除某个位置后的结点 
{
	//assert(pos);
	//SListNode* next = pos->_next->_next;//用neat标记POS的下下个位置
	//free(pos->_next);//删除pos后面的位置
	//pos->_next = next;//链接
	assert(pos);
	SListNode* cur = pos->_next;
	pos->_next = cur->_next;
	free(cur);
}
void SListRemove(SList* plt, SLTDataType x)//移除等于某个值的结点
{
	assert(plt);
	SListNode* cur = plt->_head;
	SListNode* prev = NULL;
	while (cur)
	{
		SListNode* next = cur->_next;
		if (cur->_data == x)
		{
			if (cur == plt->_head)
				plt->_head = next;
			else
			{
				prev->_next = next;//先链接
				free(cur);//再删除
				cur = NULL;
			}
			break;
		}
		   //向前走
			prev = cur;
			cur = next;
	}
}
void SListPrint(SList* plt)
{
	SListNode*cur = plt->_head;
	//迭代 
	while (cur)
	{
		printf("%d--->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
void TestSList()
{
	SList s1;
	SListInit(&s1);
	SListPushBack(&s1, 1);
	SListPushBack(&s1, 2);
	SListPushBack(&s1, 3);
	SListPushBack(&s1, 4);
	SListPushBack(&s1, 5);
	SListPrint(&s1); //尾插结果 

	SListPopBack(&s1);
	SListPrint(&s1); //尾删结果 

	SListPushFront(&s1,5);
	SListPushFront(&s1,2);
	SListPushFront(&s1,0);
	SListPrint(&s1); //头插结果 

	SListPopFront(&s1);
	SListPopFront(&s1);
	SListPrint(&s1); //头删结果 

	SListInsertAfter(SListFind(&s1, 2), 18);
	SListPrint(&s1);//pos后插入结果

	SListInsertFront(SListFind(&s1, 2), 15);
	SListPrint(&s1);//pos前插入结果

	SListEraseAfter(SListFind(&s1, 1));
	SListPrint(&s1);//删除某个位置后的结点的结果

	SListRemove(&s1, 1);
	SListPrint(&s1);//移除等于某个值的结点的结果
}
int main()
{
	TestSList();
	system("pause");
	return 0;
}