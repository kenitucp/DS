#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"stack.h"
void InsertSort(int *a, int n);//ֱ�Ӳ������� 
void ShellSort(int *a, int n); //ϣ������ 
void SelectSort(int *a, int n); //ѡ������ 
void HeapSort(int *a, int n);//������
void BubbleSort(int *a, int n);//ð������ 
void QuickSort1(int *a, int left, int right);//��������--����ָ�뷨
void print(int *a, int n);//��ӡ����