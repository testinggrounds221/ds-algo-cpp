#include "listOperations.h"

void reverseList() {
	Node* ptr = head;
	Node* q = NULL;
	Node* r = NULL;

	while (ptr) {
		r = q;
		q = ptr;
		ptr = ptr->next;

		q->next = r;
	}
	head = q;

}

void reverseElements() {
	Node* ptr = head;
	int i = 0;
	int A[recursiveCount(ptr)];
	while (ptr) {
		A[i++] = ptr->value;
		ptr = ptr->next;
	}
	i--;
	ptr = head;
	while (ptr) {
		ptr->value = A[i--];
		ptr = ptr->next;
	}
}

void recursiveReverse(Node* ptr, Node* q) {
	if (ptr) {
		recursiveReverse(ptr->next, ptr);
		ptr->next = q;
	}
	else
		head = q;
}

int main(int argc, char const* argv[])
{
	int A[] = { 1,2,3,4,5,6,7,8,9,10 };
	head = arrToList(A, sizeof(A) / sizeof(int));
	// reverseList();
	// traverse();

	// recursiveReverse(head, NULL);
	// traverse();

	reverseElements();
	traverse();
	cout << "Operation Over" << endl;

	return 0;
	return 0;
}
