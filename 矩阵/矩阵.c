#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
/*  �������� */
int index(char *s, char *t, int pos);
void replace(char *s, char *t, char *v);
void chengfa();
void zhuanzhi();
/*  ������ */
main()
{
	int k; char *s, t[] = "abc", *v = "%%%";
	s = (char *)malloc(100 * sizeof(char));
	printf("\n s=?"); gets(s);  printf("\n s=%s\n", s);
	printf("\n t=%s    v=%s\n", t, v);
	replace(s, t, v);                  /* ���ô��û����� */
	printf("\n\n new string=%s\n", s);

	int w;
	printf("1����˷�\n");
	printf("2����ת��\n");
	printf("\n");
	printf("��ѡ��Ҫ���е����㣺");
	scanf("%d", &w);
	switch (w)
	{
	case 1:chengfa(); break;
	case 2:zhuanzhi(); break;

	}

}  /* main   */
   /*  �����û���������s�е�t�����û�Ϊv��  */

void replace(char *s, char *t, char *v)
{
	int i, j, k, po, sl, tl;
	sl = strlen(s);  tl = strlen(t);
	printf("\n sl=%d   tl=%d\n", sl, tl);
	po = 1;
	while (po< sl - tl + 1)
	{
		k = index(s, t, po);          /* ���ô�ƥ�亯�� */
		printf("\n k=%2d", k);
		i = k - 1;
		for (j = 0; j <= tl - 1; j++) { s[i] = v[j]; i++; }
		po = k + tl;
		printf("     pos=%2d", po);
	}
} /*  replace */
  /*  ��ƥ�亯�� */
  /*  ������s�ĵ�pos���ַ���ʼ�����Ӵ�t������������Ӵ�t������s��pos��ʼ֮���״γ��ֵ�λ�� */
int index(char *s, char *t, int pos)
{
	int i, j, sl, tl;
	i = pos;  j = 1; sl = strlen(s); tl = strlen(t);
	while (i <= sl && j <= tl)
		if (s[i - 1] == t[j - 1]) { i++; j++; }
		else { i = i - j + 1 + 1; j = 1; }
		if (j>tl) return(i - tl);
		else return(-1);
} /*  index  */

void chengfa()
{
	int m, n;
	float s;
	float a[20][20], b[20][20], c[20][20];
	int i, j, k;
	printf("���������������");
	scanf("%d", &m);
	printf("���������������");
	scanf("%d", &n);
	printf("�������һ������");
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			scanf("%f", &a[i][j]);
	printf("������ڶ�������");
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			scanf("%f", &b[i][j]);
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			s = 0;
			for (k = 0; k<n; k++)
			{
				s = s + a[i][k] * b[k][j];
			}
				c[i][j] = s;
		}
	}
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			printf("%4f  ", c[i][j]);
		}
		printf("\n");
	}

}

void zhuanzhi()
{
	int m, n;
	float a[20][20], b[20][20];
	int i, j;
	printf("���������������");
	scanf("%d", &m);
	printf("���������������");
	scanf("%d", &n);
	printf("������һ������");
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			scanf("%f", &a[i][j]);
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			b[i][j] = a[j][i];
			printf("%4f  ", b[i][j]);
		}
		printf("\n");
	}
}