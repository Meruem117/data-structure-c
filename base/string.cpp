// 串
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 255
typedef struct {
	char ch[MaxSize];
	int length;
} SString;

typedef struct {
	char *ch;
	int length;
} HString;

typedef struct SNode {
	char ch[4];
	struct SNode *next;
} SNode, *LString;

void InitSString(SString &S) {	// 系统自动回收
	S.length = 0;
}

void InitHString(HString &HS) {	// 用完需要手动free
	HS.ch = (char *)malloc(MaxSize * sizeof(char));
	HS.length = 0;
}

void StrAssign(SString &S, char chars[]) {
	int i=0;
	while(chars[i]) {
		S.ch[i] = chars[i];
		i++;
	}
	S.length = i;
}

void StrCopy(SString &T, SString S) {
	for(int i=0; i<S.length; i++) {
		T.ch[i] = S.ch[i];
	}
	T.length = S.length;
}

bool StrEmpty(SString S) {
	return S.length == 0;
}

bool StrLength(SString S) {
	return S.length;
}

void ClearString(SString &S) {
	S.length = 0;
}

void DestroyHString(HString &HS) {
	free(HS.ch);
}

void StrConcat(SString &R, SString S, SString T) {
	int k = 0;
	for(int i=0; i<S.length; i++) {
		R.ch[k++] = S.ch[i];
	}
	for(int j=0; j<T.length; j++) {
		R.ch[k++] = T.ch[j];
	}
	R.length = k;
}

bool SubString(SString &Sub, SString S, int pos, int len) {
	if(pos+len-1 > S.length) {
		return false;
	}
	for(int i=pos; i<pos+len; i++) {
		Sub.ch[i-pos] = S.ch[i];
	}
	Sub.length = len;
	return true;
}

// S>T,return>0; S=T,return=0; S<T,return<0
int StrCompare(SString S, SString T) {
	for(int i=0; i<=S.length && i<=T.length; i++) {
		if(S.ch[i] != T.ch[i]) {
			return S.ch[i] - T.ch[i];
		}
	}
	return S.length - T.length;
}

int Index(SString S, SString T) {
	int i=1, n=S.length, m=T.length;
	SString sub;
	while(i < n-m+1) {
		SubString(sub,S,i,m);
		if(StrCompare(sub,T) != 0) {
			i++;
		} else {
			return i;
		}
	}
	return 0;
}

void PrintString(SString S) {
	if(S.length == 0) {
		printf("串为空\n");
	} else {
		printf("串为: ");
		for(int i=0; i<S.length; i++) {
			printf("%c",S.ch[i]);
		}
		printf("\n");
	}
}

// 串的朴素模式匹配
int NIndex(SString S, SString T) {
	int i=0, j=0;
	while(i<S.length && j<T.length) {
		if(S.ch[i] == T.ch[j]) {
			i++;
			j++;
		} else {
			i = i-j+1;
			j = 0;
		}
	}
	if(j = T.length) {
		return i - T.length;
	}
	return 0;
}

int main() {
	SString S;
	InitSString(S);
	PrintString(S);

	char chars[] = {'a','b'};

	StrAssign(S,chars);
	printf("S");
	PrintString(S);

	SString T;
	StrCopy(T,S);
	printf("T");
	PrintString(T);

	SString R;
	StrConcat(R,S,T);
	printf("R");
	PrintString(R);

	SString RS;
	SubString(RS,R,1,2);
	printf("RS");
	PrintString(RS);

	printf("RS在R中的位置为: %d\n",NIndex(R,RS));

	return 0;
}
