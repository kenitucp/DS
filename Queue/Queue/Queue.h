#include<stdio.h>
#include<stdlib.h>
// ��ʽ�ṹ����ʾ����
typedef int QDataType;
typedef struct QNode
{
	struct QNode* next;
	QDataType data;
}QNode;
// ���еĽṹ
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;//��¼��������ЧԪ�ظ���
}Queue;
// ��ʼ������
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, QDataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
void Print(Queue* q);