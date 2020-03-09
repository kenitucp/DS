#pragma once//防止被展开多次
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

// 静态顺序表--静态数组
//#define N 100
//typedef int DataType;
//struct SeqList
//{
//   SLDataType array[N]; // 定长数组
//   size_t size; // 有效数据的个数
//};

//动态顺序表
typedef int DataType;
typedef struct SeqList
{
	DataType* _array; //定长数组
	size_t _size; // 有效数据的个数
	size_t _capacity;//容量空间的大小
}SeqList;

void SeqListInit(SeqList* ps);// 顺序表初始化
void SeqListDestory(SeqList* ps);// 顺序表销毁
void SeqListPrint(SeqList* ps);// 顺序表打印
void SeqListCheckCapacity(SeqList* ps);// 检查空间，如果满了，进行增容
void SeqListPushBack(SeqList* ps, DataType x);//尾插
void SeqListPushFront(SeqList* ps, DataType x);//头插
void SeqListPopBack(SeqList* ps);//尾删
void SeqListPopFront(SeqList* ps);//头删
void SeqListInsert(SeqList* ps, size_t pos, DataType x);// 顺序表在pos位置插入x
void SeqListErase(SeqList* ps, size_t pos);// 顺序表删除pos位置的值
size_t SeqListSize(SeqList* ps);//求顺序表的大小
size_t SeqListFind(SeqList* ps, DataType x);//查找链表中是否有某元素
DataType SeqListAt(SeqList* ps, size_t pos);//查找顺序表中pos位置的值
