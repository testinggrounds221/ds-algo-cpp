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






int main(int argc, char const* argv[])
{
	// int A[] = { 1,2,3,4,5,6,7,8,9,10 };
	int A[] = { 10,11,11,11,12,13,14,17,17,17,20 };
	Array arr(A, 11, 20);
	findDuplicateElements(arr).Display();


	return 0;
}

