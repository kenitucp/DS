#include"Heap.h"
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType x = *p1;
	*p1 = *p2;
	*p2 = x;

}
void AdjustDown(HPDataType* a, size_t n, size_t parent)//向下调整前提：左右子树是小堆--建立小堆
{   //时间复杂度：log2 n
	size_t child = parent * 2 + 1;//child：标记parent中较小的孩子--原因：完全二叉树中一个孩子可能有左没有右
	while (child<n)//继续条件（想的是结束的条件）
	{
		if (child + 1 < n&&a[child + 1] < a[child])//先保证右孩子存在，再找俩个孩子中较小的孩子
			++child;//child指向小的孩子
		if (a[child] < a[parent])//孩子小于父亲则交换
		{
			Swap(&a[child], &a[parent]);
			parent = child;//继续向下走
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//void AdjustDown(HPDataType* a, size_t n, size_t parent)//向下调整 --建立大堆
//{
//	size_t child = parent * 2 + 1;
//	while (child<n)//继续条件（想的是结束的条件）
//	{
//		if (child + 1 < n&&a[child + 1] > a[child])
//			++child;//child指向大的孩子
//		if (a[child] >a[parent])//孩子大于父亲则交换
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;//继续向下走
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

void HeapInit(Heap* hp, HPDataType* a, int n)//堆的初始化
{
	//时间复杂度：n/2 * log2 n
	assert(hp);
	//1、先将a中元素放到堆的结构中
	//初始化堆的结构
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (NULL == hp->_a)
	{
		assert(0);
		return;
	}
	hp->_capacity = n;
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	//2、构建成小堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//n-1：是尾结点的下标--真正的向下调整：从倒数第一个非叶子结点开始
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
void HeapDestory(Heap* hp)//销毁堆
{
	assert(hp);
	if (hp->_a)
	{
		free(hp->_a);
	}
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;

}
void AdjustUp(HPDataType* a, size_t child)//向上调整--小堆
{
	int parent = (child - 1) / 2;//parent=(child-1)>>1;如果是*2用<<1
	//while (parent>=0)--错的很神奇，代码可以正常跑，逻辑上是不合适的（单用这个条件程序不会终止）会死循环又不会死循环，走else会break出来
	while (child>0)//继续条件（想的是结束的条件）
	{
		if (a[child] <a[parent])//孩子小于父亲则交换
		{
			Swap(&a[child], &a[parent]);
			//小的元素往上移动，可能会导致上层不满足堆的性质
			//要继续向上调整
			child = parent;//继续向上走
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//void AdjustUp(HPDataType* a, size_t child)//向上调整--大堆
//{
//	int parent = (child - 1) / 2;
//	while (child>0)//继续条件（想的是结束的条件）
//	{
//		if (a[child]>a[parent])//孩子大于父亲则交换
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;//继续向上走
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
void HeapPush(Heap* hp, HPDataType x)//用到向上调整算法  时间复杂度logn
{
	assert(hp);
	if (hp->_capacity == hp->_capacity)
	{
		//需要扩容
		size_t newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDataType)realloc(hp->_a, sizeof(HPDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size++] = x;
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap* hp)//堆头，堆尾交换，删堆尾。堆头，向下调整。时间复杂度logn
{
	assert(hp->_size > 0);
	//assert(hp);
	//if(HeapEmpty(hp)) return ;
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//保存堆尾元素，放到堆顶
	hp->_size--;//删除原堆顶元素
	AdjustDown(hp->_a, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)//返回堆顶元素
{
	assert(hp->_size > 0);
	return(hp->_a[0]);
}
int HeapSize(Heap* hp)//返回堆的大小
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)//判断堆是否为空
{
	assert(hp);
	return hp->_size == 0;
}
//// 堆排序 时间复杂度nlogn
//void HeapSort(int* a, int n)
//{
//	//升序 建大堆；降序 建小堆
//	//升序 建大堆
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
	printf("堆的大小为：%d\n", HeapSize(&hp));
	printf("堆顶元素为：%d\n", HeapTop(&hp));

	HeapPop(&hp);
	printf("堆的大小为：%d\n", HeapSize(&hp));
	printf("堆顶元素为：%d\n", HeapTop(&hp));

	HeapPush(&hp, 9);
	printf("堆的大小为：%d\n", HeapSize(&hp));
	printf("堆顶元素为：%d\n", HeapTop(&hp));

	HeapPush(&hp, 0);
	printf("堆的大小为：%d\n", HeapSize(&hp));
	printf("堆顶元素为：%d\n", HeapTop(&hp));
}
int main()
{
	TestHeap();
	return 0;
}