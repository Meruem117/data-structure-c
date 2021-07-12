#include <stdio.h>

#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int top;
} Stack;

void InitStack(Stack &S) {
	S.top = -1;
}

bool Empty(Stack S) {
	return S.top == -1;
}

bool Push(Stack &S, int e) {
	if(S.top == MaxSize-1) {
		return false;
	}
	S.top ++;
	S.data[S.top] = e;
	return true;
}

bool Pop(Stack &S, int &e) {
	if(S.top == -1) {
		return false;
	}
	e = S.data[S.top];
	S.top --;
	return true;
}

int main() {

	return 0;
}
