#include<stdio.h>							/*����ͷ�ļ�*/
#include<stdlib.h>
void seqsearch(int*, int);					/*����������Һ���*/
void binsearch(int*, int);					/*�����۰���Һ���*/
void bubblesort(int*, int);					/*��������������*/

void menu()
{
	printf(" 1.seqsearch()\n");
	printf(" 2.binsearch()\n");
	printf(" 3.exit()\n");
	printf("please select the method:");
}

void main()
{
	int i, j = 1;
	int ch;
	int a[10];
	clrscr();
	printf("please input 10 data:");				/*��ʾ����10������*/
	for (i = 0; i<10; i++)
		scanf("%d", &(a[i]));						/*��������*/
	menu();								/*��ʾ�˵�*/
	while (j)								/*ѭ��һ��*/
	{
		scanf("%d", &ch);
		switch (ch)								/*ѡ��ִ�г���*/
		{
		case 1:seqsearch(a, 10); break;
		case 2:binsearch(a, 10); break;
		case 3:j = 0; break;
		default:break;
		}
		printf("\n");
		menu();
	}
}

void seqsearch(int*r, int n)						/*ֱ�Ӳ��Һ���*/
{
	int i = 0, data;
	printf("please input find data:");					/*��ʾ�����������*/
	scanf("%d", &data);							/*��������*/
	while (r[i] != data)								/*ѭ������*/
		i++;
	if (i>n)
		printf("the data is not found");				/*�������û���ҵ�*/
	else printf("the %d position is %d", data, i + 1); 		/*����ҵ������λ��*/
	getchar();
}

void binsearch(int *r, int n)						/*�۰���Һ���*/
{
	int j, data, low = 0, high = n, mid, find = 0;
	bubblesort(r, n);								/*���ݷ�����*/
	for (j = 0; j<n; j++)
		printf("%d ", r[j]);							/*��������*/
	printf("please input find data:");					/*��ʾ�����������*/
	scanf("%d", &data);
	while (low <= high && !find)						/*ѭ������*/
	{
		mid = (low + high) / 2;							/*��midָ��*/
		if (data<r[mid])							/*�ж����ݴ�С���ƶ�ָ��*/
			high = mid - 1;
		else if (data>r[mid])
			low = mid + 1;
		else find = 1;
	}
	if (!find)
		printf("the data is not found!\n");				/*��ʾ����û���ҵ�*/
	else printf("the data position is %d", mid + 1);		 /*�������λ��*/
	getchar();
}

void bubblesort(int *r, int n)						/*����������*/
{
	int i, j, k, temp;
	k = n - 1;
	for (j = 0; j<n - 1; j++)
	{
		for (i = 0; i<k; i++)
		{
			if (r[i]>r[i + 1])							/*�Ƚϴ�С*/
			{
				temp = r[i]; 							/*�������ݵ�λ��*/
				r[i] = r[i + 1];
				r[i + 1] = temp;
			}
		}
		k = k - 1;
	}
}
