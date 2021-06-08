#include<iostream>
using namespace std;

class Diagonal {
private:
	void printZeroes(int num_zero) {
		// printf("%d\n", num_zero);
		for (int i = 0;i < num_zero;i++) cout << "0 ";
	}
public:
	Diagonal(int* arr, int dim)
	{
		n = dim;
		A = arr;
	}
	int* A;
	int n;
	void set(int i, int j, int x) { if (i == j) A[i - 1] = x; }
	int get(int i, int j) {
		if (i == j)return A[i - 1];
		else return 0;
	}
	void Display() {
		for (int i = 0;i < n;i++) {
			printZeroes(i);
			printf("%d ", A[i]);
			printZeroes(n - i - 1);
			printf("\n");
		}
	}

};

int main()
{
	int A[] = { 21,12,43,64,253 };
	Diagonal m(A, 5);
	m.Display();



	return 0;
}
