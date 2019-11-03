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
	int len;
}SqList;

Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) return OVERFLOW;
	L.len = 0;
	return OK;
}

Status TailInsertList(SqList& L, ElemType* arr, int len)
{
	for (int i = 0; i < len; i++)
		L.elem[L.len++] = arr[i];
	return OK;
}

void PrintList(SqList& L)
{
	for (int i = 0; i < L.len; i++)
		cout << L.elem[i] << "->";
	cout << endl;
}

Status DelAll(SqList& L, ElemType e)
{
	int len = L.len;
	int idx = 0;
	for (int i = 0; i < len; i++)
		if (L.elem[i] == e) L.len--;
		else L.elem[idx++] = L.elem[i];
	
	return OK;
}

int main()
{
	SqList L;
	InitList(L);
	ElemType arr[10] = { 0, 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	TailInsertList(L, arr, 10);
	PrintList(L);
	DelAll(L, 2);
	PrintList(L);
	return 0;
}