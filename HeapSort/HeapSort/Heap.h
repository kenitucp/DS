#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
typedef int HPDataType;
typedef struct Heap//堆支持动态增长--插入、删除数据
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);//堆的初始化
void AdjustUp(HPDataType* a, size_t child);//向上调整
void AdjustDown(HPDataType* a, size_t n, size_t parent);//向下调整
void HeapPush(Heap* hp, HPDataType x);//堆的插入
void HeapPop(Heap* hp);//堆的删除
HPDataType HeapTop(Heap* hp);//返回堆顶元素
int HeapSize(Heap* hp);//返回堆的大小
int HeapEmpty(Heap* hp);//判断堆是否为空
void HeapSort(int* a, int n);// 堆排序
void HeapDestory(Heap* hp);//销毁堆
void TestHeap();