#pragma once
#include<stdio.h>
#include<stdlib.h>
//// �����Ƕ����ľ�̬ջ�Ľṹ��ʵ����һ�㲻ʵ�ã�����������Ҫʵ�������֧�ֶ�̬������ջ
//typedef int DataType;
//#define N 10
//typedef struct Stack
//{
//	DataType _a[N];
//	int _top; // ջ��
//}Stack;//--�ڱ�������Ҫ�õ�ջ��û�нṹ��ʱ����ʱʵ��ջ�ṹ--->���飺ʵ�־�̬ջ
// ֧�ֶ�̬������ջ
typedef int DataType;
typedef struct Stack
{
	DataType* array;
	int size; // ջ��
	int capacity; // ����
}Stack;
// ��ʼ��ջ
void StackInit(Stack* ps);
// ��ջ
void StackPush(Stack* ps, DataType data);
// ��ջ
void StackPop(Stack* ps);
// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps);
// ����ջ
void StackDestroy(Stack* ps);