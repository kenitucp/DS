#pragma once//��ֹ��չ�����
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

// ��̬˳���--��̬����
//#define N 100
//typedef int DataType;
//struct SeqList
//{
//   SLDataType array[N]; // ��������
//   size_t size; // ��Ч���ݵĸ���
//};

//��̬˳���
typedef int DataType;
typedef struct SeqList
{
	DataType* _array; //��������
	size_t _size; // ��Ч���ݵĸ���
	size_t _capacity;//�����ռ�Ĵ�С
}SeqList;

void SeqListInit(SeqList* ps);// ˳����ʼ��
void SeqListDestory(SeqList* ps);// ˳�������
void SeqListPrint(SeqList* ps);// ˳����ӡ
void SeqListCheckCapacity(SeqList* ps);// ���ռ䣬������ˣ���������
void SeqListPushBack(SeqList* ps, DataType x);//β��
void SeqListPushFront(SeqList* ps, DataType x);//ͷ��
void SeqListPopBack(SeqList* ps);//βɾ
void SeqListPopFront(SeqList* ps);//ͷɾ
void SeqListInsert(SeqList* ps, size_t pos, DataType x);// ˳�����posλ�ò���x
void SeqListErase(SeqList* ps, size_t pos);// ˳���ɾ��posλ�õ�ֵ
size_t SeqListSize(SeqList* ps);//��˳���Ĵ�С
size_t SeqListFind(SeqList* ps, DataType x);//�����������Ƿ���ĳԪ��
DataType SeqListAt(SeqList* ps, size_t pos);//����˳�����posλ�õ�ֵ
