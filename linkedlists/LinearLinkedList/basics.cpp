#include <iostream>
using namespace std;

// template <typename T>
// struct Node {
// 	T value;
// 	Node* next;
// };

struct Node {
	int value;
	Node* next;
};

int main2(int argc, char const* argv[]) {

	// Node<int>* q;
	// q = new Node<int>;
	// cout << "Address of the qointer" << q << endl;

	// q->value = 25.4;
	// q->next = NULL;

	// Node<int>* p;
	// p = new Node<int>;
	// cout << "Address of the pointer" << p << endl;

	// p->value = 20;
	// p->next = q;

	// Node<int>* head = new Node<int>;
	// head->value = 0;
	// Node<int>* ptr = head;

	// for (int i = 1;i < 10;i++) {
	// 	Node<int>* temp = new Node<int>;
	// 	temp->value = i;
	// 	ptr->next = temp;
	// 	ptr = temp;
	// }
	// ptr->next = NULL;
	// ptr = head;
	// while (ptr->next != 0) {
	// 	cout << ptr->value << endl;
	// }
	return 0;
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

int main(int argc, char const* argv[])
{
	Node* head = fillInIntegers(0, 9);
	cout << head << endl;
	traverse(head);
	cout << head << endl;
	int A[] = { 2,12,34,23,54,23 };
	Node* head2 = arrToList(A, sizeof(A) / sizeof(int));
	traverse(head2);
	// cout << sizeof(A) / sizeof(int);
	// cout << typeid(typeid(typeid(A).name()).name()).name();
	return 0;
}
