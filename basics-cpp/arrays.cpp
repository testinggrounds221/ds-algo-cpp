#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void printArray(T A[], int len = 5) {
	for (int i = 0;i < len;i++) {
		cout << A[i];
	}
}

// inline int getLength(int A[]) {
// 	return sizeof(A) / sizeof(int);
// }

int main()
{
	int* p;
	p = (int*)malloc(5 * sizeof(int)); // C lang

	int A[5] = { 0,1,1,2,3 };
	// cout << sizeof(A) / sizeof(int) << endl;
	// cout << getLength(A) << endl; No other way, pass Length as argument

	printArray(A, 5);


}