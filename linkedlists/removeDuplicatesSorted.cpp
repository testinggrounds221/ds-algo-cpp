#include "listOperations.h"

void removeDuplicates() {
	Node* q = NULL;
	Node* ptr = head;
	
}

int main(int argc, char const* argv[]) {
	int A[] = { 1,2,3,4,4,4,5,5,6,7,8 };
	head = arrToList(A, sizeof(A) / sizeof(int));
	// cout << isSorted() << endl;
	removeDuplicates();
	traverse();
	cout << "Heyy" << endl;

	return 0;
}
