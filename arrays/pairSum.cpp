#include <iostream>
#include "arr.h"
using namespace std;

int* getHashTable(Array arr) {
	int* hashTable = new int[arr.Max() + 1];
	for (int i = 0;i <= arr.Max();i++)  hashTable[i] = 0;
	for (int k = 0; k < arr.GetLength();k++) hashTable[arr.Get(k)]++;
	return hashTable;
}

void printPairsUnsorted(Array arr, int k) {
	int current_complement = 0;
	int pairs = 0;
	int* hashedArr = getHashTable(arr);
	for (int i = 0; i <= arr.Max();i++) {
		// Compare indices to avoid repetition
		if (hashedArr[i] > 0) {
			current_complement = k - i;
			if (i > current_complement) {
				cout << i << " + " << current_complement << " = " << k << endl;
				pairs = pairs + min(hashedArr[i], hashedArr[current_complement]);
			}
		}
	}
	printf("%d", pairs);
}

void printPairsSorted(Array arr, int k) {
	int i = 0;
	int j = arr.GetLength() - 1;
	int c_sum = 0;
	while (i <= j) {
		c_sum = arr.Get(i) + arr.Get(j);
		if (c_sum == k) cout << arr.Get(i++) << " + " << arr.Get(j--) << " = " << k << endl;
		else if (c_sum < k) i++;
		else j--;
	}
}


int main(int argc, char const* argv[])
{
	int unsorted[] = { 4,16,8,12,13,7,12,8,4 };
	int A[] = { 1,2,3,4,5,6,7 };
	Array arr(A, 7, 20);
	printPairsSorted(arr, 8);
	return 0;
}
