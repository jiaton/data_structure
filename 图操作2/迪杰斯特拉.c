#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
int arcs[10][10];//�ڽӾ���
int D[10];//�������·������
int p[10][10];//·��
int final[10];//��final[i] = 1��˵�� ����vi���ڼ���S��
int n = 0;//�������
int v0 = 0;//Դ��
int v, w;
void ShortestPath_DIJ()
{
	int i = 0, min = 0;
	for (v = 0; v < n; v++) //ѭ�� ��ʼ��
	{
		final[v] = 0;
		D[v] = arcs[v0][v];
		for (w = 0; w < n; w++)
			p[v][w] = 0;//���·��
		if (D[v] < MAX)
		{
			p[v][v0] = 1;
			p[v][v] = 1;
		}
	}
	D[v0] = 0;
	final[v0] = 0; //��ʼ�� v0�������ڼ���S
				   //��ʼ��ѭ�� ÿ�����v0��ĳ������v�����·�� ����v������S��
	for (i = 1; i < n; i++)
	{
		min = MAX;
		for (w = 0; w < n; w++)
		{
			//����Ϊ�ĺ��Ĺ���--ѡ��
			if (!final[w]) //���w������V-S��
			{
				//�����������ѡ���ĵ� Ӧ����ѡ����ǰV-S����S�й�����
				//��Ȩֵ��С�Ķ��� ��������Ϊ ��ǰ��V0����ĵ�
				if (D[w] < min) { v = w; min = D[w]; }
			}
		}
		final[v] = 1; //ѡ���õ����뵽�ϼ�S��
		for (w = 0; w < n; w++)//���µ�ǰ���·���;���
		{
			/*�ڴ�ѭ���� vΪ��ǰ��ѡ�뼯��S�еĵ�
			���Ե�VΪ�м�� ���� d0v+dvw �Ƿ�С�� D[w] ���С�� �����
			����ӽ��� 3 ����Ҫ���� D[5] �Ƿ�Ҫ���� �� �ж� d(v0-v3) + d(v3-v5) �ĺ��Ƿ�С��D[5]
			*/
			if (!final[w] && (min + arcs[v][w]<D[w]))
			{
				D[w] = min + arcs[v][w];
				// p[w] = p[v];
				p[w][w] = 1; //p[w] = p[v] +��[w]
			}
		}
	}
}


int main()
{
	int i, j;
	scanf("%d", &n);                                    //�������
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arcs[i][j]);                  //�����洢�ڽӾ���
		}
	}
	ShortestPath_DIJ();
	for (i = 0; i < n; i++)
		printf("D[%d] = %d\n", i, D[i]);
	return 0;
}