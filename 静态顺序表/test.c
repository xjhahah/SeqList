#include "SeqList.h"

void Test2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	
}


int main()
{
	Test2();
	system("pause");
	return 0;
}
