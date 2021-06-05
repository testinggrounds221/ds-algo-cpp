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

void negOnLeft(Array* arr) {
	int p = 0, q = arr->length - 1;
	int* i = &p;
	int* j = &q;
	while (p < q) {
		while (arr->A[p] < 0) p++;
		while (arr->A[q] >= 0) q--;
		if (p < q) swap(&arr->A[p], &arr->A[q]);
	}
}


void Reverse(Array* arr) {
	int i = 0;
	int j = arr->length - 1;
	while (i <= j) {
		swap(&arr->A[i], &arr->A[j]);
		i++;
		j--;
	}
}
void Insert(Array* arr, int index, int x) {
	if ((arr->length < arr->size) && (arr->length >= index) && (index >= 0)) {
		for (int i = arr->length;i > index;i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		++arr->length;
	}
}

bool isSorted(Array arr) {
	for (int i = 0;i < arr.length - 1;i++) {
		if (arr.A[i] > arr.A[i + 1])
			return false;
	}
	return true;
}

void insertInSorted(Array* arr, int key) {
	int lower = 0, mid = 0;
	int upper = arr->length - 1;

	while (upper >= lower) {
		mid = (upper + lower) / 2;
		if (key < arr->A[mid]) upper = mid - 1;
		if (key > arr->A[mid]) lower = mid + 1;
		if (key == arr->A[mid]) break;
	}
	if (arr->A[mid] >= key) {
		Insert(arr, mid, key);
		return;
	}
	Insert(arr, mid + 1, key);
}

Array merge(Array a1, Array a2) {
	int total_elements = a1.length + a2.length;
	int i = 0;
	int j = 0;
	int k = 0;
	Array merged = { {},0,20 };
	while (i < a1.length && j < a2.length) {
		if (a1.A[i] < a2.A[j]) merged.A[k++] = a1.A[i++];
		else merged.A[k++] = a2.A[j++];
	}
	for (;i < a1.length;i++)
		merged.A[k++] = a1.A[i];
	for (;j < a2.length;j++)
		merged.A[k++] = a2.A[j];

	merged.length = k;

	return merged;
}


int main(int argc, char const* argv[])
{

	Array arr = { {2,3,5,6,7},5,20 };
	Array negArr = { {-2,-3,7,12,100},5,20 };
	Array merged = { {},0,20 };

	Array newArr = merge(arr, negArr);
	Display(newArr);
	return 0;
}