#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

int recursiveMax(int max, Node* ptr) {
	if (ptr)
		return recursiveMax(std::max(ptr->value, max), ptr->next);
	return max;
	// INT32_MAX;
}

int recursiveMin(int min, Node* ptr) {
	if (ptr)
		return recursiveMin(std::min(ptr->value, min), ptr->next);
	return min;
	// INT32_MAX
}

int recursivePresence(int key, Node* ptr) {
	if (ptr && ptr->value != key)
		return recursivePresence(key, ptr->next);
	if (ptr && ptr->value == key)
		return 1;
	return 0;
}

Node* getPointer(int key, Node* ptr) {
	while (ptr) {
		if (ptr && ptr->value == key)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}


Node* recursiveGetPointer(int key, Node* ptr) {
	if (ptr && ptr->value != key)
		return recursiveGetPointer(key, ptr->next);
	if (ptr && ptr->value == key)
		return ptr;
	return NULL;
}

int recursiveSum(Node* ptr) {
	if (ptr)
		return ptr->value + recursiveSum(ptr->next);
	return 0;
}

int recursiveCount(Node* ptr) {
	if (ptr)
		return 1 + recursiveCount(ptr->next);
	return 0;
}

void tailRecursiveTraverse(Node* ptr) {
	if (ptr) {
		cout << ptr->value << endl;
		tailRecursiveTraverse(ptr->next);
	}
}

void headRecursiveTraverse(Node* ptr) {
	if (ptr) {
		headRecursiveTraverse(ptr->next);
		cout << ptr->value << endl;
	}
}

void traverse(Node* head) {
	Node* ptr = head;
	while (ptr) {
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
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

Node* fillInIntegers(int start, int end) {
	Node* head = new Node;
	head->value = start;

	Node* ptr = head;

	for (int i = start + 1;i < end;i++) {
		Node* temp = new Node;
		temp->value = i;
		temp->next = NULL;

		ptr->next = temp;
		ptr = temp;
	}
	return head;
}

int main(int argc, char const* argv[]) {
	// Node* head = fillInIntegers(0, 9);
	// cout << head << endl;
	// traverse(head);
	// cout << head << endl;
	int A[] = { 1,2,-2,-12,2,12,34,23,54,23 };
	// 2+12+34+23+54+23
	Node* head2 = arrToList(A, sizeof(A) / sizeof(int));
	// tailRecursiveTraverse(head2);
	// headRecursiveTraverse(head2);
	// cout << recursiveCount(head2) << endl;
	// cout << recursiveMax(head2->value, head2) << endl;
	cout << recursiveMin(head2->value, head2) << endl;
	cout << recursivePresence(23, head2) << endl;
	cout << recursiveGetPointer(23, head2)->value << endl;

	Node* keyPtr = getPointer(23, head2);
	if (keyPtr) cout << "Found";
	else cout << "Not Found";

	// cout << NULL->value << endl;


	// cout << sizeof(A) / sizeof(int);
	// cout << typeid(typeid(typeid(A).name()).name()).name();
	return 0;
}
