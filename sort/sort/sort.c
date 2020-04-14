#include"sort.h"
void print(int *a, int n)
{
	int i;
	for (i = 0; i<n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int *a, int n)//直接插入排序--稳定
{
	for (int i = 1; i<n ; ++i)
	{
		
		int tmp = a[i];
		int end = i-1;
		//找待插入元素的位置
		while (end >= 0&&tmp<a[end])
		{
				a[end + 1] = a[end];
				end--;
		}
		//插入元素
		a[end + 1] = tmp;
	}

}
void ShellSort(int *a, int n) //希尔排序--不稳定
{
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i<n; ++i)//分组里面交替插入，然后往后走。
		{
			int end = i-gap;
			int tmp = a[i];
			while (end >= 0)
			{
				if (tmp<a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}
void swap(int* m, int *n)
{
	int tmp;
	tmp = *m;
	*m = *n;
	*n = tmp;
}
void SelectSort(int *a, int n)  //选择排序 
{
	for (int i = 0; i < n - 1; i++)//跑的趟数
	{
		int maxPos = 0;
		for (int j = 1; j < n - i; ++j)//找到最大元素的位置
		{
			if (a[j]>a[maxPos])
				maxPos = j;
		}
		if (maxPos != n - i - 1)//最大元素不在它该在的位置（区间最右侧）
		{
			swap(&a[maxPos], &a[n - 1- i]);
		}
	}
}
void SelectSort1(int *a, int n)  //选择排序 
{
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i]<a[min])
			{
				min = i;
			}
			if (a[i]>a[max])
			{
				max = i;
			}
		}
		swap(&a[begin], &a[min]);
		if (max == begin)
		{
			max = min;
		}
		swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}  
