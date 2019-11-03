#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
using namespace std;
typedef struct
{
	ElemType* elem;
	int length;
}SqList;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) return OVERFLOW;
	L.length = 0;
	return OK;
}

Status TailInsertList(SqList& L, ElemType* arr, int len)
{
	for (int i = 0; i < len; i++)
		L.elem[L.length++] = arr[i];
	return OK;
}

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

int LocateElem(SqList& L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;
	return 0;
}

LNode* LocateElem(LinkList& L, ElemType e)
{
	LNode* p = L->next;
	while (p && p->data != e) p = p->next;
	return p;
} 

Status InsertList(SqList& L, int index, ElemType e)
{
	if (index < 1 || index > L.length + 1) return ERROR;
	for (int i = L.length - 1; i >= index - 1; i--)
		L.elem[i + 1] = L.elem[i];
	L.elem[index - 1] = e;
	L.length++;
	return OK;
}

Status InsertList(LinkList& L, int index, ElemType e)
{
	LNode* p = L, * s = NULL; int cnt = 0;
	while (p && cnt < index - 1)
	{
		p = p->next;
		cnt++;
	}
	if (!p || index < 1) return ERROR;
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

void PrintList(SqList& L)
{
	for (int i = 0; i < L.length; i++)
		cout << L.elem[i] << "->";
	cout << endl;
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

SqList GetIntersection(SqList& A, SqList& B)
{
	SqList L;
	InitList(L);
	for (int i = 0; i < A.length; i++)
		if (LocateElem(B, A.elem[i]))
			InsertList(L, L.length + 1, A.elem[i]);
	return L;
}

int GetLength(LinkList& L)
{
	LNode* p = L; int cnt = 0;
	while (p->next)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

LinkList GetIntersection(LinkList& A, LinkList& B)
{
	LinkList L;
	InitList(L);
	LNode* p = A;
	while (p->next)
	{
		if (LocateElem(B, p->next->data))
			InsertList(L, GetLength(L) + 1, p->next->data);
		p = p->next;
	}
	return L;
}

Status DelSameElem(SqList& L)
{
	for (int i = 0; i < L.length - 1; i++)
	{
		if (L.elem[i] == L.elem[i + 1])
		{
			for (int j = i + 1; j <= L.length - 2; j++)
			{
				L.elem[j] = L.elem[j + 1];
			}
			L.length--;
			i--;
		}
	}
	return OK;
}

Status DelSameElem(LinkList& L)
{
	LNode* p = L->next, * q = NULL;
	while (p->next)
	{
		if (p->next->data == p->data)
		{
			q = p->next;
			p->next = q->next;
			delete q;
		}
		else p = p->next;
	}
	return OK;
}

Status GetNoSameInterSection(SqList& A, SqList& B)
{
	DelSameElem(A);
	for (int i = 0; i < A.length; i++)
	{
		if (!LocateElem(B, A.elem[i]))
		{
			for (int j = i; j <= A.length - 1 - 1; j++)
				A.elem[j] = A.elem[j + 1];
			A.length--;
			i--;
		}
	}
	return OK;
}

Status GetNoSameInterSection(LinkList& A, LinkList& B)
{
	DelSameElem(A);
	LNode* p = A, * q = NULL;
	while (p->next)
	{
		if (!LocateElem(B, p->next->data))
		{
			q = p->next;
			p->next = q->next;
			delete q;
		}
		else p = p->next;
	}
	return OK;
}

int main()
{
	SqList A, B;
	ElemType arrA[8] = { 1, 2, 3, 3, 4, 4, 5, 5 };
	ElemType arrB[7] = { 3, 4, 5, 5, 6, 6, 7 };
	InitList(A);
	InitList(B);
	TailInsertList(A, arrA, 8);
	TailInsertList(B, arrB, 7);
	SqList resSq = GetIntersection(A, B);
	PrintList(resSq);
	cout << "=============" << endl;
	LinkList D, E;
	InitList(D);
	InitList(E);
	TailInsertList(D, arrA, 8);
	TailInsertList(E, arrB, 7);
	LinkList resLink = GetIntersection(D, E);
	PrintList(resLink);
	cout << endl;
	cout << "=============" << endl;
	PrintList(A);
	DelSameElem(A);
	PrintList(A);
	cout << endl;
	cout << "=============" << endl;
	PrintList(D);
	DelSameElem(D);
	PrintList(D);
	cout << endl;
	cout << "=============" << endl;
	GetNoSameInterSection(A, B);
	PrintList(A);
	cout << endl;
	cout << "=============" << endl;
	GetNoSameInterSection(D, E);
	PrintList(D);
	cout << endl;
	return 0;
}
