#include<iostream>
#include <stack>

using namespace std;

class Node {
public:
	Node* prev;
	int val;
	Node* next;
};


class DoubleLL {
public:
	Node* head;
	DoubleLL();
	DoubleLL(int* A, int n);
	void Display();
	void Insert(int index, int x);
	void insertHead(int x);
	int deleteHead();
	int Delete(int index);
	void ReverseList1();
	void ReverseList2();
	Node* findMiddlePointer();
	Node* findIntersection(Node* head2);
};

DoubleLL::DoubleLL() {
	Node* head = new Node;
	head->next = nullptr;
	head->val = 0;
	head->prev = nullptr;
}

DoubleLL::DoubleLL(int* A, int num) {
	head = new Node;
	head->val = A[0];
	head->prev = nullptr;
	head->next = nullptr;
	Node* tail = head;


	for (int i = 1;i < num;i++) {
		Node* newNode = new Node;
		newNode->val = A[i];
		newNode->prev = tail;
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
}

void DoubleLL::Display() {
	Node* ptr = head;
	while (ptr != nullptr) {
		cout << ptr->val << endl;
		ptr = ptr->next;
	}
}

void DoubleLL::insertHead(int x) {
	Node* newHead = new Node;
	newHead->val = x;
	newHead->prev = nullptr;
	newHead->next = head;
	head->prev = newHead;
	head = newHead;
}

int DoubleLL::deleteHead() {
	Node* newHead = head->next;
	if (newHead)
		newHead->prev = nullptr;
	int x = head->val;
	delete head;
	head = newHead;
	return x;
}

void DoubleLL::ReverseList1() {
	if (!head) return;
	Node* ptr = head;
	while (ptr->next)
		ptr = ptr->next;
	head = ptr;


	while (ptr->prev) {
		ptr->next = ptr->prev;
		ptr->prev->next = ptr;
		ptr = ptr->prev;
	}
	ptr->next = nullptr;
	head->prev = nullptr;

}

void DoubleLL::ReverseList2() { // NOT COMPLETED !
	Node* ptr = head;
	while (ptr) {
		Node* temp = ptr->next;
		ptr->next = ptr->prev;
		ptr->prev = temp;

		ptr = ptr->prev;

	}
}

int DoubleLL::Delete(int index) {
	if (index < 0) { return -1; }

	if (index == 0) { return deleteHead(); }
	Node* ptr = head;
	int i = 0;
	while (ptr->next && i < index - 1) {
		ptr = ptr->next;
		i++;
	}
	if (!ptr->next)  return -1;
	Node* toDel = ptr->next;
	int x = toDel->val;
	ptr->next = toDel->next;
	if (toDel->next)
		toDel->next->prev = ptr;
	delete toDel;
	return(x);
}

void DoubleLL::Insert(int index, int x) {
	if (index < 0) { return; }
	if (index == 0) { insertHead(x); return; }
	Node* newNode = new Node;
	newNode->val = x;
	newNode->next = nullptr;
	int i = 0;
	Node* ptr = head;

	while (ptr->next && i < index - 1) {
		ptr = ptr->next;
		i++;
	}

	if (ptr->next == nullptr) { cout << ptr->val << "ptr->val" << endl;return; }
	newNode->prev = ptr;
	newNode->next = ptr->next;
	ptr->next->prev = newNode;
	ptr->next = newNode;

}

void create(int* A, int num, Node* head) {
	head->val = A[0];
	head->prev = nullptr;
	head->next = nullptr;
	Node* tail = head;


	for (int i = 1;i < num;i++) {
		Node* newNode = new Node;
		newNode->val = A[i];
		newNode->prev = tail;
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
}

void traverse(Node* head) {
	Node* ptr = head;
	while (ptr != nullptr) {
		cout << ptr->val << endl;
		ptr = ptr->next;
	}
}

Node* DoubleLL::findMiddlePointer() {
	Node* p = head;
	Node* q = head;
	while (q) {
		q = q->next;
		if (q) q = q->next;
		if (q) p = p->next;
	}
	return p;
}

Node* DoubleLL::findIntersection(Node* head2) {
	Node* ptr = head;
	stack<Node*> s1;
	stack<Node*> s2;

	while (ptr) s1.push(ptr);
	ptr = head2;
	while (ptr) s2.push(ptr);

	ptr = nullptr;
	while (!(s1.empty() && s2.empty()))
	{
		if (s1.top() == s2.top()) {
			ptr = s1.top();
			s1.pop();
			s2.pop();
		}
		else return ptr;
	}
	return ptr;

}

int main(int argc, char const* argv[]) {
	int A[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int B[] = { 1,2,3,4,5, };

	// int A[] = { 1 };
	int n = sizeof(A) / sizeof(int);


	DoubleLL dll(A, n);
	// DoubleLL dllB(B, sizeof(B) / sizeof(int));
	// dllB.head->next->next->next->next = dll.head->next->next;
	// cout << dll.findIntersection(dllB.head)->val << endl;
	// dll.Insert(-1, 100);
	// dll.insertHead(10);
	// cout << "hey" << endl;
	// cout << "Deleted " << dll.Delete(0) << endl << endl;
	// cout << "Deleted " << dll.Delete(-1) << endl << endl;
	// cout << "Deleted " << dll.Delete(9) << endl << endl;
	// cout << "Deleted " << dll.Delete(100) << endl << endl;
	// cout << "Deleted " << dll.Delete(8) << endl << endl;
	// cout << "Deleted " << dll.Delete(5) << endl << endl;
	// cout << "Deleted " << dll.Delete(0) << endl << endl;
	// cout << "Deleted " << dll.Delete(0) << endl << endl;
	// cout << "Deleted " << dll.Delete(0) << endl << endl;
	// dll.ReverseList1();
	// dll.Display();
	cout << dll.findMiddlePointer()->val << endl;
	// Node* head1 = new Node;
	// create(A, 9, head1);
	// traverse(head1);

	return 0;
}
