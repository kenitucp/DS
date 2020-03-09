#include"SList.h"

void SListInit(SList* plt)//��ʼ�� 
{
	assert(plt);
	plt->_head = NULL;
}
void SListDestory(SList* plt);
SListNode* BuySListNode(SLTDataType x)//�����½ڵ� 
{
	SListNode*newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	return newnode;
}
void SListPushBack(SList* plt, SLTDataType x)//β�� 
{
	assert(plt);
	SListNode*newnode;
	SListNode*cur;
	newnode = BuySListNode(x);
	if (plt->_head == NULL)//1���߽�����������Ϊ�� 
	{
		plt->_head = newnode;
	}
	else//2������Ϊ�գ��������������һ����㣬�ٽ��½ڵ����
	{
		cur = plt->_head;
		//����β
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		//������ 
		cur->_next = newnode;
	}
}
void SListPopBack(SList* plt)//βɾ 
{
   assert(plt);//1�������Ƿ����
   if (plt->_head == NULL)//2���߽�����������Ϊ������ 
   {
   	 return ; 
   }
  if (plt->_head->_next == NULL)//3���߽�������������ֻ��һ�����
   {
	  free(plt->_head);
   	    plt->_head==NULL;
   }
   SListNode*cur;
   cur=plt->_head;
   //4���������ж�����
   while(cur->_next->_next!=NULL)//��β
	  {
	  	cur=cur->_next;	
	  }	
	  free(cur->_next);//ɾ��
	  cur->_next=NULL;//�ÿ�
} 
void SListPushFront(SList* plt, SLTDataType x)//ͷ�� 
{
   assert(plt);//1���ж������Ƿ����
   SListNode *newnode;
   newnode=BuySListNode(x);
   newnode->_next=plt->_head;//2������Ϊ�գ���һ����㣬�ж�����
   plt->_head=newnode;
}
void SListPopFront(SList* plt)//ͷɾ
{
   assert(plt);//1���ж������Ƿ����
   SListNode*cur=plt->_head;
   plt->_head=plt->_head->_next;//2������Ϊ�գ���һ����㣬�ж�����
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
void SListInsertAfter(SListNode* pos, SLTDataType x)// ��pos�ĺ�����в���
{
	assert(pos);
	SListNode* next = pos->_next;//��next���POS����һ��λ��
	SListNode* newnode = BuySListNode(x);
	newnode->_next = next;//��������һ��λ��
	pos->_next = newnode;//��������һ��λ��
}
// ��pos��ǰ����в��� 
void SListInsertFront(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->_next = pos->_next;
	pos->_next = newnode;//�Ȱ��½ڵ����pos����
	newnode->_data = pos->_data;
	pos->_data = x;//�ٽ���POS���½ڵ��ֵ���·�ʵ������POSǰ����ĳ��ֵ��������ֱ�Ӳ���ģ�
}
void SListEraseAfter(SListNode* pos)//ɾ��ĳ��λ�ú�Ľ�� 
{
	//assert(pos);
	//SListNode* next = pos->_next->_next;//��neat���POS�����¸�λ��
	//free(pos->_next);//ɾ��pos�����λ��
	//pos->_next = next;//����
	assert(pos);
	SListNode* cur = pos->_next;
	pos->_next = cur->_next;
	free(cur);
}
void SListRemove(SList* plt, SLTDataType x)//�Ƴ�����ĳ��ֵ�Ľ��
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
				prev->_next = next;//������
				free(cur);//��ɾ��
				cur = NULL;
			}
			break;
		}
		   //��ǰ��
			prev = cur;
			cur = next;
	}
}
void SListPrint(SList* plt)
{
	SListNode*cur = plt->_head;
	//���� 
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
	SListPrint(&s1); //β���� 

	SListPopBack(&s1);
	SListPrint(&s1); //βɾ��� 

	SListPushFront(&s1,5);
	SListPushFront(&s1,2);
	SListPushFront(&s1,0);
	SListPrint(&s1); //ͷ���� 

	SListPopFront(&s1);
	SListPopFront(&s1);
	SListPrint(&s1); //ͷɾ��� 

	SListInsertAfter(SListFind(&s1, 2), 18);
	SListPrint(&s1);//pos�������

	SListInsertFront(SListFind(&s1, 2), 15);
	SListPrint(&s1);//posǰ������

	SListEraseAfter(SListFind(&s1, 1));
	SListPrint(&s1);//ɾ��ĳ��λ�ú�Ľ��Ľ��

	SListRemove(&s1, 1);
	SListPrint(&s1);//�Ƴ�����ĳ��ֵ�Ľ��Ľ��
}
int main()
{
	TestSList();
	system("pause");
	return 0;
}