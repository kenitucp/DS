#include"SeqList.h"

void SeqListInit(SeqList* ps)//初始化
{
	assert(ps);

	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}
void SeqListDestory(SeqList* ps)//销毁
{
	assert(ps);

	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = ps->_size = 0;
	}
}
void SeqListPrint(SeqList* ps)// 顺序表打印
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d--->", ps->_array[i]);
	}
	printf("\n");
}
void SeqListCheckCapacity(SeqList* ps)// 检查空间，如果满了，进行增容
{
	size_t newcapacity;
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		newcapacity = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;//三目运算符
		ps->_array = (DataType*)realloc(ps->_array, sizeof(DataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* ps, DataType x)//尾插
{
	assert(ps);
	SeqListCheckCapacity(ps);

	ps->_array[ps->_size] = x;
	ps->_size++;
}
void SeqListPushFront(SeqList* ps, DataType x)//头插
{
	size_t end;
	assert(ps);
	SeqListCheckCapacity(ps);
	end = ps->_size;
	while (end>0)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	ps->_array[0] = x;
	ps->_size++;
}
void SeqListPopBack(SeqList* ps)//尾删
{
	assert(ps&&ps->_size>0);
	--ps->_size;
}
void SeqListPopFront(SeqList* ps)//头删
{
	size_t start;
	assert(ps);
	start = 1;
	while (start<ps->_size)
	{
		ps->_array[start - 1] = ps->_array[start];
		++start;
	}
	ps->_size--;
}
void SeqListInsert(SeqList* ps, int pos, DataType x)//在列表pos位置插入x
{
	int end;
	assert(ps);
	SeqListCheckCapacity(ps);
	for (end = ps->_size - 1;end >= pos; end--)
	{
		ps->_array[end + 1] = ps->_array[end];//1.将顺序表中pos位置开始的元素往后挪一个位置，从后往前一个一个挪
	}
	//2.插入元素
	ps->_array[pos] = x;
	ps->_size++;
}
void SeqListErase(SeqList* ps, size_t pos)//删除列表中pos位置的值
{
	size_t start;
	assert(ps && pos<ps->_size);
	start = pos;
	while (start<ps->_size - 1)
	{
		ps->_array[start] = ps->_array[start + 1];
		++start;
	}
	ps->_size--;
}
size_t SeqListSize(SeqList* ps)//求顺序表的大小
{
	assert(ps);
	return ps->_size;
}
size_t SeqListFind(SeqList* ps, DataType x)//查找链表中是否有某值
{
	assert(ps);
	size_t i = 0;
	for (i; i<ps->_size; i++)
	{
		if (ps->_array[i] == x)
			printf("找到了，下标是：%d\n", i);
	}
	return -1;
}
DataType SeqListAt(SeqList* ps, size_t pos)//查找顺序表中pos位置的值
{
	assert(ps);
	return ps->_array[pos];
}
void test()
{
	SeqList s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);//尾插结果

	SeqListPushFront(&s1, 0);
	SeqListPushFront(&s1, 2);
	SeqListPushFront(&s1, 5);
	SeqListPrint(&s1);//头插结果

	SeqListPopBack(&s1);
	SeqListPrint(&s1);//尾删结果

	SeqListPopFront(&s1);
	SeqListPrint(&s1);//头删结果

	SeqListInsert(&s1, 0, 5);
	SeqListPrint(&s1);//在列表pos位置插入某值的结果

	SeqListErase(&s1, 3);
	SeqListPrint(&s1);//删除链表中pos位置的值

	printf("%d\n",SeqListSize(&s1));//求顺序表的大小

	SeqListFind(&s1, 3);//查找列表中是否有某值的结果

	printf("%d\n", SeqListAt(&s1, 0));//查找列表中pos位置的值
}
int main()
{
	test();
	return 0;
}