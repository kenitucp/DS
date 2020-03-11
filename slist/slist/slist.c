#include"slist.h"


//����һ���µĽ��
SLNode* BuyNode(DataType data)
{
	SLNode *newNode = (SLNode*)malloc(sizeof(SLNode));
	if (NULL == newNode)
	{
		printf("����ڵ�ʧ��\n");
		assert(newNode);
	}

	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}
//β��
void SLPushBack( SLNode**head, DataType data)
{
	assert(head);//�����Ƿ����
	SLNode* newNode = BuyNode(data);
	if (NULL == *head)//�����Ƿ�Ϊ������û���κν�������
	{
		*head = newNode;//��һ�����Ĳ��뷽ʽ
	}
	else//����ǿ�
	{
		SLNode* tail = *head;
		while (tail->next)//1����ȥ�����������һ�����
		{
			tail = tail->next;
		}
		tail->next = newNode;//2�������½��
	}
}
//βɾ
void SLPopBack(SLNode**head)
{
	assert(head);//�����Ƿ����
	//�Ȼ�ͼ�������ǳ������
	//�ٻ�ͼ�������Ƿǳ���������߽�������
	if (NULL == *head)//1�������Ƿ�Ϊ������û���κν�������
		return;
    if ((*head)->next == NULL)//2��������ֻ��һ�����
	{
		free(*head);
		*head = NULL;
	}
	SLNode*prev = NULL;
	SLNode*cur = *head;
	//3���������ж����㣬����cur���ҵ����һ����㣬������cur����һ��λ��
	while (cur->next)
	{
		prev = cur;//����cur����һ��λ��
		cur = cur->next;
	}
	prev->next = cur->next;//����
	free(cur);//ɾ��
}

//ͷ��
void SLPushFront(SLNode**head, DataType data)
{
	assert(head);//�����Ƿ����
	SLNode*  newNode = BuyNode(data);
	newNode->next = *head;//1������Ϊ����������������ж���ڵ�--����
	*head = newNode;	 
}
//ͷɾ
void SLPopFront(SLNode**head)
{
	assert(head);//�����Ƿ����
	if (NULL == *head)//1�������Ƿ�Ϊ������û���κν�������
		return;
	if ((*head)->next == NULL)//2��������ֻ��һ�����
	{
		free(*head);
		*head = NULL;
	}
	SLNode* delNode = *head;//���βɾ�Ľ��
	*head = delNode->next;//����
	free(delNode);//ɾ��
}

//��POSλ�ú����data
void SLInsertAfter(SLNode*pos, int data)//����λ�ò���(���棩
{	
	SLNode* newNode = NULL;
	//�������
	if (NULL == pos)
		return ;
	newNode = BuyNode(data);
	newNode->next = pos->next;//��һ�����½ڵ����һ��λ��ָ��POS����һ��λ��
	pos->next = newNode;//�ڶ�����POS����һ��λ��ָ���½ڵ�
}
void SLErase(SLNode*pos)//����λ��ɾ��
{
	SLNode* delNode = NULL;
	//pos�����ڻ���pos����һ��λ��Ϊ��
	if (NULL == pos || NULL == pos->next)
		return;
	delNode = pos->next;
	pos->next = delNode->next;//������
	free(delNode);//��ɾ��
}
int SLSize(SLNode*head)
{
	int count = 0;
	SLNode *cur = head;//��������
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
	while (cur)//ͷɾ
	{
		*head = cur->next;//������
		free(cur);//��ɾ��
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
	SLNode *L = NULL;//��ʾl������ĵ�������һ��Ԫ�ض�û��
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
