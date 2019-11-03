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
	LNode* p = L, * s = NULL;
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

LNode* FindMaxElem(LinkList& L)
{
	LNode* p = L->next;
	LNode* maxNode = NULL;
	while (p)
	{
		if (!maxNode || p->data >= maxNode->data)
			maxNode = p;
		p = p->next;
	}
	return maxNode;
}

int main()
{
	LinkList L;
	InitList(L);
	ElemType arr[5] = { 1, 2, 5, 4, 3 };
	TailInsertList(L, arr, 5);
	LNode* max = FindMaxElem(L);
	if (max)
		cout << "最大的结点的值为：" << max->data << endl;
	return 0;
}