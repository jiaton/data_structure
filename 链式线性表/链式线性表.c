//链表创增删改查 并实现AB两个链表的合并操作
#include<stdio.h>
#define ElemType int
typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode ,*LinkList;
int GetElem(LinkList L, int i, ElemType *e) {//取得第i个元素,若不存在，返回-1 L头指针
	LNode*p;
	p = L->next;//第一个节点
	int j = 1;
	while (p&&j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return-1;
	*e = p->data;
	return 1;
}
int ReferElem(LinkList L,ElemType e) {//查找元素e，返回元素位置
	int i = 1;
	LinkList p = L->next;//p指向第一个节点
	while (p)
	{
		if (p->data == e) return i;
		i++;
		p = p->next;
	}
	if (!p) return -1;
	return i;
}
int ListInsert(LinkList L, int i, ElemType e) {//将e插入到第i个位置
	LinkList p=L;
	int j = 0;
	while (p&&j < i - 1) {//找到i的前一个节点
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)return -1;
	LinkList q = (LinkList)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
int AddElem(LinkList L, ElemType e) {//在链表尾部添加一个节点
	LinkList p=L;
	while (p) {
		p = p->next;
	}//遍历到最后一个节点
	LinkList q = (LinkList)malloc(sizeof(LNode));
	p->next = q;
	q->data = e;
	q->next = NULL;
	return 1;
}
int DeleteElem(LinkList L, ElemType *e, int i) {//删除第i个元素并给e
	int j = 0;
	LinkList p=L;
	while (p&&j<i-1) {//找到i的前一个节点
		p = p->next;
		j++;
	}
	if (!p || j > i-1) return -1;
	LinkList q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
}
void MergeList(LinkList La, LinkList Lb, LinkList *Lc) {//把La，Lb合并，到Lc
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	*Lc = pc = pa;
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}
int main() {
	LinkList *L;
	prinf("请输出元素个数：");
	AddElem(L, 55);

}
