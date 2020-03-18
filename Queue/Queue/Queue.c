#include"Queue.h"
#include<assert.h>
void QueueInit(Queue* q)// ��ʼ������
{
	assert(q);
	q->front = q->rear = NULL;
}
// ���ٶ���
void QueueDestory(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->rear = NULL;
}

QNode* BuyQueueNode(QDataType x)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = x;
	node->next = NULL;
	return node;
}
// ��β�����
void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	if (q->front == NULL)
	{
		q->front = q->rear = BuyQueueNode(x);
	}
	else
	{
		q->rear->next = BuyQueueNode(x);
		q->rear = q->rear->next;
	}
}
// ��ͷ������
void QueuePop(Queue* q)
{
	if (q->front)
	{
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;

		if (q->front == NULL)
		{
			q->rear = NULL;
		}
	}
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QNode* cur = q->front;
	while (cur)
	{
		++size;
		cur = cur->next;
	}

	return size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL ? 0 : 1;
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);

	return q->rear->data;
}
void Print(Queue* q)
{
	QNode *p = q->front;
	while (p)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("\n");
}
void test()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	QueuePush(&q1, 5);
	Print(&q1);//����н��

	QueuePop(&q1);
	Print(&q1);//�����н��

	printf("����ͷ��Ԫ��Ϊ��%d\n", (QueueFront(&q1)));
	printf("����β��Ԫ��Ϊ��%d\n", (QueueBack(&q1)));
	printf("��������ЧԪ�ظ���Ϊ��%d\n", (QueueSize(&q1)));

	// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
	printf("����Ϊ����ʾ0����Ȼ��ʾ1��%d",QueueEmpty(&q1));
}
int main()
{
	test();
	system("pause");
	return 0;
}