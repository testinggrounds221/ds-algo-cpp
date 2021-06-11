#include<iostream>
using namespace std;

class Toeplitz {
public:
	Toeplitz(int* arr, int dim)
	{
		n = dim;
		A = arr;
	}
	int* A;
	int n;
	int getIndex(int i, int j) {
		int index;
		if (i <= j) index = j - i;
		if (i > j) index = n + i - j - 1;
		return index;
	}
	int getValue(int i, int j) {
		int index;
		return A[getIndex(i, j)];
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
	int A[] = { 1,2,3,4,5,6,7,8,9 };
	Toeplitz m(A, 5);
	m.Display();
	return 0;
}
