#include"Stack.h"
#include<assert.h>
#include<malloc.h>
// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType)*10);
	ps->capacity = 10;
	ps->size = 0;
}
void CheckCapacity(Stack* ps)
{
	if (ps->size >= ps->capacity)
	{
		//�����¿ռ�
		int newcapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType)* newcapacity);
		if (temp)
		{
          //����Ԫ��
			/*memcpy(temp, ps->array, sizeof(DataType)*ps->capacity);*/
			for (int i = 0; i < ps->size; ++i)
				temp[i] = ps->array[i];
		}
		
		//�ͷžɿռ�
		free(ps->array);
		ps->array = temp;
		ps->capacity = newcapacity;
	}
}
// ��ջ
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = data;
	ps->size++;
}
// ��ջ
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return ;
	ps->size--;
}
// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->array[ps->size - 1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}
// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}
void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	printf("stack size:%d\n", StackSize(&s));
	printf("stack top:%d\n", StackTop(&s));
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	printf("stack size:%d\n", StackSize(&s));
	printf("stack top:%d\n", StackTop(&s));

	StackDestroy(&s);
}
int main()
{
	TestStack();
	return 0;
}