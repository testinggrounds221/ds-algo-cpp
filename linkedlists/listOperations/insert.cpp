#include "listOperations.h"


// void append(int key) {
// 	Node* ptr = head;
// 	Node* newNode = new Node;
// 	newNode->value = key;
// 	newNode->next = NULL;
// 	if (head == NULL) { head = newNode;return; }
// 	while (ptr->next)
// 		ptr = ptr->next;
// 	ptr->next = newNode;
// }

// void insertAfterPointer(int key, Node* indexPtr) {
// 	Node* ptr = head;
// 	while (ptr) {
// 		if (ptr == indexPtr) {
// 			Node* newNode = new Node;
// 			newNode->next = indexPtr->next;
// 			newNode->value = key;

// 			ptr->next = newNode;
// 			return;
// 		}
// 		ptr = ptr->next;

// 	}
// }

// void insertAfterIndex(int key, int index) {
// 	Node* ptr = head;
// 	if (index == 0) {
// 		Node* newNode = new Node;
// 		newNode->value = key;
// 		newNode->next = head;
// 		head = newNode;
// 		return;
// 	}
// 	int i = 0;
// 	while (i < index - 1 && ptr) {
// 		ptr = ptr->next;
// 		i++;
// 	}
// 	insertAfterPointer(key, ptr);
// }

// void insertInSorted(int key) {
// 	Node* p = head;
// 	Node* q = new Node;

// 	Node* newNode = new Node;
// 	newNode->next = NULL;
// 	newNode->value = key;

// 	if (head == NULL) { head = newNode; return; }
// 	if (head->value > key) {
// 		insertAfterIndex(key, 0);return;
// 	}

// 	while (p && key > p->value) {
// 		q = p;
// 		p = p->next;
// 	}
// 	insertAfterPointer(key, q);
// }

int main(int argc, char const* argv[])
{
	int A[] = { 1,6,23,45,50 };
	head = arrToList(A, sizeof(A) / sizeof(int));
	cout << "Inital List :	" << endl;
	traverse(head);

	cout << "Insert List :	" << endl;
	insertInSorted(-100);
	traverse(head);

	cout << "Insert List :	" << endl;
	insertInSorted(100);
	traverse(head);

	return 0;
}
