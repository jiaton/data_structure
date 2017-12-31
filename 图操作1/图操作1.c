# include <stdio.h>
# include <stdlib.h>
# define MAX 20
typedef int VexType;
typedef  struct Vnode
{
	VexType data;
	struct Vnode *next;
}Vnode;                           /* Vnode�Ƕ���Ľ��ṹ */
typedef Vnode Lgraph[MAX];      /* Lgraph��һά�������ͱ�ʶ�� */
								/* ����ԭ������ */
void creat_L(Lgraph G);
void out_L(Lgraph G);
void dfsL(Lgraph G, int v);
int n, e, z, vis[MAX]; Lgraph Ga;                      /*  Ga���ڽ�����ı�ͷ������  */
													   /*  ������ */
void main()
{
	int v1, i; char ch;
	do {
		printf("\n\n     1. ���������ڽӾ���");
		printf("\n\n     2. ���������ڽӾ���");
		printf("\n\n     3. �����������ڽӾ���");
		printf("\n\n     4. ������������");
		printf("\n\n     ����������ѡ�� (1,2,3,4)");
		scanf("%d", &z);
		if (z == 1 || z == 2 || z == 3)
		{
			for (i = 0; i<MAX; i++) vis[i] = 0;     /*  ������ʵı�־����   */
			creat_L(Ga);                 /*   ����ͼ�ڽ�����Ga    */
			out_L(Ga);                 /*  ����ڽ�����Ga */
			printf("\n ");
			printf("��Ҫ��ʼ�����Ķ���v1=?");
			scanf("%d", &v1); dfsL(Ga, v1);
		}    /* �Ӷ���v1��ʼ����ͼGa����������ȱ��� */
		printf("\n======================================");
	} while (z == 1 || z == 2 || z == 3);
	printf("\n\n   ��س�����������"); ch = getchar();
}/* main */
 /* �����ڽ�����  */
void creat_L(Lgraph G)
{
	Vnode *p, *q;  int i, j, k;
	printf("���� n,e=?");
	scanf("%d,%d", &n, &e);
	for (i = 1; i <= n; i++)
	{
		G[i].data = i; G[i].next = NULL;
	}
	for (k = 1; k <= e; k++)
	{
		printf("���� vi,vj=?"); scanf("%d,%d", &i, &j);
		if (z == 1 || z == 3)
		{
			p = (Vnode *)malloc(sizeof(Vnode)); p->data = i;
			p->next = G[j].next; G[j].next = p;
		}   /* p������ӵ���j���� */
		if (z == 1 || z == 2)
		{
			q = (Vnode *)malloc(sizeof(Vnode));
			q->data = j;  q->next = G[i].next; G[i].next = q; /* q������ӵ���i����  */
		}
	}
}/*  creat_L */
 /*  �ڽ�����ļ������Ϊ�˼�������Ƿ���ȷ  */
void out_L(Lgraph G)
{
	int i; Vnode *p;
	for (i = 1; i <= n; i++)
	{
		printf("\n i=%d", i);        p = G[i].next;
		while (p != NULL) {
			printf("%5d", p->data);
			p = p->next;
		}
	}
} /* out_L */
  /* ������ȱ���ͼ */
void dfsL(Lgraph G, int v)
{
	Vnode *p;
	int u = 1;
	printf("%3d", G[v].data);  vis[v] = 1; /*  ����v�����ʣ���־��1 */
	p = G[v].next;
	while (p) {
		v = p->data; u++;
		if (vis[v] == 0)
			dfsL(G, v);  /* ����vδ������ʱ�������� */
		p = p->next;
	}
	if (u<n)
		for (v = 1; v <= n; v++)
			if (vis[v] != 1) { dfsL(G, v); break; }
	return;
}/* dfs  */
