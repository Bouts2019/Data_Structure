#include <iostream>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
using namespace std;
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode, *DuLinkList;

Status InitDuList(DuLinkList& L)
{
	L = new DuLNode;
	if (!L) return OVERFLOW;
	L->next = L;
	L->prior = L;
	return OK;
}

Status TailInsertDuList(DuLinkList& L, ElemType* arr, int len)
{
	DuLNode* p = L, * s = NULL;
	while (p->next != L) p = p->next;
	for (int i = 0; i < len; i++)
	{
		s = new DuLNode;
		s->data = arr[i];
		s->next = p->next;
		p->next->prior = s;
		p->next = s;
		s->prior = p;
		p = s;
	}
	return OK;
}

Status ChangeDuNode(DuLNode* p)
{
	DuLNode* q = p->prior;
	p->prior = q->prior;
	q->prior->next = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;
	q->prior = p;
	return OK;
}

void PrintDuList(DuLinkList& L)
{
	DuLNode* p = L->next;
	while (p != L)
	{
		cout << p->data << "<->";
		p = p->next;
	}
	cout << endl;
}

void RPrintDuList(DuLinkList& L)
{
	DuLNode* p = L->prior;
	while (p != L)
	{
		cout << p->data << "<->";
		p = p->prior;
	}
	cout << endl;
}

int main()
{
	DuLinkList L;
	InitDuList(L);
	ElemType arr[5] = { 1, 2, 3, 4, 5 };
	TailInsertDuList(L, arr, 5);
	DuLNode* p = L->next->next->next;
	PrintDuList(L);
	ChangeDuNode(p);
	PrintDuList(L);

	return 0;
}