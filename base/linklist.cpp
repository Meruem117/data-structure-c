// 单链表
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *LinkList;

// 初始化 - 带头结点
bool InitList(LinkList &L) {
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL) {	// 内存不足，分配失败
		return false;
	}
	L->next = NULL;
	return true;
}

// 初始化 - 不带头结点
bool InitList2(LinkList &L) {
	L = NULL;
	return true;
}

// 判空 - 带头结点
bool Empty(LinkList L) {
	return L->next == NULL;
}

// 判空 - 不带头结点
bool Empty2(LinkList L) {
	return L == NULL;
}

// 插入 - 带头结点
bool ListInsert(LinkList &L, int i , int e) {
	if(i < 0) {
		return false;
	}
	LNode *p;
	int j = 0;
	p = L;	// L指向头结点，头结点是第0个结点，p指向头结点
	while(p!=NULL && j < i-1) {	// 循环找到i-1个结点
		p = p->next;
		j++;
	}

//	return InsertNextNode(p,e);	// 可替代下面的操作

	if(p == NULL) { // i值不合法
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;	// 将结点s连到p之后
	return true;
}

// 插入 - 不带头结点
bool ListInsert2(LinkList &L, int i , int e) {
	if(i < 0) {
		return false;
	}
	if(i == 1) {
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;	// 头指针指向新结点
		return true;
	}
	LNode *p;
	int j = 1;
	p = L;	// p指向第1个结点
	while(p!=NULL && j < i-1) {	// 循环找到i-1个结点
		p = p->next;
		j++;
	}
	if(p == NULL) { // i值不合法
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;	// 将结点s连到p之后
	return true;
}

// 后插操作 - 在p结点之后插入元素 e
bool InsertNextNode(LNode *p, int e) {
	if(p == NULL) {
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL) {	// 内存分配失败
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

// 前插操作 -  在p结点之前插入元素 e
bool InsertPriorNode(LNode *p, int e) {
	if(p == NULL) {
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL) {	// 内存分配失败
		return false;
	}
	s->next = p->next;
	p->next = s;	// 将新结点连到p之后
	s->data = p->data;	// 将p中元素复制到s中
	p->data = e;	// p中元素覆盖为e
	return true;
}

// 删除操作 - 带头结点
bool ListDelete(LinkList &L, int i , int &e) {
	if(i < 0) {
		return false;
	}
	LNode *p;
	int j = 0;
	p = L;	// L指向头结点，头结点是第0个结点，p指向头结点
	while(p!=NULL && j < i-1) {	// 循环找到i-1个结点
		p = p->next;
		j++;
	}
	if(p == NULL) { // i值不合法
		return false;
	}
	if(p->next == NULL) { // 第i-1个结点后没有其他结点
		return false;
	}

	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(p);
	return true;
}

// 删除指定结点
bool DeleteNode(LNode *p) {
	if (p == NULL) {
		return false;
	}
	LNode *q = p->next;
	p->data = p->next->data;	// 如果p是最后一个结点，则有问题
	p->next = q->next;
	free(q);
	return true;
}

// 按位查找 - 带头结点
LNode * GetElem(LinkList L, int i) {
	// i=0 返回头结点, i>L长度，返回NULL
	if(i<0) {
		return NULL;
	}
	LNode *p;
	int j = 0;
	p = L;
	while(p!=NULL && j < i) {
		p = p->next;
		j ++;
	}
	return p;
}

// 按值查找
LNode * LocateElem(LinkList L, int e) {
	LNode *p = L->next;
	while(p!=NULL && p->data != e) {
		p = p->next;
	}
	return p;
}

// 求表长度
int Length(LinkList L) {
	int len = 0;
	LNode *p = L;
	while(p->next != NULL) {
		p = p->next;
		len ++;
	}
	return len;
}

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s,*r = L;
	scanf("%d",&x);
	while(x!=9999) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return L;
}

//  头尾插法建立单链表
LinkList List_HeadInsert(LinkList &L) {
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x!=9999) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}

int main() {
	LinkList L;

	return 0;
}
