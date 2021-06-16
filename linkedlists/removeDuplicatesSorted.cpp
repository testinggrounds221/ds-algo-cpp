#include "listOperations.h"

void removeDuplicates() {
	Node* q = head;
	Node* ptr = head->next;

	while (ptr) {
		if (q->value != ptr->value) {
			q = ptr;
			ptr = ptr->next;
		}
		else {
			q->next = ptr->next;
			delete ptr;
			ptr = q->next;
		}
	}
}

int main(int argc, char const* argv[]) {
	int A[] = { 1,1,1,1,2,3,4,4,4,5,5,6,7,8,8,88 };
	head = arrToList(A, sizeof(A) / sizeof(int));
	// cout << isSorted() << endl;
	removeDuplicates();
	traverse();
	cout << "Heyy" << endl;

	return 0;
}
