#include"Heap.h"
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType x = *p1;
	*p1 = *p2;
	*p2 = x;

}
void AdjustDown(HPDataType* a, size_t n, size_t parent)//���µ���ǰ�᣺����������С��--����С��
{   //ʱ�临�Ӷȣ�log2 n
	size_t child = parent * 2 + 1;//child�����parent�н�С�ĺ���--ԭ����ȫ��������һ�����ӿ�������û����
	while (child<n)//��������������ǽ�����������
	{
		if (child + 1 < n&&a[child + 1] < a[child])//�ȱ�֤�Һ��Ӵ��ڣ��������������н�С�ĺ���
			++child;//childָ��С�ĺ���
		if (a[child] < a[parent])//����С�ڸ����򽻻�
		{
			Swap(&a[child], &a[parent]);
			parent = child;//����������
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//void AdjustDown(HPDataType* a, size_t n, size_t parent)//���µ��� --�������
//{
//	size_t child = parent * 2 + 1;
//	while (child<n)//��������������ǽ�����������
//	{
//		if (child + 1 < n&&a[child + 1] > a[child])
//			++child;//childָ���ĺ���
//		if (a[child] >a[parent])//���Ӵ��ڸ����򽻻�
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;//����������
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

void HeapInit(Heap* hp, HPDataType* a, int n)//�ѵĳ�ʼ��
{
	//ʱ�临�Ӷȣ�n/2 * log2 n
	assert(hp);
	//1���Ƚ�a��Ԫ�طŵ��ѵĽṹ��
	//��ʼ���ѵĽṹ
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (NULL == hp->_a)
	{
		assert(0);
		return;
	}
	hp->_capacity = n;
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	//2��������С��
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//n-1����β�����±�--���������µ������ӵ�����һ����Ҷ�ӽ�㿪ʼ
	{
		AdjustDown(hp->_a, hp->_size, i);
	}

}
void HeapPrint(Heap *hp)
{
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);

	}
	printf("\n");
}
void HeapDestory(Heap* hp)//���ٶ�
{
	assert(hp);
	if (hp->_a)
	{
		free(hp->_a);
	}
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;

}
void AdjustUp(HPDataType* a, size_t child)//���ϵ���--С��
{
	int parent = (child - 1) / 2;//parent=(child-1)>>1;�����*2��<<1
	//while (parent>=0)--��ĺ����棬������������ܣ��߼����ǲ����ʵģ���������������򲻻���ֹ������ѭ���ֲ�����ѭ������else��break����
	while (child>0)//��������������ǽ�����������
	{
		if (a[child] <a[parent])//����С�ڸ����򽻻�
		{
			Swap(&a[child], &a[parent]);
			//С��Ԫ�������ƶ������ܻᵼ���ϲ㲻����ѵ�����
			//Ҫ�������ϵ���
			child = parent;//����������
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//void AdjustUp(HPDataType* a, size_t child)//���ϵ���--���
//{
//	int parent = (child - 1) / 2;
//	while (child>0)//��������������ǽ�����������
//	{
//		if (a[child]>a[parent])//���Ӵ��ڸ����򽻻�
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;//����������
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
void HeapPush(Heap* hp, HPDataType x)//�õ����ϵ����㷨  ʱ�临�Ӷ�logn
{
	assert(hp);
	if (hp->_capacity == hp->_capacity)
	{
		//��Ҫ����
		size_t newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDataType)realloc(hp->_a, sizeof(HPDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size++] = x;
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap* hp)//��ͷ����β������ɾ��β����ͷ�����µ�����ʱ�临�Ӷ�logn
{
	assert(hp->_size > 0);
	//assert(hp);
	//if(HeapEmpty(hp)) return ;
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//�����βԪ�أ��ŵ��Ѷ�
	hp->_size--;//ɾ��ԭ�Ѷ�Ԫ��
	AdjustDown(hp->_a, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)//���ضѶ�Ԫ��
{
	assert(hp->_size > 0);
	return(hp->_a[0]);
}
int HeapSize(Heap* hp)//���ضѵĴ�С
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)//�ж϶��Ƿ�Ϊ��
{
	assert(hp);
	return hp->_size == 0;
}
//// ������ ʱ�临�Ӷ�nlogn
//void HeapSort(int* a, int n)
//{
//	//���� ����ѣ����� ��С��
//	//���� �����
//	for (int i = (n - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[end], &a[0]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
void TestHeap()
{
	int a[] = { 5, 3, 8, 4, 2, 7, 6, 1, 0 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	printf("�ѵĴ�СΪ��%d\n", HeapSize(&hp));
	printf("�Ѷ�Ԫ��Ϊ��%d\n", HeapTop(&hp));

	HeapPop(&hp);
	printf("�ѵĴ�СΪ��%d\n", HeapSize(&hp));
	printf("�Ѷ�Ԫ��Ϊ��%d\n", HeapTop(&hp));

	HeapPush(&hp, 9);
	printf("�ѵĴ�СΪ��%d\n", HeapSize(&hp));
	printf("�Ѷ�Ԫ��Ϊ��%d\n", HeapTop(&hp));

	HeapPush(&hp, 0);
	printf("�ѵĴ�СΪ��%d\n", HeapSize(&hp));
	printf("�Ѷ�Ԫ��Ϊ��%d\n", HeapTop(&hp));
}
int main()
{
	TestHeap();
	return 0;
}