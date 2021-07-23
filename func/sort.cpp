#include <stdio.h>

void PrintArr(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", A[i] );
	}
	printf("\n");
}

// 直接插入排序
void InsertSort(int A[], int n) {
	int i, j, tmp;
	for (i = 1; i < n; i++) {
		if (A[i] < A[i - 1]) {
			tmp = A[i];
			for (j = i - 1; j > 0 && A[j] > tmp; j--) {
				A[j + 1] = A[j];
			}
			A[j + 1] = tmp;
		}
	}
}

// 直接插入排序(带哨兵)
void InsertSort2(int A[], int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		if (A[i] < A[i - 1]) {
			A[0] = A[i];
			for (j = i - 1; A[0] < A[j]; j--) {
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];
		}
	}
}

// 折半插入排序
void InsertSort3(int A[], int n) {
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++) {
		A[0] = A[1];
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (A[mid] > A[0]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		for (j = i - 1; j >= high + 1; j--) {
			A[j + 1] = A[j];
		}
		A[high + 1] = A[0];
	}
}

// 希尔排序
void ShellSort(int A[], int n) {
	int d, i, j;
	for (d = n / 2; d >= 1; d = d / 2) {	// 步长变化
		for (i = d + 1; i <= n; i++) {
			if (A[i] < A[i - d]) {
				A[0] = A[i];
				for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {
					A[j + d] = A[j];
				}
				A[j + d] = A[0];
			}
		}
	}
}

// 冒泡排序
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void BubbleSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool flag = false;
		for (int j = n - 1; j > 1; j--) {
			if (A[j - 1] > A[j]) {
				swap(A[j - 1], A[j]) {
					flag = true;
				}
			}
		}
		if (flag = false) {
			return;
		}
	}
}

// 快速排序
int Partition(int A[], int low, int high) {
	int pivot = A[low];	// 第一个元素作为基准
	while (low < high) {
		while (low < high && A[high] >= pivot) {
			high --;
		}
		A[low] = A[high];	// 比基准小的元素移到左端
		while (low < high && A[low] <= pivot) {
			low ++;
		}
		A[high] = A[low];	// 比基准大的元素移到右端
	}
	A[low] = pivot;	// 记录基准元素最终位置
	return low;
}
void QuickSort(int A[], int low, int high) {
	if (low < high) {
		int pivotpos = Partition(A, low, high);	// 划分
		QuickSort(A, low, pivotpos);	// 划分左子表
		QuickSort(A, pivotpos + 1, high);	// 划分右子表
	}
}

// 选择排序
void SelectSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
			if (min != j) {
				swap(A[i], A[min]);
			}
		}
	}
}

// 堆排序
void HeadAdjust(int A[], int k, int n) {
	A[0] = A[k];
	for (int i = 2 * k; i <= n; i *= 2) {
		if (i < n && A[i] < A[i + 1]) {
			i++;
		}
		if (A[0] >= A[i]) {
			break;
		} else {
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = A[0];
}
void BuildHeap(int A[], int n) {
	for (int i = n / 2; i > 0; i--) {
		HeadAdjust(A, i, n);
	}
}
void HeadSort(int A[], int n) {
	BuildHeap(A, n);
	for (int i = n; i > 1; i--) {
		swap(A[i], A[1]);
		HeadAdjust(A, 1, i - 1);
	}
}

int main() {
	int A[] = {2, 3 , 3, 1, 4, 2};
	return 0;
}
