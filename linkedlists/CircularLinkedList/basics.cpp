// Needs Corrections
#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
}*head, * trial;

void arrToCircularLL(int A[], int n) {
	Node* t;
	Node* tail;

	head = new Node;

	head->val = A[0];
	head->next = head;
	tail = head;

	for (int i = 1; i < n; i++) {
		t = new Node;
		t->val = A[i];
		t->next = tail->next;

		tail->next = t;
		tail = t;
	}

}

void deleteHead() {
	Node* ptr = head;
	do {
		ptr = ptr->next;
	} while (ptr->next != head);
	if (head == ptr) { delete head;head = NULL; }
	ptr->next = head->next;
	delete head;
	head = ptr;
}


void deleteIndex(int index) {
	// TO DO -> CHECK FOR INDEX IN BOUNDS OF LL
	int i = 0;
	if (index == 0) { deleteHead();return; }
	Node* ptr = head;
	do {
		ptr = ptr->next;
		i++;
	} while (ptr != head && i < index - 1);
	ptr->next = ptr->next->next;
	delete ptr->next;
}

void insert(int x, int index) {
	// CHECK FOR INDEX IN BOUNDS OF LL
	trial = NULL;
	Node* ptr = head;

	Node* newPtr = new Node;
	newPtr->val = x;
	if (index == 0) {
		while (ptr->next != head)
			ptr = ptr->next;
		cout << "Last Pointer value" << ptr->val << endl;
		ptr->next = newPtr;
		newPtr->next = head;
		head = newPtr;
		cout << newPtr << endl;

		cout << "Head Addr." << head << endl;

		return;
	}
	int i = 0;
	ptr = head;
	while (i < index - 1) {
		ptr = ptr->next;
		i++;
	}
	newPtr->next = ptr->next;
	ptr->next = newPtr;

}

void displayCircularLL() {
	if (!head) return;
	Node* ptr = head;
	do {
		cout << ptr->val << endl;
		ptr = ptr->next;
	} while (ptr != head);
}

void recursiveDisplayCircularLL(Node* ptr) {
	static int flag = 0;
	if (ptr != head || flag == 0) {
		cout << ptr->val << endl;
		flag++;
		recursiveDisplayCircularLL(ptr->next);
	}
	flag = 0;
}


int main(int argc, char const* argv[])
{
	int A[] = { 1,2,3,4,5,6,7,8,9,0 };
	arrToCircularLL(A, sizeof(A) / sizeof(int));
	trial = head;
	deleteIndex(5);
	displayCircularLL();
	return 0;
}


