#include <iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;
typedef int ElemType;
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
	LNode* p = L, *s = NULL;
	while (p->next) p = p->next;
	for (int i = 0; i < len; i++)
	{
		s = new LNode;
		s->data = arr[i];
		s->next = NULL;
		p->next = s;
		p = s;
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

Status SplitList(LinkList& A, LinkList& B, LinkList& C)
{
	LNode* pa = A->next, * pb = B, * pc = C;
	while (pa)
	{
		if (pa->data < 0)
		{
			pb->next = pa;
			pb = pa;
			pa = pa->next;
			pb->next = NULL;
		}
		else if (pa->data > 0)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pc->next = NULL;
		}
	}
	return OK;
}

int main()
{
	LinkList A, B, C;
	InitList(A);
	InitList(B);
	InitList(C);
	ElemType arr[6] = { -3, -2, -1, 1, 2, 3 };
	TailInsertList(A, arr, 6);
	PrintList(A);
	SplitList(A, B, C);
	PrintList(B);
	PrintList(C);

	return 0;
}