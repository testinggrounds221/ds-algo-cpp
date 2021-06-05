#include <iostream>
#include "arr.h"
using namespace std;

Array findDuplicateElements(Array arr) {
	Array duplicates(arr.GetLength());
	for (int i = 0;i < arr.GetLength();i++) {
		if (arr.Get(i) == arr.Get(i + 1)) {
			duplicates.Append(arr.Get(i));
			while (arr.Get(i) == arr.Get(i + 1))
				i++;
		}
	}
	return duplicates;
}

Array findUniqueElements(Array arr) {
	Array duplicates(arr.GetLength());
	for (int i = 0;i < arr.GetLength();i++) {
		while (arr.Get(i) == arr.Get(i + 1))
			i++;
		duplicates.Append(arr.Get(i));

	}
	return duplicates;
}

Array findDuplicateElementsAlternate(Array arr) {
	Array duplicates(arr.GetLength());
	int lastDup = 0;
	for (int i = 0;i < arr.GetLength();i++) {
		if (arr.Get(i) == arr.Get(i + 1) && (arr.Get(i) != lastDup)) {
			duplicates.Append(arr.Get(i));
			lastDup = arr.Get(i);
		}
	}
	return duplicates;
}

int* countDuplicates(Array arr) {
	int* dupCount = new int[arr.Max() + 1];
	for (int i = 0;i <= arr.Max();i++) dupCount[i] = 0;

	for (int k = 0; k < arr.GetLength();k++) dupCount[arr.Get(k)]++;
	return dupCount;
}

int main(int argc, char const* argv[])
{
	// int A[] = { 1,2,3,4,5,6,7,8,9,10 };
	int A[] = { 10,11,11,12,13,14,17,17,17,20,20,30,30 };
	int unsorted[] = { 12,34,1,22,12,45,34,34,12,10 };

	Array arr(unsorted, 10, 20);
	//  findDuplicateElements(arr).Display();
	int* dupCount = countDuplicates(arr);
	for (int i = 0;i <= arr.Max();i++) {
		if (dupCount[i] > 1)
			cout << i << " - " << dupCount[i] << endl;
	}

	return 0;
}

