
#include "stdio.h"
#include "stdlib.h"
typedef int Status;
typedef int elemtype;
#define listsize 100



typedef struct {
	int a[listsize];
	int length;
}Seqlist;

//初始化
void InitList(Seqlist *l)

{
	l->length = 0;
}

//创建
void createlList(Seqlist *l) {
	int i;
	for (i = 0;; i++)
	{
		scanf("%d", &l->a[i]);
		l->length++;
		if (getchar() == '?')break;
	}
}

//序号查找元素
Status LocateSqList(Seqlist *l, int i) {
	return l->a[i - 1];
}

// 由元素找序号
Status LocateSqList_2(Seqlist *l, elemtype e) {
	int i;
	for (i = 0; i<l->length; i++) {
		if (l->a[i] == e) {
			return i + 1;
		}
	}
	return -1;
}
//插入
void listinsert(Seqlist *l, elemtype  e, int i) {


	if (i<1 || i>l->length + 1) {
		puts("插入位置错");

	}
	if (l->length >= listsize) {
		puts("表满不能插入");

	}
	for (int j = l->length - 1; j >= i - 1; j--)
		l->a[j + 1] = l->a[j];

	l->a[i - 1] = e;

	l->length++;

}


//删除元素

void listdelete(Seqlist *l, int i)
{
	int  j;
	if (i<1 || i>l->length)
		printf("删除元素失败!");

	if (l->length == 0)
		printf("空表不能删除!");

	for (j = i; j <= l->length - 1; j++)
		l->a[j - 1] = l->a[j];
	l->length--;

}
//表显示
void PrintSqList(Seqlist *l) {
	printf("顺序表数据如下：\n");
	for (int i = 0; i<l->length - 1; i++) {
		printf("%4d", l->a[i]);
	}
	printf("\n");
}

int main() {
	Seqlist l;
	int a[999];
	int length = 0;
	int index, order = 0;
	int deleteorder;

	printf("请输入你想建立的顺序表的元素，以？结束\n");
	printf("请输入顺序表元素：\n");
	createlList(&l);
	printf("你建立的顺序表为");
	PrintSqList(&l);
	printf("你顺序表的长度为：%d\n", l.length - 1);
	printf("输入你想查找的元素:");
	scanf("%d", &index);
	printf("数据%d的位置为:%d\n", index, LocateSqList_2(&l, index));

	printf("输入你想查找的元素序位:");
	scanf("%d", &order);
	printf("你查找的元素为%d", index);
	LocateSqList(&l, index);
	printf("\n输入你想插入的元素以及序位:<用逗号隔开>"); 	scanf("%d,%d", &index, &order);
	listinsert(&l, index, order);
	printf("插入数据之后的顺序表如下：\n");
	PrintSqList(&l);
	printf("请输入你想删除的元素序位:");
	scanf("%d", &deleteorder);
	listdelete(&l, deleteorder);
	PrintSqList(&l);

	printf("\n");
	return 0;
}

