#include"Stack.h"
#include<assert.h>
#include<malloc.h>
// 初始化栈
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
		//申请新空间
		int newcapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType)* newcapacity);
		if (temp)
		{
          //拷贝元素
			/*memcpy(temp, ps->array, sizeof(DataType)*ps->capacity);*/
			for (int i = 0; i < ps->size; ++i)
				temp[i] = ps->array[i];
		}
		
		//释放旧空间
		free(ps->array);
		ps->array = temp;
		ps->capacity = newcapacity;
	}
}
// 入栈
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = data;
	ps->size++;
}
// 出栈
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return ;
	ps->size--;
}
// 获取栈顶元素
DataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->array[ps->size - 1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}
// 销毁栈
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