#include "SeqList.h"
//PushBack
void TestPushBack()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	 
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
}
void TestPushFront()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
}
void TestInsert()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);

	SeqListInsert(&s, 4, 5);
	SeqListInsert(&s, 2, 3);
	SeqListInsert(&s, 0, 0);
	SeqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListErase(&s, 3);
	SeqListErase(&s, 5);
}
void TestBubbleSort()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	
	BubbleSort(s._array,SeqListSize(&s),Greater);
	SeqListPrint(&s);
}
