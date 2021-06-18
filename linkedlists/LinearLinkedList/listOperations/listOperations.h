#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
}*head = NULL;

int isSorted() {
	if (!head) return 0;
	Node* ptr = head;
	while (ptr->next) {
		if (ptr->value > ptr->next->value)
			return 0;
		ptr = ptr->next;
	}
	return 1;
}

void traverse(Node* head) {
	Node* ptr = head;
	while (ptr) {
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
}

void traverse() {
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

Node* getPointer(int key) {
	Node* ptr = head;
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

void append(int key) {
	Node* ptr = head;
	Node* newNode = new Node;
	newNode->value = key;
	newNode->next = NULL;
	if (head == NULL) { head = newNode;return; }
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = newNode;
}

void insertAfterPointer(int key, Node* indexPtr) {
	Node* ptr = head;
	while (ptr) {
		if (ptr == indexPtr) {
			Node* newNode = new Node;
			newNode->next = indexPtr->next;
			newNode->value = key;

			ptr->next = newNode;
			return;
		}
		ptr = ptr->next;

	}
}

void insertAfterIndex(int key, int index) {
	Node* ptr = head;
	if (index == 0) {
		Node* newNode = new Node;
		newNode->value = key;
		newNode->next = head;
		head = newNode;
		return;
	}
	int i = 0;
	while (i < index - 1 && ptr) {
		ptr = ptr->next;
		i++;
	}
	insertAfterPointer(key, ptr);
}

void insertInSorted(int key) {
	Node* p = head;
	Node* q = new Node;

	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->value = key;

	if (head == NULL) { head = newNode; return; }
	if (head->value > key) {
		insertAfterIndex(key, 0);return;
	}

	while (p && key > p->value) {
		q = p;
		p = p->next;
	}
	insertAfterPointer(key, q);
}

int deleteIndex(int index) {
	if (head == NULL) return -1;
	if (index == 1) {
		Node* tempHead = head;
		head = head->next;
		int deletedValue = head->value;
		delete tempHead;
		return deletedValue;
	}
	Node* ptr = head;
	int i = 1;
	while (i < index - 1 && ptr) {
		i++;
		ptr = ptr->next;
	}
	if (ptr == NULL || ptr->next == NULL) return -1;
	int deletedValue = ptr->next->value;
	ptr->next = ptr->next->next;
	delete ptr->next;
	return deletedValue;
}

void deleteNode(Node* deletePtr) {
	if (head == NULL || deletePtr == NULL) return;
	if (deletePtr == head) {
		head = head->next;
		return;
	}
	Node* ptr = head;
	while (ptr && ptr->next != deletePtr) {
		ptr = ptr->next;
	}
	ptr->next = ptr->next->next;
	delete ptr->next;
}
