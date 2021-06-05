// Sum upto n terms being n(n+1)/2
#include "arr.h"
#include <iostream>
using namespace std;

int findMissingElementUsingSum(Array arr) {
	int lower = arr.Get(0);
	int higher = arr.Get(arr.GetLength() - 1);

	int sumUptoHigh = higher * (higher + 1) / 2;
	int sumUptoLower = lower * (lower + 1) / 2;

	int sumRange = sumUptoHigh - sumUptoLower + lower;
	int missing = sumRange - arr.Sum();

	return missing;
}

Array findMissingElementsUsingIndex(Array arr) {
	int difference = arr.Get(0);
	Array missing(arr.GetLength() - 5);
	for (int i = 0;i < arr.GetLength();i++) {
		if ((arr.Get(i) - i) != difference) {
			while (difference < (arr.Get(i) - i)) {
				missing.Append(i + difference);
				difference++;
			}

		}
	}
	return missing;
}

Array inUnsortedByHashing(Array arr) {
	int max = arr.Max();
	int min = arr.Min();

	Array missing(max - 1);
	int hash[max + 1] = { 0 };

	for (int i = 0;i <= arr.GetLength();i++)
		hash[arr.Get(i)] = 1;

	for (int j = min;j <= max;j++) {
		if (hash[j] != 1)
			missing.Append(j);
	}
	return missing;
}



int main(int argc, char const* argv[])
{
	// int A[] = { 1,2,3,4,5,6,7,8,9,10 };
	int A[] = { 10,11,12,13,14,17,20 };
	Array arr(A, 7, 20);
	// cout << findMissingElementUsingSum(arr) << endl;
	// findMissingElementsUsingIndex(arr).Display();
	inUnsortedByHashing(arr).Display();


	return 0;
}
