#include <stdio.h>

// ˳�����
typedef struct {
	int *data;
	int len;
} SqTable;

int search_seq(SqTable T,int key) {
	T.data[0] = key;	// �ڱ�
	int i;
	for(i=T.len; T.data[i]!=key; i--);
	return i;
}

// ���ֲ���
int binary_search(SqTable T,int key) {
	int low=1, high=T.len-1, mid;
	while(low <= high) {
		mid = (low + high) / 2;
		if(T.data[mid] == key) {
			return mid;
		} else if(T.data[mid] > key) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}

// �ֿ����
// ������
typedef struct {
	int maxValue;
	int low,high;
} Index;

int main() {
	SqTable T;
	int data[10] = {0,1,2,3,4,5,6,7,8,9};	// 0λ���洢���� 
	T.data = data;
	T.len = 9;
	
	printf("˳����ҽ��Ϊ %d\n",search_seq(T,3));
	printf("˳����ҽ��Ϊ %d\n",binary_search(T,3));
	return 0;
}
