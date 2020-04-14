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
void InsertSort(int *a, int n)//ֱ�Ӳ�������--�ȶ�
{
	for (int i = 1; i<n ; ++i)
	{
		
		int tmp = a[i];
		int end = i-1;
		//�Ҵ�����Ԫ�ص�λ��
		while (end >= 0&&tmp<a[end])
		{
				a[end + 1] = a[end];
				end--;
		}
		//����Ԫ��
		a[end + 1] = tmp;
	}

}
void ShellSort(int *a, int n) //ϣ������--���ȶ�
{
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i<n; ++i)//�������潻����룬Ȼ�������ߡ�
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
void SelectSort(int *a, int n)  //ѡ������ 
{
	for (int i = 0; i < n - 1; i++)//�ܵ�����
	{
		int maxPos = 0;
		for (int j = 1; j < n - i; ++j)//�ҵ����Ԫ�ص�λ��
		{
			if (a[j]>a[maxPos])
				maxPos = j;
		}
		if (maxPos != n - i - 1)//���Ԫ�ز��������ڵ�λ�ã��������Ҳࣩ
		{
			swap(&a[maxPos], &a[n - 1- i]);
		}
	}
}
void SelectSort1(int *a, int n)  //ѡ������ 
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
void AdjustDown(int *a, int n, int parent)//�ѵ����µ�������� 
{
	int child = parent * 2 + 1;//���ȱ������--��Ϊ��ʵ��������ȫ����������ȫ�������п���������û���Һ���
	while (child<n)
	{
		if (child + 1<n&&a[child]<a[child + 1])//���������������ĺ���
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
void HeapSort(int *a, int n)//������ 
{
	//�����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//ѡ������
	int end = n - 1;
	while (end>0)//���ö�ɾ����˼����ж�����
	{
		swap(&a[0], &a[end]);//���Ѷ�Ԫ����������һ��Ԫ�ؽ��н���
		AdjustDown(a, end, 0);//�ԶѶ�Ԫ��Ӧ�����µ���
		--end;
	}
}
void BubbleSort(int *a, int n)//ð������ 
{
	int end = n;
	while (end>0)//����ð������
	{
		int ischange = 0;
		for (int i = 1; i<end; ++i)//����ð�ݷ�ʽ
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
int PartSort1(int *a, int left, int right)//����ָ�뷨 
{
	int key = a[right];
	int keyindex = right;
	while (left<right)
	{
		//left�Ҵ�right��С���ٽ������ұ�Ϊk,������ߣ����Ϊk���ұ����ߣ�
		while (left<right&&a[left] <= key)
			++left;
		while (left<right&&a[right] >= key)
			--right;

		swap(&a[left], &a[right]);
	}
	if (left!=right)//���ֱ��return��˵����׼ֵ����ֵ������С
	  swap(&a[left], &a[keyindex]);
	return left;
}
void QuickSort1(int *a, int left, int right)//����ָ�뷨
{
	if (left >= right)
		return;
	if (right - left + 1>10)
	{
		//ȡ��׼ֵ�����ջ�׼ֵ��������л���
		//�����ڶ�����ǰ��������
		int keyindex = PartSort1(a, left, right);
		QuickSort1(a, left, keyindex-1);
		QuickSort1(a, keyindex + 1, right);
	}
	else
		InsertSort(a + left, right - left + 1);//���������Ż���С����������ֱ�Ӳ���ʵ�� 
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
int PartSort2(int *a, int left, int right)//�ڿӷ�
{
	int key;
	int keyindex;
	int mid = GetmidIndex(a, left, right);//���������Ż�������ȡ��
	swap(&a[mid], &a[right]);
	key = a[right];
	keyindex = right;
	while (left<right)
	{
		while (left<right&&a[left] <= key)	//left�Ҵ󣬷ŵ��ұߵĿ�
		{
			++left;//left�Ҵ� 
		}
		a[right] = a[left];//��ֵ��left��Ϊ�¿� 
		while (left<right&&a[right] >= key)//right��С���ŵ���ߵĿ�
		{
			--right;//right��С 
		}
		a[left] = a[right];//��ֵ��right��Ϊ�¿� 
	}
	a[left] = key;
	return left;
}
void QuickSort2(int *a, int left, int right)//�ڿӷ�
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
		InsertSort(a + left, right - left + 1);//���������Ż���С������������ֱ�Ӳ���ʵ�� 
}
int PartSort3(int *a, int left, int right)//ǰ��ָ�뷨 
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
void QuickSort3(int *a, int left, int right)//ǰ��ָ�뷨
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
		InsertSort(a + left, right - left + 1);//���������Ż���С����������ֱ�Ӳ���ʵ�� 
}
void QuickSortNor(int *a, int size)//ѭ��ʵ��
{
	Stack s;
	StackInit(&s);
	//������������ջ
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
			//div�ǻ�׼ֵ
			//[left,div)��׼ֵ��ಿ��
			//[div+1,right)��׼ֵ�Ҳಿ��
			StackPush(&s, right);
			StackPush(&s,div+1);

			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}
void MergeData(int *a, int left, int mid, int right, int *tmp)//�鲢
//�鲢����//ȡ�� ������ ���� ����ȥ [left,mid],[mid+1,right]�鲢��tmp[left,right]
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
	//[left,mid],[mid+1,right] �Ȳ��
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
void MergeSortNor(int *a,int size)//�ݹ�ʵ�ֹ鲢����
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
				//����gap�仯��mid,right,����Խ��
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
void CountSort(int* a, int n)//��������
{
	int max = a[0];
	int min = a[0];
	//0��ͳ�����ݵķ�Χ--�����Ǳ���ģ�����û��������ݵķ�Χ���Ͳ���Ҫ��ͳ�Ʒ�Χ��
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
	//2����������ռ�
	int range = max - min + 1;
	int *countArray = (int*)malloc(sizeof(int)*range);//ͳ�ƴ��� 
	if (NULL == countArray)
	{
		assert(0);
		return;
	}
	memset(countArray, 0, sizeof(int)*range);//���¿��ٵ������ʼ��Ϊ0
	int i;
	//3��ͳ��ÿ��Ԫ�س��ֵĴ���
	for (i = 0; i < n; i++)//����ԭ����ͳ��ÿ�����ֳ��ֵĴ���
	{
		countArray[a[i] - min]++;
	}
	//4�������ݽ��л���
	int index = 0;//���� 
	for (i = 0; i < range; i++)//������Χ����ԭ�����������
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
	printf("ֱ�Ӳ���������Ϊ��\n");
	print(a, 9);
	ShellSort(a, 9);
	printf("ϣ��������Ϊ��\n");
	print(a, 9);
	SelectSort1(a, 9);
	printf("ѡ��������Ϊ��\n");
	print(a, 9);
	HeapSort(a, 9);
	printf("��������Ϊ��\n");
	print(a, 9);
	BubbleSort(a, 9);
	printf("ð��������Ϊ��\n");
	print(a, 9);
	QuickSort1(a,0, 9);
	printf("����������Ϊ��\n");
	print(a, 9);
	QuickSortNor(a, sizeof(a)/sizeof(a[0]));
	printf("��������ǵݹ���Ϊ��\n");
	print(a, 9);
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	printf("�鲢������Ϊ��\n");
	print(a, sizeof(a) / sizeof(a[0]));
	MergeSortNor(a, sizeof(a) / sizeof(a[0]));
	printf("�鲢����ǵݹ���Ϊ��\n");
	print(a, sizeof(a) / sizeof(a[0]));*/
	CountSort(a, sizeof(a) / sizeof(a[0]));
	printf("����������Ϊ��\n");
	print(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	Test();
	system("pause");
	return 0;
}