#define _CRT_SECURE_NO_WARNINGS
/*   �������Ľ��������  */
# include <stdio.h>
# include <stdlib.h>
typedef int Etype;
typedef struct BiTNode  /* �����ṹ */
{
	Etype data;
	struct BiTNode *lch, *rch;
}BiTNode;
/* ����ԭ������ */
BiTNode *creat_bt1();
BiTNode *creat_bt2();
void inorder(BiTNode *p);
void numb(BiTNode *p);
BiTNode *t; int n, n0, n1, n2;
/*  ������ */
int main()
{
	char ch; int k;
	do {
		printf("\n\n\n");
		printf("\n\n     1. ��������������1 ");
		printf("\n\n     2. ��������������2");
		printf("\n\n     3. ����ݹ����������");
		printf("\n\n     4. �������н�����");
		printf("\n\n     5. ������������");
		printf("\n======================================");
		printf("\n     ����������ѡ�� (1,2,3,4,5,6)");  
		scanf("%d", &k);
		switch (k)
		{
		case 1:t = creat_bt1(); break; /*  ��������5�����������㷨 */
		case 2:t = creat_bt2(); break; /*  ���õݹ齨���������㷨   */
		case 3: { inorder(t);                /*  �����������     */
			printf("\n\n    ��س�����������");
				ch=getchar();
		} break;
		case 4: { n = 0; n0 = 0; n1 = 0; n2 = 0;  /* ȫ�ֱ�����0 */
			numb(t);
			printf("\n     ������������� n = %d", n);
			printf("\n     ������Ҷ�ӽ���� n0 = %d", n0);
			printf("\n     ��Ϊ1�Ľ���� n1 = %d", n1);
			printf("\n     ��Ϊ2�Ľ���� n2 = %d", n2);
			printf("\n\n   ��س�����������"); ch=getchar();
		} break;
		case 5: exit(0);
		} /*  switch  */
		printf("\n ----------------");
	} while (k >= 1 && k<5);
	printf("\n               �ټ���");
	printf("\n      ��س��������ء�"); ch = getchar();
} /* main */
  /* ���ö���������5 ������һά����V ���������� */
BiTNode *creat_bt1()
{
	BiTNode *t, *p, *v[20]; int i, j; Etype e; /* ����������i ����������e  */
	printf("\n i,data=?"); scanf("%d%d", &i, &e);
	while (i != 0 && e != 0)              /* �� i ,e��Ϊ0ʱ������ѭ��  */
	{
		p = (BiTNode *)malloc(sizeof(BiTNode));
		p->data = e; p->lch = NULL; p->rch = NULL;
		v[i] = p;
		if (i == 1) t = p;                      /* ���Ϊ1�Ľ���Ǹ� */
		else {
			j = i / 2;
			if (i % 2 == 0) v[j]->lch = p; /* ���Ϊż����������*/
			else   v[j]->rch = p;  /* ���Ϊ���������Һ���*/
		}
		printf("\n i,data=?"); scanf("%d%d", &i,&e);
	} 
	return(t);
} /* creat_bt1 */
  /* ģ������ݹ�������������������� */
BiTNode * creat_bt2()
{
	int e;
	BiTNode *t;
	printf("\n data="); scanf("%d", &e);
	if (e == 0) t = NULL;                  /* ����0ֵ���������½�� */
	else {
		t = (BiTNode *)malloc(sizeof(BiTNode));
		t->data = e;
		t->lch = creat_bt2();  /* ���ӻ����ָ��ֵ  */
		t->rch = creat_bt2();  /* �Һ��ӻ����ָ��ֵ  */
	}
	return(t);
} /* creat_bt2 */
  /* ����ݹ����������  */
void inorder(BiTNode *p)
{
	if (p) {
		inorder(p->lch);
		printf("%3d", p->data);
		inorder(p->rch);
	}
} /* inorder  */
//�������
void firstorder(BiTNode *p) {
	if (p) {
		printf("%3d", p->data);
		firstorder(p->lch);
		firstorder(p->rch);
	}
}
  /* ��������ݹ�����������ķ������������н����� */
  /* ���߿�������������������ݹ�����������������±�д��һ�κ��� */
void numb(BiTNode *p)
{
	if (p) {
		numb(p->lch);
		{ printf("%3d", p->data);
		n++;
		if (p->lch == NULL && p->rch == NULL) n0++;
		if ((p->lch == NULL && p->rch != NULL) ||(p->lch != NULL && p->rch == NULL)) n1++;
		if (p->lch != NULL && p->rch != NULL) n2++;
		} /*  �ѷ��ʵĹ��������� ʹ��n0��ͳ��û��������n1������������or������������n2�������������������*/
		numb(p->rch);
	}
} /* numb  */
void numb_first(BiTNode *p) {
	if (p) {
		printf("%3d", p->data);
		n++;
		if (p->lch == NULL&&p->rch == NULL) n0++;
		if ((p->lch == NULL && p->rch != NULL) || (p->lch != NULL && p->rch == NULL)) n1++;
		if (p->lch != NULL && p->rch != NULL) n2++;
		numb_first(p->lch);
		numb_first(p->rch);
	}
}//�������ͳ�ƽڵ