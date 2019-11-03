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
	LNode* s = NULL;
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

LNode* LocateElem(LinkList& L, ElemType e)
{
	LNode* p = L->next;
	while (p && p->data != e) p = p->next;
	return p;
}

Status MergeList(LinkList& A, LinkList& B)
{
	LNode* p = A;
	LNode* q = NULL;
	while (p->next)
	{
		if (LocateElem(B, p->next->data)) p = p->next;
		else
		{
			q = p->next;
			p->next = q->next;
			delete q;
		}
	}
	return OK;
}

int main()
{
	LinkList A, B;
	InitList(A);
	InitList(B);
	ElemType arrA[5] = { 1, 2, 3, 4, 5 };
	ElemType arrB[5] = { 2, 4, 5 ,7, 10};
	TailInsertList(A, arrA, 5);
	TailInsertList(B, arrB, 5);
	PrintList(A);
	PrintList(B);
	MergeList(A, B);
	PrintList(A);
	return 0;
}