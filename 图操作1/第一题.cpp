
# include <stdio.h>
# include <stdlib.h>
# define MAX 20
typedef int VexType;
typedef  VexType Mgraph[MAX][MAX]; /* Mgraph�Ƕ�ά�������ͱ�ʶ�� */
								   /* ����ԭ������ */
void creat_mg(Mgraph G);
void out_mg(Mgraph G);
Mgraph G1;                         /*  G1���ڽӾ���Ķ�ά������  */
int n, e, v0;
/*  ������ */
int main()
{
	creat_mg(G1);
	out_mg(G1);
}/* main */
 /*  �����ڽӾ���  */
void creat_mg(Mgraph G)
{
	int i, j, k;
	printf("\n  n,e=?");
	scanf("%d%d", &n, &e);  /* ���붥����n������e */
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) G[i][j] = 0;
	/* ���������G[i][j]=0��ΪG[i][j]=32767�����*/
	for (k = 1; k <= e; k++)                                /* ��֯������ѭ��  */
	{
		printf("\n  vi,vj=?");
		scanf("%d%d", &i, &j);          /* ����һ���ߵ�����������i,j */
		G[i][j] = G[j][i] = 1;
		/* ����ͼ���ڽӾ����ǶԳƾ��� */
		/* �����������Ҫ����ߵ�Ȩֵw������G[i][j]=w */
	}
} /* creat_mg */
  /* �ڽӾ���������Ϊ�˼�������Ƿ���ȷ */
void out_mg(Mgraph G)
{
	int i, j, k;  char ch;
	for (i = 1; i <= n; i++)        /*  ����ԭ����� */
	{
		printf("\n ");
		for (j = 1; j <= n; j++) printf("%5d", G[i][j]);
	}
	/*  ��������ڵı� */
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (G[i][j] == 1)printf("\n ���ڱ�< %d,%d >", i, j);

}




