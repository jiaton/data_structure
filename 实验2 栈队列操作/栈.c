#include <stdio.h> 
#include <stdlib.h> 
#include"stdafx.h"
#define MAXSIZE 20                       /* ���������� */
typedef int ElemType;                    /* ����Ԫ������ */
typedef  struct
{
	ElemType  a[MAXSIZE];               /* һά�������� */
	int  top;                        /* ջ��ָ������    */
}SqStack;							 /* ջ��˳��ṹ������ */
SqStack  s1;						/*  ��������  */
void init_s(SqStack *s);			/*  ��ʼ����ջ  */
void out_s(SqStack s);				/*  ���ջ������  */
void push(SqStack *s, ElemType e);	/*  ��ջ����  */
ElemType pop(SqStack *s);			/*  ��ջ���� */

main()
{
	int k;  
	ElemType e, x; 
	char ch;
	init_s(&s1);          /* ��ʼ��һ����ջ */
	do {
		printf("\n\n\n");
		printf("\n\n     1. ����Ԫ��e��ջ ");
		printf("\n\n     2. ��ջһ��Ԫ�أ�������ֵ");
		printf("\n\n     3. ������������");
		printf("\n======================================");
		printf("\n     ����������ѡ�� (1,2,3)");
		scanf("%d", &k);
		switch (k)
		{
		case 1: { printf("\n ��ջ e=?"); scanf("%d", &e);
			push(&s1, e); out_s(s1);
		} break;
		case 2: {   x = pop(&s1);
			printf("\n��ջԪ�� : %d", x);
			out_s(s1);
		} break;
		case 3: exit(0);
		} /*  switch  */
		printf("\n ----------------");
	} while (k >= 1 && k < 3);
	printf("\n               �ټ���");
	printf("\n        ��س��������ء�");
	ch = getch();
} /* main */

  /*  ��ʼ����ջ  */
void init_s(SqStack *s) {
	for (int i = 0; i < MAXSIZE; i++) {
		s->a[i] = 0;
	}
	s->top = -1;
}

  /*  ���ջ������  */
void out_s(SqStack s) {
	for (int i = s.top; i >=0; i--) {
		printf("%d", s.a[i]);
	}
}
  /*  ��ջ����  */
void push(SqStack *s, ElemType e) {
	if (s->top == MAXSIZE - 1) {
		printf("ջ��");
		return;
	}
	s->a[++(s->top)] = e;
}
  /*  ��ջ���� */
ElemType pop(SqStack *s) {
	if (s->top == -1) {
		printf("ջΪ��");
		return;
	}
	return(s->a[(s->top)--]);
}