void AdjustDown(int *a, int n, int parent)//堆的向下调整建大堆 
{
	int child = parent * 2 + 1;//优先标记左孩子--因为堆实际上是完全二叉树，完全二叉树中可能有左孩子没有右孩子
	while (child<n)
	{
		if (child + 1<n&&a[child]<a[child + 1])//找俩个孩子中最大的孩子
			++child;
		if (a[child]>a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *a, int n)//堆排序 
{
	//建大堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//选数排序
	int end = n - 1;
	while (end>0)//利用堆删除的思想进行堆排序
	{
		swap(&a[0], &a[end]);//将堆顶元素与堆中最后一个元素进行交换
		AdjustDown(a, end, 0);//对堆顶元素应用向下调整
		--end;
	}
}
void BubbleSort(int *a, int n)//冒泡排序 
{
	int end = n;
	while (end>0)//控制冒泡趟数
	{
		int ischange = 0;
		for (int i = 1; i<end; ++i)//具体冒泡方式
		{
			if (a[i - 1]>a[i])
			{
				swap(&a[i - 1], &a[i]);
				ischange = 1;
			}
		}
		if (!ischange)
		{
			return;
		}
		--end;
	}
}
int PartSort1(int *a, int left, int right)//左右指针法 
{
	int key = a[right];
	int keyindex = right;
	while (left<right)
	{
		//left找大，right找小，再交换（右边为k,左边先走；左边为k，右边先走）
		while (left<right&&a[left] <= key)
			++left;
		while (left<right&&a[right] >= key)
			--right;

		swap(&a[left], &a[right]);
	}
	if (left!=right)//如果直接return，说明基准值左侧的值比它都小
	  swap(&a[left], &a[keyindex]);
	return left;
}
void QuickSort1(int *a, int left, int right)//左右指针法
{
	if (left >= right)
		return;
	if (right - left + 1>10)
	{
		//取基准值，按照基准值对区间进行划分
		//类似于二叉树前序遍历框架
		int keyindex = PartSort1(a, left, right);
		QuickSort1(a, left, keyindex-1);
		QuickSort1(a, keyindex + 1, right);
	}
	else
		InsertSort(a + left, right - left + 1);//快速排序优化：小区间有序：用直接插入实现 
}
int GetmidIndex(int *a, int left, int right)
{
	int mid;
	mid = left + (right - left) / 2;
	if (a[left]<a[mid])
	{
		if (a[mid]<a[right])
			return mid;
		else if (a[left]>a[right])
			return left;
		else
			return right;
	}
	else//a[left]>a[mid]
	{
		if (a[mid]>a[right])
			return mid;
		else if (a[left]<a[right])
			return left;
		else
			return right;
	}
}
int PartSort2(int *a, int left, int right)//挖坑法
{
	int key;
	int keyindex;
	int mid = GetmidIndex(a, left, right);//快速排序优化：三数取中
	swap(&a[mid], &a[right]);
	key = a[right];
	keyindex = right;
	while (left<right)
	{
		while (left<right&&a[left] <= key)	//left找大，放到右边的坑
		{
			++left;//left找大 
		}
		a[right] = a[left];//赋值，left作为新坑 
		while (left<right&&a[right] >= key)//right找小，放到左边的坑
		{
			--right;//right找小 
		}
		a[left] = a[right];//赋值，right作为新坑 
	}
	a[left] = key;
	return left;
}
void QuickSort2(int *a, int left, int right)//挖坑法
{
	if (left >= right)
		return;
	if (right - left + 1>10)
	{
		int keyindex = PartSort2(a, left, right);
		QuickSort2(a, left, keyindex - 1);
		QuickSort2(a, keyindex + 1, right);
	}
	else
		InsertSort(a + left, right - left + 1);//快速排序优化：小区间有序则用直接插入实现 
}
int PartSort3(int *a, int left, int right)//前后指针法 
{ 
	int key = a[right];
	int prev = left - 1;
	int cur = left;
	while (cur<right)
	{
		if (a[cur]<key&&++prev != cur)
			swap(&a[cur], &a[prev]);
		++cur;
	}
	++prev;
	swap(&a[right], &a[prev]);
	return prev;
}
void QuickSort3(int *a, int left, int right)//前后指针法
{
	if (left >= right)
		return;
	if (right - left + 1>10)
	{
		int keyindex = PartSort3(a, left, right);
		QuickSort3(a, left, keyindex - 1);
		QuickSort3(a, keyindex + 1, right);
	}
	else
		InsertSort(a + left, right - left + 1);//快速排序优化：小区间有序：用直接插入实现 
}
void QuickSortNor(int *a, int size)//循环实现
{
	Stack s;
	StackInit(&s);
	//将数据整体入栈
	StackPush(&s, size);
	StackPush(&s, 0);
	int left = 0, right = 0;
	while (!StackEmpty(&s))
	{
		int left = StackTop(&s);//left=0
		StackPop(&s);
		int right = StackTop(&s);//right=size
		StackPop(&s);
		if (right - left > 1)
		{
			int div = PartSort2(a, left, right-1);
			//div是基准值
			//[left,div)基准值左侧部分
			//[div+1,right)基准值右侧部分
			StackPush(&s, right);
			StackPush(&s,div+1);

			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}
void MergeData(int *a, int left, int mid, int right, int *tmp)//归并
//归并排序//取数 归下来 排序 拷回去 [left,mid],[mid+1,right]归并到tmp[left,right]
{
	int begin1 = left, end1 = mid;
	int begin2 = mid , end2 = right;
	int i = left;
	while (begin1 < end1&&begin2 < end2)
	{
		if (a[begin1]<=a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 < end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 < end2)
	{
		tmp[i++] = a[begin2++];
	}	
}
void _MergeSort(int *a,int left,int right,int*tmp)
{
	if (right - left > 1)
	{
	int mid = left + (right - left) / 2;
	//[left,mid],[mid+1,right] 先拆分
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid , right, tmp);
	MergeData(a, left, mid, right, tmp);
	memcpy(a + left, tmp + left, sizeof(a[0])*(right - left));
	}
}
void MergeSort(int *a, int n)
{
	int *tmp = (int*)malloc(sizeof(a[0])*n);
	if (NULL == tmp)
	{
		assert(0);
		return ;
     }
	_MergeSort(a, 0, n, tmp);
	free(tmp);
}
void MergeSortNor(int *a,int size)//递归实现归并排序
{
	int gap = 1;
	int *tmp = (int*)malloc(sizeof(a[0])*size);
	if (NULL == tmp)
	{
		assert(0);
      return ;
	}
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
			{
				int left = i;
				int mid = left + gap;
				int right = mid + gap;
				//随着gap变化，mid,right,可能越界
				if (mid>size)
					mid = size;
				if (right>size)
					right = size;
				MergeData(a, left, mid, right, tmp);
			}
		memcpy(a, tmp, size*sizeof(a[0]));
		gap <<=1;
	}
	free(tmp);
}
void CountSort(int* a, int n)//计数排序
{
	int max = a[0];
	int min = a[0];
	//0、统计数据的范围--并不是必须的（如果用户告诉数据的范围，就不需要来统计范围！
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	//2、申请计数空间
	int range = max - min + 1;
	int *countArray = (int*)malloc(sizeof(int)*range);//统计次数 
	if (NULL == countArray)
	{
		assert(0);
		return;
	}
	memset(countArray, 0, sizeof(int)*range);//把新开辟的数组初始化为0
	int i;
	//3、统计每个元素出现的次数
	for (i = 0; i < n; i++)//遍历原数组统计每个数字出现的次数
	{
		countArray[a[i] - min]++;
	}
	//4、对数据进行回收
	int index = 0;//排序 
	for (i = 0; i < range; i++)//遍历范围，对原数组进行排序
	{
		while (countArray[i]--)
		{
			a[index] = i + min;
			index++;
		}
	}
	free(countArray);
}
void Test()
{
	int a[] = { 2, 5, 1, 8, 6, 9, 3, 4, 7,4,6,7,8,2,1 };
	/*InsertSort(a, 9);
	printf("直接插入排序结果为：\n");
	print(a, 9);
	ShellSort(a, 9);
	printf("希尔排序结果为：\n");
	print(a, 9);
	SelectSort1(a, 9);
	printf("选择排序结果为：\n");
	print(a, 9);
	HeapSort(a, 9);
	printf("堆排序结果为：\n");
	print(a, 9);
	BubbleSort(a, 9);
	printf("冒泡排序结果为：\n");
	print(a, 9);
	QuickSort1(a,0, 9);
	printf("快速排序结果为：\n");
	print(a, 9);
	QuickSortNor(a, sizeof(a)/sizeof(a[0]));
	printf("快速排序非递归结果为：\n");
	print(a, 9);
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	printf("归并排序结果为：\n");
	print(a, sizeof(a) / sizeof(a[0]));
	MergeSortNor(a, sizeof(a) / sizeof(a[0]));
	printf("归并排序非递归结果为：\n");
	print(a, sizeof(a) / sizeof(a[0]));*/
	CountSort(a, sizeof(a) / sizeof(a[0]));
	printf("计数排序结果为：\n");
	print(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	Test();
	system("pause");
	return 0;
}