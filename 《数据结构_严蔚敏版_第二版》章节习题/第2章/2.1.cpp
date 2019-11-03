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

Status MergeList(LinkList& A, LinkList& B)
{
	LNode* PA = A->next; LNode* PB = B->next; LNode* PC = A;
	while (PA && PB)
	{
		if (PA->data < PB->data)
		{
			PC->next = PA;
			PC = PA;
			PA = PA->next;
		}
		else if (PA->data > PB->data)
		{
			PC->next = PA;
			PC = PA;
			PA = PA->next;
		}
		else
		{
			PC->next = PA;
			PC = PA;
			PA = PA->next;
			LNode* p = PB;
			PB = PB->next;
			delete p;
		}
	}
	if (PA) PC->next = PA;
	else if (PB) PC->next = PB;
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

int main()
{
	LinkList LA, LB;
	InitList(LA);
	InitList(LB);
	ElemType arrA[5] = { 1, 2, 3, 4, 5 };
	ElemType arrB[5] = { 3, 4, 5, 6, 7 };
	TailInsertList(LA, arrA, 5);
	TailInsertList(LB, arrB, 5);
	PrintList(LA);
	cout << endl;
	PrintList(LB);
	cout << endl;
	MergeList(LA, LB);
	PrintList(LA);
	cout << endl;
	return 0;
}

