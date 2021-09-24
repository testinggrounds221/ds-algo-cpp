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
	f = 0;
	r = 0;
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
bool CircularQueue<T>::isFull() { return (r + 1) % size == f; }

template <typename T>
bool CircularQueue<T>::isEmpty() { return r == f; }

template <typename T>
void CircularQueue<T>::enqueue(T val) {
	if (isFull()) { cout << "Overflow";return; }
	r = (r + 1) % size;
	Q[r] = val;
}

template <typename T>
T CircularQueue<T>::dequeue() {
	if (isEmpty()) return 0;
	f = (f + 1) % size;
	return Q[f];
}

template <typename T>
void CircularQueue<T>::traverse() {
	int i = f + 1;
	do {
		cout << Q[i] << "->";
		i = (i + 1) % size;
	} while (i != (r + 1) % size);

}

int main(int argc, char const* argv[])
{
	CircularQueue<int> q(5);
	q.enqueue(20);
	q.enqueue(21);
	q.enqueue(22);
	q.enqueue(500);


	// q.enqueue(20);
	// q.enqueue(20);
	q.dequeue();
	// q.dequeue();
	// q.dequeue();
	// q.dequeue();
	// q.enqueue(20);
	// q.enqueue(20);
	// q.enqueue(20);
	// q.enqueue(20);		

	q.traverse();
	return 0;
}
