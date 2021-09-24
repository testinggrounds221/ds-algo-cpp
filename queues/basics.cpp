#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
public:
	int size;
	int f;
	int r;
	T* Q;

	CircularQueue(int sz);
	~CircularQueue();
	bool isFull();
	bool isEmpty();
	void enqueue(T val);
	T dequeue();
	void traverse();

};

template <typename T>
CircularQueue<T>::CircularQueue(int sz) {
	f = -1;
	r = -1;
	size = sz;
	Q = new T[size];
}

template <typename T>
CircularQueue<T>::~CircularQueue() {
	delete[] Q;
}

// template <typename T>
// void Queue<T>::enqueue(int val) {
// }
template <typename T>
bool CircularQueue<T>::isFull() { return r == size - 1; }

template <typename T>
bool CircularQueue<T>::isEmpty() { return r == f; }

template <typename T>
void CircularQueue<T>::enqueue(T val) {
	if (isFull()) return;
	Q[++r] = val;
}

template <typename T>
T CircularQueue<T>::dequeue() {
	if (isEmpty()) {
		printf("dd");
		return 0;
	}
	return Q[++f];
}

template <typename T>
void CircularQueue<T>::traverse() {
	for (int i = f + 1;i <= r;i++) cout << Q[i] << "->";
}

int main(int argc, char const* argv[])
{
	CircularQueue<int> q(5);
	// q.enqueue(20);
	// q.enqueue(21);
	// q.enqueue(22);

	// q.dequeue();
	q.enqueue(500);
	q.enqueue(100);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	printf("Over");


	// q.dequeue();
	// q.dequeue();
	// q.dequeue();
	// q.dequeue();
	// q.enqueue(20);
	// q.enqueue(20);
	// q.enqueue(20);
	// q.enqueue(20);	
	// cout << q.dequeue();

	q.traverse();
	return 0;
}
