// 队列
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
// 顺序
typedef struct {
	int data[MaxSize];
	int front, rear;
	int size;
} SqQueue;

// 链式
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

// 判空
bool QueueEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

// 入队
bool EnQueue(SqQueue &Q, int x) {
	// 判断队满
	if(Q.size == MaxSize) {
		return false;
	}
	// 循环队列
	Q.data[Q.rear] = x;	// 新元素插入队尾
	Q.rear = (Q.rear + 1) % MaxSize;	// 队尾指针加1取模
	Q.size ++;
	return true;
}

// 出队
bool DeQueue(SqQueue &Q, int &x) {
	// 判断队空
	if(Q.size == 0) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.size --;
	return true;
}

// 队首元素
bool GetHead(SqQueue Q,int &x) {
	if(Q.size == 0) {
		return false;
	}
	x = Q.data[Q.front];
	return true;
}

// 打印队列
void PrintQueue(SqQueue Q) {
	if(Q.size > 0) {
		printf("队列为: ");
		for(int i =Q.front; i<Q.rear; i++) {
			printf("%d ",i+1,Q.data[i]);
		}
		printf("\n");
	} else {
		printf("队列为空\n");
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
	printf("队首元素为%d\n",x);

	DeQueue(Q,x);
	PrintQueue(Q);

	return 0;
}
