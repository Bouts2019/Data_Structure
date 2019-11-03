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
	LNode* r = L, * s = NULL;
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
}

Status DelRangeElem(LinkList& L, ElemType mink, ElemType maxk)
{
	LNode* p = L, * q = NULL;
	while (p->next)
	{
		if (p->next->data > mink && p->next->data < maxk)
		{
			q = p->next;
			p->next = q->next;
			delete q;
		}
		else
			p = p->next;
	}
	return OK;
}

int main()
{
	LinkList L;
	InitList(L);
	ElemType arr[5] = { 1, 2, 3, 4, 5 };
	TailInsertList(L, arr, 5);
	DelRangeElem(L, 1, 5);
	PrintList(L);
	cout << endl;
	return 0;
}