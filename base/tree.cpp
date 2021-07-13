// ������
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 40
// ������ ˳��
typedef struct {
	int value;
	bool isEmpty;
} TreeNode;	// i������2i,�Һ���2i+1,�����i/2

// ������ ��ʽ
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
//	struct BiTNode *parent;
} BiTNode, *BiTree;

typedef struct LinkNode {
	BiTNode * data;
	struct LinkNode *next;
} LinkNode;

typedef struct {
	LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q, BiTNode *e) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

void DeQueue(LinkQueue &Q, BiTNode* &e) {
	if(Q.rear == Q.front) {
		return;
	}
	LinkNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) {
		Q.rear = Q.front;
	}
	free(p);
}

bool IsQueueEmpty(LinkQueue Q) {
	return Q.front->next == NULL;
}

void TestBiTree() {
	BiTree root = NULL;
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data = 1;
	root->lchild = NULL;
	root->rchild = NULL;

	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data = 2;
	p->lchild = NULL;
	p->rchild = NULL;
	root->rchild = p;
}

void Visit(BiTNode *T) {
	printf("%d ",T->data);
}

// �������
void PreOrder(BiTree T) {
	if(T != NULL) {
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// �������
void InOrder(BiTree T) {
	if(T != NULL) {
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}

// �������
void PostOrder(BiTree T) {
	if(T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T);
	}
}

// ���������
int TreeDepth(BiTree T) {
	if(T == NULL) {
		return 0;
	}
	int l = TreeDepth(T->lchild);
	int r = TreeDepth(T->rchild);
	return l>r ? l+1 : r+1;
}

// �������
void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);
	while(!IsQueueEmpty(Q)) {
		DeQueue(Q,p);
		Visit(p);
		if(p->lchild != NULL) {
			EnQueue(Q,p->lchild);
		}
		if(p->rchild != NULL) {
			EnQueue(Q,p->rchild);
		}
	}
}

int main() {

	return 0;
}
