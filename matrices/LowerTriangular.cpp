#include<iostream>
using namespace std;

class LowerTriangular {
private:
	void printZeroes(int num_zero) {
		// printf("%d\n", num_zero);
		for (int i = 0;i < num_zero;i++) cout << "0 ";
	}
public:
	LowerTriangular(int* arr, int dim)
	{
		n = dim;
		A = arr;
	}
	int* A;
	int n;

	int getRowMajorIndex(int i, int j) {
		int index;
		if (i >= j) index = ((i - 1) * i) / 2 + (j - 1);
		return index;
	}
	int getColumnMajorIndex(int i, int j) {
		int index;
		if (i >= j) {
			index = n * (j - 1) - (((j - 1) * (j - 2)) / 2) + i - j;
		}
		return index;
	}

	int getRowMajorValue(int i, int j) {
		int index;
		if (i >= j) {
			index = ((i - 1) * i) / 2 + (j - 1);
			return A[index];
		}
		return 0;
	}
	int getColumnMajorValue(int i, int j) {
		int index;
		if (i >= j) {
			index = n * (j - 1) - (((j - 1) * (j - 2)) / 2) + i - j;
			return A[index];
		}
		return 0;
	}

	void setRowMajorValue(int i, int j, int x) {
		if (i >= j) {
			int index = ((i - 1) * i) / 2 + (j - 1);
			A[index] = x;
		}
	}
	void setColumnMajorValue(int i, int j, int x) {
		if (i >= j) {
			int index = n * (j - 1) - (((j - 1) * (j - 2)) / 2) + i - j;
			A[index] = x;
		}
	}

	void DisplayRowMajor() {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				printf("%d ", getRowMajorValue(i, j));
			}
			printf("\n");
		}
	}
	void DisplayColumnMajor() {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				printf("%d ", getColumnMajorValue(i, j));
			}
			printf("\n");
		}
	}

};

int main()
{
	int A[] = { 21,12,43,64,25,13,24,34,53,63,10,12,14,45,20 };
	LowerTriangular m(A, 5);
	m.DisplayColumnMajor();
	return 0;
}
