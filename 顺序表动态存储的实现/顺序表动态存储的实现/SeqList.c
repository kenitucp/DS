#include"SeqList.h"

void SeqListInit(SeqList* ps)//��ʼ��
{
	assert(ps);

	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}
void SeqListDestory(SeqList* ps)//����
{
	assert(ps);

	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = ps->_size = 0;
	}
}
void SeqListPrint(SeqList* ps)// ˳����ӡ
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d--->", ps->_array[i]);
	}
	printf("\n");
}
void SeqListCheckCapacity(SeqList* ps)// ���ռ䣬������ˣ���������
{
	size_t newcapacity;
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		newcapacity = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;//��Ŀ�����
		ps->_array = (DataType*)realloc(ps->_array, sizeof(DataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* ps, DataType x)//β��
{
	assert(ps);
	SeqListCheckCapacity(ps);

	ps->_array[ps->_size] = x;
	ps->_size++;
}
void SeqListPushFront(SeqList* ps, DataType x)//ͷ��
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
void SeqListPopBack(SeqList* ps)//βɾ
{
	assert(ps&&ps->_size>0);
	--ps->_size;
}
void SeqListPopFront(SeqList* ps)//ͷɾ
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
void SeqListInsert(SeqList* ps, int pos, DataType x)//���б�posλ�ò���x
{
	int end;
	assert(ps);
	SeqListCheckCapacity(ps);
	for (end = ps->_size - 1;end >= pos; end--)
	{
		ps->_array[end + 1] = ps->_array[end];//1.��˳�����posλ�ÿ�ʼ��Ԫ������Ųһ��λ�ã��Ӻ���ǰһ��һ��Ų
	}
	//2.����Ԫ��
	ps->_array[pos] = x;
	ps->_size++;
}
void SeqListErase(SeqList* ps, size_t pos)//ɾ���б���posλ�õ�ֵ
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
size_t SeqListSize(SeqList* ps)//��˳���Ĵ�С
{
	assert(ps);
	return ps->_size;
}
size_t SeqListFind(SeqList* ps, DataType x)//�����������Ƿ���ĳֵ
{
	assert(ps);
	size_t i = 0;
	for (i; i<ps->_size; i++)
	{
		if (ps->_array[i] == x)
			printf("�ҵ��ˣ��±��ǣ�%d\n", i);
	}
	return -1;
}
DataType SeqListAt(SeqList* ps, size_t pos)//����˳�����posλ�õ�ֵ
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
	SeqListPrint(&s1);//β����

	SeqListPushFront(&s1, 0);
	SeqListPushFront(&s1, 2);
	SeqListPushFront(&s1, 5);
	SeqListPrint(&s1);//ͷ����

	SeqListPopBack(&s1);
	SeqListPrint(&s1);//βɾ���

	SeqListPopFront(&s1);
	SeqListPrint(&s1);//ͷɾ���

	SeqListInsert(&s1, 0, 5);
	SeqListPrint(&s1);//���б�posλ�ò���ĳֵ�Ľ��

	SeqListErase(&s1, 3);
	SeqListPrint(&s1);//ɾ��������posλ�õ�ֵ

	printf("%d\n",SeqListSize(&s1));//��˳���Ĵ�С

	SeqListFind(&s1, 3);//�����б����Ƿ���ĳֵ�Ľ��

	printf("%d\n", SeqListAt(&s1, 0));//�����б���posλ�õ�ֵ
}
int main()
{
	test();
	return 0;
}