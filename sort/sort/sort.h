#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"stack.h"
void InsertSort(int *a, int n);//直接插入排序 
void ShellSort(int *a, int n); //希尔排序 
void SelectSort(int *a, int n); //选择排序 
void HeapSort(int *a, int n);//堆排序
void BubbleSort(int *a, int n);//冒泡排序 
void QuickSort1(int *a, int left, int right);//快速排序--左右指针法
void print(int *a, int n);//打印数组