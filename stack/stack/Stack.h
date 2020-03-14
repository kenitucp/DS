#pragma once
#include<stdio.h>
#include<stdlib.h>
//// 下面是定长的静态栈的结构，实际中一般不实用，所以我们主要实现下面的支持动态增长的栈
//typedef int DataType;
//#define N 10
//typedef struct Stack
//{
//	DataType _a[N];
//	int _top; // 栈顶
//}Stack;//--在笔试中需要用到栈而没有结构的时候，临时实现栈结构--->建议：实现静态栈
// 支持动态增长的栈
typedef int DataType;
typedef struct Stack
{
	DataType* array;
	int size; // 栈顶
	int capacity; // 容量
}Stack;
// 初始化栈
void StackInit(Stack* ps);
// 入栈
void StackPush(Stack* ps, DataType data);
// 出栈
void StackPop(Stack* ps);
// 获取栈顶元素
DataType StackTop(Stack* ps);
// 获取栈中有效元素个数
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps);
// 销毁栈
void StackDestroy(Stack* ps);