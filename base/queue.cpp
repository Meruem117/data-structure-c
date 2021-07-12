// ����
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
// ˳��
typedef struct {
	int data[MaxSize];
	int front, rear;
	int size;
} SqQueue;

// ��ʽ
typedef struct LinkNode {
	int data;
	struct LinkNode *next;
} LinkNode;
typedef struct {
	LinkNode *front, *rear;
} LinkQueue;

void InitLinkQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

void EnLinkQueue(LinkQueue &Q, int e) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

void DeLinkQueue(LinkQueue &Q, int &e) {
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

// �п�
bool QueueEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

// ���
bool EnQueue(SqQueue &Q, int x) {
	// �ж϶���
	if(Q.size == MaxSize) {
		return false;
	}
	// ѭ������
	Q.data[Q.rear] = x;	// ��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MaxSize;	// ��βָ���1ȡģ
	Q.size ++;
	return true;
}

// ����
bool DeQueue(SqQueue &Q, int &x) {
	// �ж϶ӿ�
	if(Q.size == 0) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.size --;
	return true;
}

// ����Ԫ��
bool GetHead(SqQueue Q,int &x) {
	if(Q.size == 0) {
		return false;
	}
	x = Q.data[Q.front];
	return true;
}

// ��ӡ����
void PrintQueue(SqQueue Q) {
	if(Q.size > 0) {
		printf("����Ϊ: ");
		for(int i =Q.front; i<Q.rear; i++) {
			printf("%d ",i+1,Q.data[i]);
		}
		printf("\n");
	} else {
		printf("����Ϊ��\n");
	}
}

int main() {
	SqQueue Q;
	Q.size = 0;
	Q.front = Q.rear = 0;
	int x;
	PrintQueue(Q);

	EnQueue(Q,1);
	EnQueue(Q,2);
	PrintQueue(Q);

	GetHead(Q,x);
	printf("����Ԫ��Ϊ%d\n",x);

	DeQueue(Q,x);
	PrintQueue(Q);

	return 0;
}
