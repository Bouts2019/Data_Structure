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
	LNode* r = L, *s = NULL;
	while (r->next) r = r->next;
	for (int i = 0; i < len; i++)
	{
		s = new LNode;
		s->next = NULL;
		s->data = arr[i];
		r->next = s;
		r = s;
	}
	return OK;
}

LNode* LocateElem(LinkList& L, ElemType e)
{
	LNode* p = L->next;
	while (p && p->data != e) p = p->next;
	return p;
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

int GetDiffSet(LinkList& A, LinkList& B)
{
	LNode* p = A , *s = NULL;
	int len = 0;
	while (p->next)
	{
		if (!LocateElem(B, p->next->data))
		{
			len++;
			p = p->next;
		}
		else
		{
			s = p->next;
			p->next = s->next;
			delete s;
		}
	}
	return len;
}

int main()
{
	LinkList A, B;
	InitList(A);
	InitList(B);
	ElemType arrA[5] = { 1, 2, 3, 4, 5 };
	ElemType arrB[5] = { 1, 2, 3, 4, 5 };
	TailInsertList(A, arrA, 5);
	TailInsertList(B, arrB, 5);
	PrintList(A);
	PrintList(B);
	cout << "A的长度：" << GetDiffSet(A, B) << endl;
	PrintList(A);
	return 0;
}