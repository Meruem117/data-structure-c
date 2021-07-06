// 线性表
#include <stdio.h>
#include <stdlib.h>

// 静态
#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int length;
} SqList;

// 动态
#define InitSize 10
typedef struct {
	int *data;
	int max;
	int length;
} SeqList;

// 初始化 - 动态
void InitList2(SeqList &L) {
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.max = InitSize;
}

// 动态增加长度
void IncreaseList(SeqList &L, int len) {
	int *tmp = L.data;
	L.data = (int *)malloc((L.max + len) * sizeof(int));
	for(int i=0; i<L.length; i++) {
		L.data[i] = tmp[i];
	}
	L.max += len;
	free(tmp);
}

// 初始化 - 静态
void InitList(SqList &L) {
	for(int i=0; i<MaxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

// 销毁
void DestroyList(SqList &L) {
	for(int i=0; i<MaxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}

// 插入
bool ListInsert(SqList &L,int index,int elem) {
	if(L.length >= MaxSize) {
		printf("顺序表已满\n");
		return false;
	}
	if(index < 0 && index > L.length) {
		printf("输入值不合法\n");
		return false;
	}
	for(int i=L.length; i>=index; i--) {
		L.data[i] = L.data[i-1];
	}
	L.data[index] = elem;
	L.length ++;
	return true;
}

// 删除
bool ListDelete(SqList &L,int index,int &elem) {
	if(index<0 && index >= MaxSize) {
		printf("输入位置不合法\n");
		return false;
	}
	if(L.length == 0) {
		printf("顺序表为空，无法删除\n");
		return false;
	}
	elem = L.data[index];
	L.length --;
	for(int i=index; i<L.length; i++) {
		L.data[i] = L.data[i+1];
	}
	return true;
}

// 按值查找
int LocateElem(SqList L, int elem) {
	for(int i=0; i<L.length; i++) {
		if(L.data[i] == elem) {
			printf("%d的索引为%d\n",elem,i);
			return i;
		}
	}
	return -1;
}

// 按位查找
int GetElem(SqList L, int index) {
	if(L.data[index]) {
		printf("第%d位存储的数据为%d\n",index,L.data[index]);
		return L.data[index];
	} else {
		return -1;
	}
}

// 求表长度
int Length(SqList L) {
	return L.length;
}

// 判空
bool Empty(SqList L) {
	return L.length == 0;
}

// 输出
void PrintList(SqList L) {
	if(L.length == 0) {
		printf("顺序表为空\n");
	} else {
		printf("顺序表为: ");
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
	printf("顺序表的长度为%d\n",Length(L));

	GetElem(L,2);
	LocateElem(L,3);

	int elemDeleted;
	ListDelete(L,3,elemDeleted);
	printf("被删除的元素为%d\n",elemDeleted);
	PrintList(L);

	DestroyList(L);
	PrintList(L);
	return 0;
}
