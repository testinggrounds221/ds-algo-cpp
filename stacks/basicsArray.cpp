#include <iostream>
using namespace std;

class Stck {
public:
	int size;
	int top;
	int* s;
	Stck(int sz);
	void push(int ele);
	int peek(int pos);
	int stackTop();
	int pop();
	bool isEmpty();
	bool isFull();
	void traverse();

};

Stck::Stck(int sz) {
	size = sz;
	s = new int[size];
	top = -1;
}

void Stck::traverse() {
	if (isEmpty()) return;
	for (int i = top;i >= 0;i--) {
		cout << s[i];
	}
}
bool Stck::isEmpty() {
	return top == -1;
}

bool Stck::isFull() {
	return top == size - 1;
}

void Stck::push(int ele) {
	if (isFull()) return;
	s[++top] = ele;
}
int Stck::pop() {
	if (isEmpty()) return -1;
	int val = s[top];
	s[top--] = 0;

	return val;
}
int Stck::peek(int pos) {
	int ind = top - pos + 1;
	if (ind < 0 || top - pos + 1 == size) return -1;
	return s[ind];
}

int Stck::stackTop() {
	if (isEmpty()) return -1;
	return s[top];
}

int main(int argc, char const* argv[])
{
	int inp_sz = 0;
	// cout << "Enter Size of Stack" << endl;
	// cin >> inp_sz;
	inp_sz = 5;
	Stck st(inp_sz);

	st.push(5);
	st.push(3);
	st.push(4);
	st.push(1);
	cout << st.peek(1);
	// cout << st.peek(2);
	// cout << st.peek(3);

	// cout << st.pop();
	// cout << st.pop();
	// cout << st.pop();
	// cout << st.pop();
	// cout << st.pop();
	// cout << st.pop();
	// cout << st.pop();


	st.traverse();
	return 0;
}

