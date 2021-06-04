#include <iostream>
using namespace std;
struct Array {
	int A[10];
	int length;
	int size;
};

void Display(Array arr);
void swap(int* x, int* y);
bool checkValidIndex(Array arr, int index);

void Append(Array* arr, int x);
void Insert(Array* arr, int index, int x);
int Delete(Array* arr, int index);

int LinearSearch(Array* arr, int key);
int BinarySearchLoop(Array arr, int key);
int BinarySearchRecursive(Array arr, int key, int lower, int upper);

bool checkValidIndex(Array arr, int index) {
	if (index < arr.length && index >= 0)
		return true;
	return false;
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Display(Array arr) {
	cout << "\n Elements Are : \n";
	for (int i = 0;i < arr.length;i++) {
		printf("%d\n", arr.A[i]);
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

int Delete(Array* arr, int index) {
	int i = 0;
	if ((arr->length > 1) && (arr->length > index)) {
		int x = arr->A[index];
		for (i = index;i < arr->length - 1;i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return x;
	}
	return -1;
}
int LinearSearch(Array* arr, int key) {
	for (int i = 0;i < arr->length;i++) {
		if (arr->A[i] == key) {
			swap(&arr->A[i], &arr->A[0]);
			return i;
		}

	}
	return -1;
}

int BinarySearchLoop(Array arr, int key) {
	int mid = 0;
	int upper = arr.length;
	int lower = 0;
	while (lower < upper) {
		mid = (lower + upper) / 2;
		if (arr.A[mid] == key)
			return mid;

		if (arr.A[mid] > key)
			upper = mid - 1;

		if (arr.A[mid] < key)
			lower = mid + 1;
	}
	return -1;
}

int BinarySearchRecursive(Array arr, int key, int lower, int upper) {
	int mid = (lower + upper) / 2;
	cout << "mid = " << mid << endl;
	if (upper >= lower) {
		if (arr.A[mid] == key)
			return mid;
		if (arr.A[mid] > key)
			return BinarySearchRecursive(arr, key, lower, mid - 1);
		if (arr.A[mid] < key)
			return BinarySearchRecursive(arr, key, mid + 1, upper);
	}

	return -1;
}



void Append(Array* arr, int x) {
	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
}

int main(int argc, char const* argv[])
{
	Array arr = { {2,3,4,5,6},5,10 };
	Display(arr);
	// Append(&arr, 10);
	// Display(arr);
	// Insert(&arr, 4, 100);
	// cout << "\nAfter insertion \n";
	// Display(arr);

	// cout << "\nAfter Deletion \n";
	// printf("%d\n", Delete(&arr, 0));
	// printf("%d\n", Delete(&arr, arr.length - 1));

	// Display(arr);
	// printf("\n%d", LinearSearch(&arr, 6));
	// Display(arr);
	// printf("\n%d\n", BinarySearchRecursive(arr, 20, 0, arr.length));
	// printf("\n%d\n", BinarySearchRecursive(arr, 2, 0, arr.length));
	// printf("\n%d\n", BinarySearchRecursive(arr, 30, 0, arr.length));
	printf("\n%d\n", BinarySearchRecursive(arr, 5, 0, arr.length));
	// printf("\n%d\n", BinarySearchRecursive(arr, 6, 0, arr.length));

	return 0;
}
