#include <stdio.h>

#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int front, rear;
	int size; // ���е�ǰ����
} SqQueue;

// ��ʼ������
void InitQueue() {
	SqQueue SQ;
}

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue SQ) {
	if(SQ.rear == SQ.front) {
		return true;
	} else {
		return false;
	}
}

// ���
bool EnQueue(SqQueue &SQ, int x) {
	// �ж϶���
	if(SQ.size == MaxSize) {
		return false;
	}
	// ѭ������
	SQ.data[SQ.rear] = x;	// ��Ԫ�ز����β
	SQ.rear = (SQ.rear + 1) % MaxSize;	// ��βָ���1ȡģ
	SQ.size ++;
	return true;
}

// ����
bool DeQueue(SqQueue &SQ, int &x) {
	// �ж϶ӿ�
	if(SQ.size == 0) {
		return false;
	}
	x = SQ.data[SQ.front];
	SQ.front = (SQ.front + 1) % MaxSize;
	SQ.size --;
	return true;
}

// ����Ԫ��
bool GetHead(SqQueue SQ,int &x) {
	if(SQ.size == 0) {
		return false;
	}
	x = SQ.data[SQ.front];
	return true;
}

// ��ӡ����
void PrintQueue(SqQueue SQ) {
	if(SQ.size > 0) {
		printf("����Ϊ: ");
		for(int i =SQ.front; i<SQ.rear; i++) {
			printf("%d ",i+1,SQ.data[i]);
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
