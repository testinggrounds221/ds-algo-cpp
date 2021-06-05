#include <iostream>
using namespace std;


struct Array {
	int A[20];
	int length;
	int size;
};
void Display(Array arr) {
	cout << "\n Elements Are : \n";
	for (int i = 0;i < arr.length;i++) {
		printf("%d\n", arr.A[i]);
	}
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}



Array Intersection(Array a1, Array a2) {
	int total_elements = a1.length + a2.length;
	int i = 0;
	int j = 0;
	int k = 0;
	Array merged = { {},0,20 };
	while (i < a1.length && j < a2.length) {
		if (a1.A[i] < a2.A[j]) i++;
		else if (a1.A[i] > a2.A[j]) j++;
		else { merged.A[k++] = a2.A[j++];i++; }
	}


	merged.length = k;

	return merged;
}


Array Difference(Array a1, Array a2) {
	int total_elements = a1.length + a2.length;
	int i = 0;
	int j = 0;
	int k = 0;
	Array merged = { {},0,20 };
	while (i < a1.length && j < a2.length) {
		if (a1.A[i] < a2.A[j]) merged.A[k++] = a1.A[i++];

		else if (a1.A[i] > a2.A[j]) j++;

		else { i++; j++; }
	}
	for (;i < a1.length;)
		merged.A[k++] = a1.A[i++];


	merged.length = k;

	return merged;
}


int main(int argc, char const* argv[])
{

	Array arr = { {2,3,5,6,7},5,20 };
	Array negArr = { {2,3,7,8,9},5,20 };
	Array merged = { {},0,20 };


	Display(Difference(arr, negArr));
	return 0;
}