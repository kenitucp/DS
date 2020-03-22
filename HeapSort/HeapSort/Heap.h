#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
typedef int HPDataType;
typedef struct Heap//��֧�ֶ�̬����--���롢ɾ������
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);//�ѵĳ�ʼ��
void AdjustUp(HPDataType* a, size_t child);//���ϵ���
void AdjustDown(HPDataType* a, size_t n, size_t parent);//���µ���
void HeapPush(Heap* hp, HPDataType x);//�ѵĲ���
void HeapPop(Heap* hp);//�ѵ�ɾ��
HPDataType HeapTop(Heap* hp);//���ضѶ�Ԫ��
int HeapSize(Heap* hp);//���ضѵĴ�С
int HeapEmpty(Heap* hp);//�ж϶��Ƿ�Ϊ��
void HeapSort(int* a, int n);// ������
void HeapDestory(Heap* hp);//���ٶ�
void TestHeap();