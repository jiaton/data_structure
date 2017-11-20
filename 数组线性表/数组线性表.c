#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
	ElemType *data;
	int length;
}sqList;
int InitList(sqList *L);
int GetElem(sqList L, int i, ElemType *e);//将查到的数赋给e
int DelElem(sqList *L, int i,ElemType *e);
int ListInsert(sqList *L, int i, ElemType e);
int RePlaceElem(sqList *L, int i, ElemType e);
int main() {
	sqList L;
	InitList(&L);
	for (int i = 0; i < 20; i++) {
		ListInsert(&L,L.length+1,i);
	}
	for (int i = 0; i < L.length; i++) {
		printf(L.data[i]);
	}
}
int InitList(sqList *L) {
	L = (sqList*)malloc(sizeof(sqList)*MAXSIZE);
	L->length = 0;
}
int GetElem(sqList L, int i, ElemType *e) {
	if (i<1 || i>L.length) return -1;
	*e = L.data[i - 1];
	return 1;
}
int DelElem(sqList *L, int i, ElemType *e) {
	if (i > L->length || i < 1) return -1;
	*e = L->data[i - 1];
	for (int k = i - 1; k < L->length; k++) {
		L->data[k] = L->data[k + 1];
	}
	L->length--;
	return 1;
}
int ListInsert(sqList *L, int i, ElemType e) {
	if (i > L->length || i < 1) return -1;
	for (int k = L->length - 1; k > i; k--) {
		L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->length++;
	return 1;
}
int RePlaceElem(sqList *L, int i, ElemType e) {
	if (i > L->length || i < 1) return -1;
	L->data[i - 1] = e;
	return 1;
}