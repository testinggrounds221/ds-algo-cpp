#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	Node<T>* next;
	T val;
};

template <typename L>
class QueueLL {
public:
	Node<L>* f;
	Node<L>* r;

	QueueLL();
	void enqueue(L x);
	L dequeue();
	bool isFull();
	bool isEmpty();
	void traverse();
};



template <typename L>
QueueLL<L>::QueueLL() {
	f = nullptr;
	r = nullptr;
}

template <typename L>
bool QueueLL<L>::isEmpty() {
	return f == nullptr;
}

template <typename L>
L QueueLL<L>::dequeue() {
	if (isEmpty()) return 0;
	Node<L>* t = f;
	L val = f->val;
	f = f->next;
	delete t;
	return val;

}

template <typename L>
void QueueLL<L>::traverse() {
	Node<L>* ptr = f;
	while (ptr) {
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
}

template <typename L>
void QueueLL<L>::enqueue(L x) {
	Node<L>* t = new Node<L>;
	if (!t) return;//HEAP FULL
	t->val = x;
	t->next = nullptr;
	if (f == nullptr) f = t;
	else r->next = t;
	r = t;
}



int main(int argc, char const* argv[])
{
	QueueLL<int> qll;
	qll.enqueue(5);
	qll.enqueue(51);
	qll.enqueue(25);
	qll.dequeue();
	qll.dequeue();
	qll.dequeue();
	qll.dequeue();
	qll.traverse();
	return 0;
}
