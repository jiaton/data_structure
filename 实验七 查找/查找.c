#include<stdio.h>							/*引入头文件*/
#include<stdlib.h>
void seqsearch(int*, int);					/*声明插入查找函数*/
void binsearch(int*, int);					/*声明折半查找函数*/
void bubblesort(int*, int);					/*声明起泡排序函数*/

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
	printf("please input 10 data:");				/*提示输入10个数据*/
	for (i = 0; i<10; i++)
		scanf("%d", &(a[i]));						/*接收输入*/
	menu();								/*显示菜单*/
	while (j)								/*循环一次*/
	{
		scanf("%d", &ch);
		switch (ch)								/*选择执行程序*/
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

void seqsearch(int*r, int n)						/*直接查找函数*/
{
	int i = 0, data;
	printf("please input find data:");					/*提示输入查找数据*/
	scanf("%d", &data);							/*接收数据*/
	while (r[i] != data)								/*循环查找*/
		i++;
	if (i>n)
		printf("the data is not found");				/*输出数据没有找到*/
	else printf("the %d position is %d", data, i + 1); 		/*如果找到，输出位置*/
	getchar();
}

void binsearch(int *r, int n)						/*折半查找函数*/
{
	int j, data, low = 0, high = n, mid, find = 0;
	bubblesort(r, n);								/*起泡法排序*/
	for (j = 0; j<n; j++)
		printf("%d ", r[j]);							/*排序后输出*/
	printf("please input find data:");					/*提示输入查找数据*/
	scanf("%d", &data);
	while (low <= high && !find)						/*循环查找*/
	{
		mid = (low + high) / 2;							/*置mid指针*/
		if (data<r[mid])							/*判断数据大小，移动指针*/
			high = mid - 1;
		else if (data>r[mid])
			low = mid + 1;
		else find = 1;
	}
	if (!find)
		printf("the data is not found!\n");				/*显示数据没有找到*/
	else printf("the data position is %d", mid + 1);		 /*输出数据位置*/
	getchar();
}

void bubblesort(int *r, int n)						/*起泡排序函数*/
{
	int i, j, k, temp;
	k = n - 1;
	for (j = 0; j<n - 1; j++)
	{
		for (i = 0; i<k; i++)
		{
			if (r[i]>r[i + 1])							/*比较大小*/
			{
				temp = r[i]; 							/*交换数据的位置*/
				r[i] = r[i + 1];
				r[i + 1] = temp;
			}
		}
		k = k - 1;
	}
}
