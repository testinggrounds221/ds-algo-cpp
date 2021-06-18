#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
}*head = NULL;

Node* linearMoveToHead(int key) {
	Node* q = NULL;
	Node* ptr = head;

	while (ptr)
	{
		if (ptr->value == key) {
			q->next = ptr->next;
			ptr->next = head;
			head = ptr;
		}
		q = ptr;
		ptr = ptr->next;
	}
	return NULL;
}

Node* linearSearchTranspose(int key) {
	Node* q = NULL;
	Node* r = NULL;

	Node* ptr = head;

	while (ptr)
	{
		if (ptr->value == key) {
			r->next = ptr;
			q->next = ptr->next;
			ptr->next = q;
		}
		r = q;
		q = ptr;
		ptr = ptr->next;
	}
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


int main(int argc, char const* argv[])
{
	int A[] = { 1,2,-2,-12,24,12,34,54,23 };
	head = arrToList(A, sizeof(A) / sizeof(int));

	cout << "Value of head " << head->value << endl;
	traverse(head);

	cout << "Address of Head Before" << head << endl;
	linearSearchTranspose(24);
	cout << "Value of head Pointer" << head->value << endl;
	cout << "Address of Head " << head << endl;
	traverse(head);

	return 0;
}
