#include <stdio.h>

#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int front, rear;
	int size; // 队列当前长度
} SqQueue;

// 初始化队列
void InitQueue() {
	SqQueue SQ;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue SQ) {
	if(SQ.rear == SQ.front) {
		return true;
	} else {
		return false;
	}
}

// 入队
bool EnQueue(SqQueue &SQ, int x) {
	// 判断队满
	if(SQ.size == MaxSize) {
		return false;
	}
	// 循环队列
	SQ.data[SQ.rear] = x;	// 新元素插入队尾
	SQ.rear = (SQ.rear + 1) % MaxSize;	// 队尾指针加1取模
	SQ.size ++;
	return true;
}

// 出队
bool DeQueue(SqQueue &SQ, int &x) {
	// 判断队空
	if(SQ.size == 0) {
		return false;
	}
	x = SQ.data[SQ.front];
	SQ.front = (SQ.front + 1) % MaxSize;
	SQ.size --;
	return true;
}

// 队首元素
bool GetHead(SqQueue SQ,int &x) {
	if(SQ.size == 0) {
		return false;
	}
	x = SQ.data[SQ.front];
	return true;
}

// 打印队列
void PrintQueue(SqQueue SQ) {
	if(SQ.size > 0) {
		printf("队列为: ");
		for(int i =SQ.front; i<SQ.rear; i++) {
			printf("%d ",i+1,SQ.data[i]);
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
