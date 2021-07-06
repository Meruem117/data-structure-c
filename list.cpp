// ���Ա�
#include <stdio.h>
#include <stdlib.h>

// ��̬
#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int length;
} SqList;

// ��̬
#define InitSize 10
typedef struct {
	int *data;
	int max;
	int length;
} SeqList;

// ��ʼ�� - ��̬
void InitList2(SeqList &L) {
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.max = InitSize;
}

// ��̬���ӳ���
void IncreaseList(SeqList &L, int len) {
	int *tmp = L.data;
	L.data = (int *)malloc((L.max + len) * sizeof(int));
	for(int i=0; i<L.length; i++) {
		L.data[i] = tmp[i];
	}
	L.max += len;
	free(tmp);
}

// ��ʼ�� - ��̬
void InitList(SqList &L) {
	for(int i=0; i<MaxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

// ����
void DestroyList(SqList &L) {
	for(int i=0; i<MaxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

// ����
bool ListInsert(SqList &L,int index,int elem) {
	if(L.length >= MaxSize) {
		printf("˳�������\n");
		return false;
	}
	if(index < 0 && index > L.length) {
		printf("����ֵ���Ϸ�\n");
		return false;
	}
	for(int i=L.length; i>=index; i--) {
		L.data[i] = L.data[i-1];
	}
	L.data[index] = elem;
	L.length ++;
	return true;
}

// ɾ��
bool ListDelete(SqList &L,int index,int &elem) {
	if(index<0 && index >= MaxSize) {
		printf("����λ�ò��Ϸ�\n");
		return false;
	}
	if(L.length == 0) {
		printf("˳���Ϊ�գ��޷�ɾ��\n");
		return false;
	}
	elem = L.data[index];
	L.length --;
	for(int i=index; i<L.length; i++) {
		L.data[i] = L.data[i+1];
	}
	return true;
}

// ��ֵ����
int LocateElem(SqList L, int elem) {
	for(int i=0; i<L.length; i++) {
		if(L.data[i] == elem) {
			printf("%d������Ϊ%d\n",elem,i);
			return i;
		}
	}
	return -1;
}

// ��λ����
int GetElem(SqList L, int index) {
	if(L.data[index]) {
		printf("��%dλ�洢������Ϊ%d\n",index,L.data[index]);
		return L.data[index];
	} else {
		return -1;
	}
}

// �����
int Length(SqList L) {
	return L.length;
}

// �п�
bool Empty(SqList L) {
	return L.length == 0;
}

// ���
void PrintList(SqList L) {
	if(L.length == 0) {
		printf("˳���Ϊ��\n");
	} else {
		printf("˳���Ϊ: ");
		for(int i=0; i<L.length; i++) {
			printf("%d ",L.data[i]);
		}
		printf("\n");
	}
}

int main() {
	SqList L;
	InitList(L);
	PrintList(L);

	ListInsert(L,0,1);
	ListInsert(L,1,2);
	ListInsert(L,2,3);
	ListInsert(L,3,4);
	PrintList(L);
	printf("˳���ĳ���Ϊ%d\n",Length(L));

	GetElem(L,2);
	LocateElem(L,3);

	int elemDeleted;
	ListDelete(L,3,elemDeleted);
	printf("��ɾ����Ԫ��Ϊ%d\n",elemDeleted);
	PrintList(L);

	DestroyList(L);
	PrintList(L);
	return 0;
}
