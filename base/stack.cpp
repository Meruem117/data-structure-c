// Õ»
#include <stdio.h>

#define MaxSize 10
// Ë³ÐòÕ»
typedef struct {
	int data[MaxSize];
	int top;
} SqStack;

// ¹²ÏíÕ»
typedef struct {
	int data[MaxSize];
	int top0;
	int top1;
} ShStack;

void InitSqStack(SqStack &S) {
	S.top = -1;
}

void InitShStack(ShStack &S) {
	S.top0 = -1;
	S.top1 = MaxSize;
}

bool Empty(SqStack S) {
	return S.top == -1;
}

bool Push(SqStack &S, int e) {
	if(S.top == MaxSize-1) {
		return false;
	}
	S.top ++;
	S.data[S.top] = e;
	return true;
}

bool Pop(SqStack &S, int &e) {
	if(S.top == -1) {
		return false;
	}
	e = S.data[S.top];
	S.top --;
	return true;
}

bool GetTop(SqStack S, int &e) {
	if(S.top == -1) {
		return false;
	}
	e = S.data[S.top];
	printf("Õ»¶¥ÔªËØÎª%d\n",e);
	return true;
}

void PrintStack(SqStack S) {
	if(S.top == -1) {
		printf("Õ»Îª¿Õ\n");
		return;
	}
	printf("Õ»´Ó¶¥ÍùÏÂÎª ");
	for(int i = S.top; i >= 0 ; i--) {
		printf("%d ",S.data[i]);
	}
	printf("\n");
}

int main() {
	SqStack S;
	InitSqStack(S);
	PrintStack(S);

	Push(S,1);
	Push(S,2);
	Push(S,3);
	PrintStack(S);

	int e;
	Pop(S,e);
	PrintStack(S);

	int top;
	GetTop(S,top);

	return 0;
}
