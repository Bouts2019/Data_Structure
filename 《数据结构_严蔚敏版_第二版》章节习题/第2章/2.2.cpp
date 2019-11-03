#include <iostream>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
using namespace std;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

Status InitList(LinkList& L)
{
	L = new LNode;
	if (!L) return OVERFLOW;
	L->next = NULL;
	return OK;
}

Status TailInsertList(LinkList& L, ElemType* arr, int len)
{
	LNode* r = L;
	LNode* s;
	while (r->next) r = r->next;
	for (int i = 0; i < len; i++)
	{
		s = new LNode;
		s->data = arr[i];
		s->next = NULL;
		r->next = s;
		r = s;
	}
	return OK;
}

void PrintList(LinkList& L)
{
	LNode* p = L->next;
	while (p)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << endl;
}

Status MergeList(LinkList& A, LinkList& B)
{
	LNode* pa = A->next, *pb = B->next, *pc = A;
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	if (pa) pc->next = pa;
	else pc->next = pb;
	return OK;
}

int main()
{
	LinkList LA, LB;
	InitList(LA);
	InitList(LB);
	ElemType arrA[5] = { 1, 2, 2, 3, 3 };
	ElemType arrB[5] = { 1, 2, 2, 3, 3 };
	TailInsertList(LA, arrA, 5);
	TailInsertList(LB, arrB, 5);
	PrintList(LA);
	PrintList(LB);
	MergeList(LA, LB);
	PrintList(LA);
	return 0;
}