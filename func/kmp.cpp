#include <stdio.h>

#define MaxSize 255
typedef struct {
	char ch[MaxSize];
	int length;
} SString;

void getNext(SString T, int next[]) {
	int i=1, j=0;
	next[1] = 0;
	while(i < T.length) {
		if(j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
	printf("next数组为: ");
	for(int k=1; k<=T.length; k++) {
		printf("%d ", next[k]);
	}
	printf("\n");
}

void getNextval(SString T, int next[], int nextval[]) {
	nextval[1] = 0;
	for(int j=2; j<=T.length; j++) {
		if(T.ch[next[j]] == T.ch[j]) {
			nextval[j] = nextval[next[j]];
		} else {
			nextval[j] = next[j];
		}
	}
	printf("nextval数组为: ");
	for(int k=1; k<=T.length; k++) {
		printf("%d ", nextval[k]);
	}
	printf("\n");
}

int KMP(SString S, SString T) {
	int i=1, j=1;
	int next[T.length + 1];
	getNext(T,next);
	int nextval[T.length + 1];
	getNextval(T,next,nextval);
	while(i<=S.length && j<=T.length) {
		if(j == 0 || S.ch[i] == T.ch[j]) {
			i++;
			j++;
		} else {
			j=next[j];
		}
	}
	if(j > T.length) {
		return i - T.length;
	}
	return 0;
}

void StrAssign(SString &S, char chars[]) {
	int i=1, j=0;
	while(chars[j]) {
		S.ch[i] = chars[j];
		i++;
		j++;
	}
	S.length = j;
}

void PrintString(SString S) {
	if(S.length == 0) {
		printf("串为空\n");
	} else {
		printf("串为: ");
		for(int i=1; i<=S.length; i++) {
			printf("%c",S.ch[i]);
		}
		printf(" 长度为: %d\n",S.length);
	}
}

int main() {
	SString S1,S2;
	char c1[] = {'a','a','a','a','b'};
	char c2[] = {'a','a','a','b'};
	StrAssign(S1,c1);
	StrAssign(S2,c2);
	printf("S1");
	PrintString(S1);
	printf("S2");
	PrintString(S2);

	printf("S2在S1的位置为%d",KMP(S1,S2));

	return 0;
}
