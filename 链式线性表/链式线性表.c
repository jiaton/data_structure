//������ɾ�Ĳ� ��ʵ��AB��������ĺϲ�����
#include<stdio.h>
#define ElemType int
typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode ,*LinkList;
int GetElem(LinkList L, int i, ElemType *e) {//ȡ�õ�i��Ԫ��,�������ڣ�����-1 Lͷָ��
	LNode*p;
	p = L->next;//��һ���ڵ�
	int j = 1;
	while (p&&j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return-1;
	*e = p->data;
	return 1;
}
int ReferElem(LinkList L,ElemType e) {//����Ԫ��e������Ԫ��λ��
	int i = 1;
	LinkList p = L->next;//pָ���һ���ڵ�
	while (p)
	{
		if (p->data == e) return i;
		i++;
		p = p->next;
	}
	if (!p) return -1;
	return i;
}
int ListInsert(LinkList L, int i, ElemType e) {//��e���뵽��i��λ��
	LinkList p=L;
	int j = 0;
	while (p&&j < i - 1) {//�ҵ�i��ǰһ���ڵ�
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
int AddElem(LinkList L, ElemType e) {//������β�����һ���ڵ�
	LinkList p=L;
	while (p) {
		p = p->next;
	}//���������һ���ڵ�
	LinkList q = (LinkList)malloc(sizeof(LNode));
	p->next = q;
	q->data = e;
	q->next = NULL;
	return 1;
}
int DeleteElem(LinkList L, ElemType *e, int i) {//ɾ����i��Ԫ�ز���e
	int j = 0;
	LinkList p=L;
	while (p&&j<i-1) {//�ҵ�i��ǰһ���ڵ�
		p = p->next;
		j++;
	}
	if (!p || j > i-1) return -1;
	LinkList q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
}
void MergeList(LinkList La, LinkList Lb, LinkList *Lc) {//��La��Lb�ϲ�����Lc
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
	prinf("�����Ԫ�ظ�����");
	AddElem(L, 55);

}
