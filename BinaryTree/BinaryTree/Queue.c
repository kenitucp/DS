#include"Queue.h"
#include<assert.h>
#include<stdbool.h>
void QueueInit(Queue* q)// 初始化队列
{
	assert(q);
	q->front = q->rear = NULL;
}
// 销毁队列
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
// 队尾入队列
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
// 队头出队列
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
// 获取队列中有效元素个数
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL ? 0 : 1;
}
// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// 获取队列队尾元素
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