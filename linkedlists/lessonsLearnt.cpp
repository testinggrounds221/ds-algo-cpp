#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};


void transpose(int key, Node* head) {
	Node* ptr = new Node;
	while (ptr) {
		if (ptr->next->next->value == key) {
			Node* keyNode = ptr->next->next;
			Node* pN = ptr->next;
			Node* nN = keyNode->next;

			ptr->next = keyNode;
			keyNode->next = pN;
			pN->next = nN;
			return;
		}
		ptr = ptr->next;
	}
}

Node* linearMoveToHead(int key, Node* head) {
	Node* ptr = head;
	while (ptr->next) {
		Node* nextPointer = ptr->next;
		if (nextPointer->value == key) {
			Node* nextHead = head->next;

			head->next = nextPointer->next;
			ptr->next = head;

			head = nextPointer;
			head->next = nextHead;
			cout << "here" << endl;
			cout << "Value Of key Pointer " << nextPointer->value << endl;
			cout << "Address of Head " << head << endl;

		}
		ptr = ptr->next;
	}
	return NULL;
}

int recursivePresence(int key, Node* ptr) {
	if (ptr && ptr->value != key)
		return recursivePresence(key, ptr->next);
	if (ptr && ptr->value == key)
		return 1;
	return 0;
}

Node* recursiveGetPointer(int key, Node* ptr) {
	if (ptr && ptr->value != key)
		return recursiveGetPointer(key, ptr->next);
	if (ptr && ptr->value == key)
		return ptr;
	return NULL;
}
Node* arrToList(int A[], int n) {
	if (n == 0) return NULL;
	Node* head = new Node;
	head->value = A[0];
	head->next = NULL;

	Node* ptr = head;

	for (int i = 1;i < n;i++) {
		Node* temp = new Node;
		temp->value = A[i];
		temp->next = NULL;

		ptr->next = temp;
		ptr = temp;
	}
	return head;
}

void traverse(Node* head) {
	Node* ptr = head;
	while (ptr) {
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
	cout << endl;
}

int main(int argc, char const* argv[]) {

	int A[] = { 1,2,-2,-12,24,12,34,23,54,23 };
	Node* head = arrToList(A, sizeof(A) / sizeof(int));
	cout << "Value of head " << head->value << endl;
	traverse(head);

	// Node* keyPtr = linearMoveToHead(24, head);
	cout << "Address of Head Before" << head << endl;

	linearMoveToHead(24, head);
	cout << "Value of head Pointer" << head->value << endl;
	cout << "Address of Head " << head << endl; // Address IS SAME AFTER CHANGING ??
	// if (keyPtr) cout << "Found" << endl;
	// else cout << "Not Found" << endl;


	traverse(head);
	// cout << NULL->value << endl;


	// cout << sizeof(A) / sizeof(int);
	// cout << typeid(typeid(typeid(A).name()).name()).name();
	return 0;
}
