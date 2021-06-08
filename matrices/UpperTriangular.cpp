#include<iostream>
using namespace std;

class UpperTriangular {
private:
	void printZeroes(int num_zero) {
		// printf("%d\n", num_zero);
		for (int i = 0;i < num_zero;i++) cout << "0 ";
	}
public:
	UpperTriangular(int* arr, int dim)
	{
		n = dim;
		A = arr;
	}
	int* A;
	int n;

	int getRowMajorIndex(int i, int j) {
		int index;
		if (i <= j) index = n * (i - 1) - ((i - 2) * (i - 1) / 2) + j - i;
		return index;
	}
	int getRowMajorValue(int i, int j) {
		int index;
		if (i <= j) {
			return A[getRowMajorIndex(i, j)];
		}
		return 0;
	}
	void setRowMajorValue(int i, int j, int x) {
		if (i <= j) {
			A[getRowMajorIndex(i, j)] = x;
		}
	}
	void DisplayRowMajor() {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				printf("%d\t", getRowMajorValue(i, j));
			}
			printf("\n");
		}
	}

	int getColumnMajorIndex(int i, int j) {
		int index;
		if (i <= j) index = ((j * (j - 1)) / 2) + i - 1;
		return index;
	}
	int getColumnMajorValue(int i, int j) {
		int index;
		if (i <= j) {
			return A[getColumnMajorIndex(i, j)];
		}
		return 0;
	}
	void setColumnMajorValue(int i, int j, int x) {
		if (i <= j) {
			A[getColumnMajorIndex(i, j)] = x;
		}
	}
	void DisplayColumnMajor() {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				printf("%d\t", getColumnMajorValue(i, j));
			}
			printf("\n");
		}
	}

};

int main()
{
	int A[] = { 21,12,43,64,25,13,24,34,53,63,10,12,14,45,20 };
	UpperTriangular m(A, 5);
	m.DisplayColumnMajor();
	return 0;
}
