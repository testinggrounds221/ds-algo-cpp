#include<iostream>
using namespace std;

class TriDiagonal {
public:
	TriDiagonal(int* arr, int dim)
	{
		n = dim;
		A = arr;
	}
	int* A;
	int n;
	int getIndex(int i, int j) {
		int index;
		if (std::abs(i - j) <= 1) {
			if (i < j) index = 2 * n + i - 2;
			if (i > j) index = j - 1;
			if (i == j) index = n + i - 2;
		}
		return index;
	}
	int getValue(int i, int j) {
		int index;
		if (std::abs(i - j) <= 1) {
			return A[getIndex(i, j)];
		}
		return 0;
	}
	void setValue(int i, int j, int x) {
		A[getIndex(i, j)] = x;
	}
	void Display() {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				printf("%d\t", getValue(i, j));
			}
			printf("\n");
		}
	}


};
int main()
{
	int A[] = { 21,12,43,64,25,13,24,34,53,63,10,12,14 };
	TriDiagonal m(A, 5);
	m.Display();
	return 0;
}
