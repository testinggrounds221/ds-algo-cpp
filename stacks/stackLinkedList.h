#include <iostream>
using namespace std;

class Node {
public:
	Node* next;
	int val;
};

class StckLL {
public:
	int size;
	Node* top;

	StckLL();
	~StckLL();

	bool isEmpty();
	bool isFull();
	void traverse();
	void push(int ele);
	int peek(int pos);
	int stackTop();
	int pop();

};

int StckLL::stackTop() {
	if (!isEmpty()) return top->val;
	return -1;
}
StckLL::~StckLL() {
	Node* p = top;
	while (top) {
		top = top->next;
		delete p;
		p = top;
	}
}
StckLL::StckLL() {
	top = nullptr;
}

bool StckLL::isEmpty() {
	return !top;
}

bool StckLL::isFull() {
	Node* p = new Node;
	bool isFull = p;
	delete p;
	return isFull;
}
void StckLL::push(int ele) {
	Node* temp = new Node;
	temp->val = ele;
	temp->next = top;
	top = temp;
}

void StckLL::traverse() {
	Node* ptr = top;
	while (ptr) {
		cout << ptr->val << " | ";
		ptr = ptr->next;
	}

}

int StckLL::pop() {
	if (isEmpty()) return -1;
	Node* p = top;
	int popVal = top->val;
	top = top->next;
	delete p;
	return popVal;
}

int StckLL::peek(int pos) {
	if (isEmpty()) return -1;
	Node* ptr = top;
	int i = 0;
	while (ptr && i < pos - 1) {
		i++;
		ptr = ptr->next;
	}
	if (ptr) return ptr->val;
	return -1;
}