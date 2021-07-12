#include <stdio.h>

#define MaxSize 10
typedef struct {
	char data[MaxSize];
	int top;
} Stack;

void InitStack(Stack &S) {
	S.top = -1;
}

bool Empty(Stack S) {
	return S.top == -1;
}

bool Push(Stack &S, char e) {
	if(S.top == MaxSize-1) {
		return false;
	}
	S.top ++;
	S.data[S.top] = e;
	return true;
}

bool Pop(Stack &S, char &e) {
	if(S.top == -1) {
		return false;
	}
	e = S.data[S.top];
	S.top --;
	return true;
}

// ¿®∫≈∆•≈‰
bool BracketCheck(char str[], int len) {
	Stack s;
	InitStack(s);
	for(int i=0; i<len; i++) {
		if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
			Push(s,str[i]);
		} else {
			if(Empty(s)) {
				return false;
			}
			char top;
			Pop(s,top);
			if(str[i] == ')' && top != '(') {
				return false;
			}
			if(str[i] == ']' && top != '[') {
				return false;
			}
			if(str[i] == '}' && top != '{') {
				return false;
			}
		}
	}
	return Empty(s);
}

int main() {
	char str1[] = {'{','[','(',')',']','}'};
	char str2[] = {'{','[','(',')',']',')'};
	if(BracketCheck(str1,6)) {
		printf("¿®∫≈∆•≈‰");
	} else {
		printf("¿®∫≈≤ª∆•≈‰");
	}
	return 0;
}
