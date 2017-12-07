#define _CRT_SECURE_NO_WARNINGS
//ѭ�����У������е�˳��洢�ṹ��ʵ�֡�
#include <stdio.h> 
#include <stdlib.h> 
#define MAXSIZE 20                       /* ���������� */
typedef int ElemType;                    /* ����Ԫ������ */
typedef  struct
{
	ElemType  a[MAXSIZE];               /* һά�������� */
	int  front, rear;                 /* ͷ��βָ������  */
}SqQueue;                     /* ѭ�����еĽṹ������ */
SqQueue  Q1;
/*  ��������  */
void init_Q(SqQueue *Q);
void out_Q(SqQueue Q);
void EnQueue(SqQueue *Q, ElemType e);
ElemType DeQueue(SqQueue *Q);
/*  ������  */
main()
{
	int k; ElemType e, x; char ch;
	init_Q(&Q1);          /* ��ʼ��һ����ѭ������ */
	do {
		printf("\n\n\n");
		printf("\n\n     1. ����Ԫ��e������ ");
		printf("\n\n     2. ����һ��Ԫ�أ�������ֵ");
		printf("\n\n     3. ������������");
		printf("\n======================================");
		printf("\n     ����������ѡ�� (1,2,3)");
		scanf("%d", &k);
		switch (k)
		{
		case 1: { printf("\n ���� e=?"); scanf("%d", &e);
			EnQueue( &Q1, e); 
			out_Q(Q1);
		} break;
		case 2: { x = DeQueue(&Q1);
			printf("\n����Ԫ�� : %d", x);
			out_Q(Q1);
		} break;
		case 3: exit(0);
		} /*  switch  */
		printf("\n ----------------");
	} while (k >= 1 && k < 3);
	printf("\n               �ټ���");
	printf("\n        ��س��������ء�"); 
	ch = getch();
} /* main */

  /*  ��ʼ���ն���  */
void init_Q(SqQueue *Q) {
	Q->front = 0;
	Q->rear = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		Q->a[i] = 0;
	}
}
  /*  ������е�����  */
void out_Q(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("���п�");
	}
	else {
		printf("�����е�����Ϊ��\n");
		for (int i = Q.front; i != Q.rear; i = (i + 1 + MAXSIZE) % MAXSIZE) {
			printf("%d ", Q.a[i]);
		}

	}
	
}
  /*  �����޸Ķ���ͷ��βָ�� */

/*���Ӻ���  */
void EnQueue(SqQueue *Q, ElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		printf("��������");
		return;
	}
	else
	{
		Q->a[Q->rear] = e;
		Q->rear=(Q->rear+1)%MAXSIZE;
	}
}
/*  ���Ӻ��� */
ElemType DeQueue(SqQueue *Q) {
	if (Q->rear == Q->front) {
		printf("����Ϊ��");
		return 0;
	}
	else {
		ElemType tmp;
		tmp = Q->a[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
		return tmp;
	}
}