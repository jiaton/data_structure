# include <stdio.h>
# include <stdlib.h>
# define MAX 20
typedef int VexType;
typedef  struct Vnode
{
	VexType data;
	struct Vnode *next;
}Vnode;                           /* Vnode是顶点的结点结构 */
typedef Vnode Lgraph[MAX];      /* Lgraph是一维数组类型标识符 */
								/* 函数原形声明 */
void creat_L(Lgraph G);
void out_L(Lgraph G);
void dfsL(Lgraph G, int v);
int n, e, z, vis[MAX]; Lgraph Ga;                      /*  Ga是邻接链表的表头数组名  */
													   /*  主函数 */
void main()
{
	int v1, i; char ch;
	do {
		printf("\n\n     1. 无向链表邻接矩阵");
		printf("\n\n     2. 有向链表邻接矩阵");
		printf("\n\n     3. 有向链表逆邻接矩阵");
		printf("\n\n     4. 结束程序运行");
		printf("\n\n     请输入您的选择 (1,2,3,4)");
		scanf("%d", &z);
		if (z == 1 || z == 2 || z == 3)
		{
			for (i = 0; i<MAX; i++) vis[i] = 0;     /*  顶点访问的标志数组   */
			creat_L(Ga);                 /*   建立图邻接链表Ga    */
			out_L(Ga);                 /*  输出邻接链表Ga */
			printf("\n ");
			printf("所要开始遍历的顶点v1=?");
			scanf("%d", &v1); dfsL(Ga, v1);
		}    /* 从顶点v1开始，对图Ga进行深度优先遍历 */
		printf("\n======================================");
	} while (z == 1 || z == 2 || z == 3);
	printf("\n\n   打回车键，继续。"); ch = getchar();
}/* main */
 /* 建立邻接链表  */
void creat_L(Lgraph G)
{
	Vnode *p, *q;  int i, j, k;
	printf("输入 n,e=?");
	scanf("%d,%d", &n, &e);
	for (i = 1; i <= n; i++)
	{
		G[i].data = i; G[i].next = NULL;
	}
	for (k = 1; k <= e; k++)
	{
		printf("输入 vi,vj=?"); scanf("%d,%d", &i, &j);
		if (z == 1 || z == 3)
		{
			p = (Vnode *)malloc(sizeof(Vnode)); p->data = i;
			p->next = G[j].next; G[j].next = p;
		}   /* p结点链接到第j条链 */
		if (z == 1 || z == 2)
		{
			q = (Vnode *)malloc(sizeof(Vnode));
			q->data = j;  q->next = G[i].next; G[i].next = q; /* q结点链接到第i条链  */
		}
	}
}/*  creat_L */
 /*  邻接链表的简单输出，为了检查输入是否正确  */
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
  /* 深度优先遍历图 */
void dfsL(Lgraph G, int v)
{
	Vnode *p;
	int u = 1;
	printf("%3d", G[v].data);  vis[v] = 1; /*  顶点v被访问，标志置1 */
	p = G[v].next;
	while (p) {
		v = p->data; u++;
		if (vis[v] == 0)
			dfsL(G, v);  /* 顶点v未被访问时继续遍历 */
		p = p->next;
	}
	if (u<n)
		for (v = 1; v <= n; v++)
			if (vis[v] != 1) { dfsL(G, v); break; }
	return;
}/* dfs  */
