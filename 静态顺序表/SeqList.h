#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_SIZE 10 
typedef unsigned int size_t;
typedef int DataType;

typedef struct SeqList
{
	DataType _array[MAX_SIZE];
	size_t  _size; // ˳�������ЧԪ�صĸ��� 
}SeqList, *PSeqList;

//typedef struct SeqList SeqList; 
void SeqListInit(PSeqList ps);
void SeqListPushBack(PSeqList ps, DataType data);
void SeqListPopBack(PSeqList ps);
void SeqListPushFront(PSeqList ps, DataType data);
void SeqListPopFront(PSeqList ps);
void SeqListInsert(PSeqList ps, size_t pos, DataType data); 
void SeqListErase(PSeqList ps, size_t pos);
int SeqListFind(PSeqList ps, DataType data);
void SeqListRemove(PSeqList ps, DataType data); 
void SeqListRemoveAll(PSeqList ps, DataType data);
int SeqListEmpty(PSeqList ps);
int SeqListSize(PSeqList ps); 
void PrintSeqList(PSeqList ps);
void BubbleSort(int* array, int size);
void SelectSort(int* array, int size); 
void SelectSort_OP(int* array, int size);

/////////////////////////////////////////////////// 
// .h 
// ��ʼ��˳��� 
void SeqListPrint(PSeqList  ps)
{
	size_t i = 0;
	assert(ps);
	for (; i < ps->_size;i--)
	{
		printf("%d", ps->_array[i]);
	}
	printf("\n");
}
void SeqListInit(PSeqList  ps)
{
	assert(ps);
	ps->_size = 0;
	memset(ps->_array, 0, sizeof(DataType)*MAX_SIZE);
}

// β�� 
void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	if (ps->_size >= MAX_SIZE)
	{
		printf("SeqList is full\n");
		return;
	}
	ps->_array[ps->_size++] = data;
}
// βɾ 
void SeqListPopBack(PSeqList ps)
{ 
	assert(ps);
	if (ps->_size == 0)
	{
		printf("SeqList is Empty\n");
		return;
	}
	ps->_size--;
}

// ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data)
{
	assert(ps);
	int end = 0;
	if (ps->_size >= MAX_SIZE)
	{
		printf("SeqList is full\n");
		return;
	}
	end = ps->_size - 1;
	while (end >= 0)
	{
		ps->_array[end + 1] = ps->_array[end];
		--end;
	}
	ps->_array[0] = data;
	ps->_size++;
}

// ͷɾ 
void SeqListPopFront(PSeqList ps)
{
	size_t begin = 1;
	assert(ps);
	if (ps->_size == 0)
	{
		printf("SeqList is Empty\n");
		return;
	}
	while (begin<ps->_size) 
	{
		ps->_array[begin-1] = ps->_array[begin];
		++begin; 
	}
	--ps->_size;
}

// ����λ���в���ֵΪdata��Ԫ�� 
void SeqListInsert(PSeqList ps, size_t pos, DataType data)
{
	size_t end = 0;
	assert(ps);
	assert(pos <= ps->_size);
	end = ps->_size - 1;
	while (end >= pos)
	{ 
		ps->_array[end + 1] = ps->_array[end];
		--end; 
	}
	ps->_array[pos] = data;
	++ps->_size;
}

// ɾ������λ���е�Ԫ�� 
void SeqListErase(PSeqList ps, size_t pos)
{
	assert(ps);
	size_t begin = pos + 1;
	if (ps->_size==0)
	{
		printf("SeqList is Empty\n");
		return;
	}
	assert(pos < ps->_size);
	while (begin<ps->_size)
	{
		ps->_array[begin - 1] = ps->_array[begin];
		++begin;
	}
	--ps->_size;
}

// ��˳����в���ֵΪdata��Ԫ�أ����ظ�Ԫ����˳����е��±� 
int SeqListFind(PSeqList ps, DataType data)
{
	size_t i = 0;
	assert(ps);
	while (ps)
	{
		if (ps->_array[i] == data)
		{
			return i;
		}
		i++;
	}
	return -1;
}

// ɾ��˳�����ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList ps, DataType data)
{
	SeqListErase(ps, SeqListFind(ps, data));
}

// ɾ��˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	int count = 0;
	size_t i = 0;
	assert(ps);
	for (; i < ps->_size; ++i)
	{
		if (ps->_array[i]==data)
			count++;
		else
			ps->_array[i - count] = ps->_array[i];
	}
	ps->_size -= count;
}

// �ж�˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps)
{
	if (ps->_size == 0)
	printf("SeqList is Empty\n");
	return 0;
}

// ��ȡ˳�����Ԫ�صĸ��� 
int SeqListSize(PSeqList ps)
{
	return (ps->_size);
}

///////////////////////////////////////////////////////////////////////////////////////////////////// 
// �������� 
// ��ӡ˳����е�Ԫ�� 
void PrintSeqList(PSeqList ps)
{
	size_t i;
	for (i = 0; i < ps->_size; i++)
	printf("%d\t", ps->_array[i]);
	printf("\n");
}

// ��ð�������˳����е�Ԫ�ؽ������� 
int Greater(int left, int right)//����
{
	return left > right;
}
int Less(int left, int right)//����
{
	return right > left;
}
typedef  int(*Com)(int left, int right);


void BubbleSort(int* array, int size,Com  Compare)
{
	assert(array);
	size_t tmp = 0; 
	int i = 0;
	int j = 0;
	
	for (; i < size-1; i++)
	{
		int IsChamge = 0;
		for (j=1; j < size-i; j++)
		{
			if (Compare(array[j + 1] , array[j]))
			{
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
				IsChamge = 1;
			}
		}
		if (!IsChamge)
			return;
	}
}

// ��ѡ�������˳����е�Ԫ�ؽ������� 
int Swap(int *x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return tmp;
}
void SelectSort(int* array, int size)
{
	int i = 0;
	int j = 0;
	int maxPos = 0;
	for (; i < size - 1;i++)
	{
		maxPos = 0;
		for (j = 1; j < size - i;j++)
		{
			if (array[maxPos] < array[j])
				maxPos = j;
		}
		if (maxPos != size - 1 - i)
		{
			Swap(&array[maxPos], &array[i]);
		}
	}
}

// ѡ�������Ż�---һ���ҳ������СԪ�����ڵ�λ�� 
//��BUG
void SelectSort_OP(int* array, int size)
{
	int begin = 0;
	int end = size - 1;
	int maxPos = 0;
	int minPos = 0;
	while (begin<=end)
	{
		int j = begin + 1;
		while (j < end)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
			if (array[minPos] > array[j])
				minPos = j;
			j++;
		}
	}
	if (maxPos != end)
		Swap(&array[maxPos], &array[end]);
	if (minPos != begin)
		Swap(&array[minPos], &array[begin]);
	begin++;
	end--;
}
