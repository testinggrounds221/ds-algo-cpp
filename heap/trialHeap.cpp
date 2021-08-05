#include <iostream>

using namespace std;
//FULLY MESSED UP
class Heap {
public:
	int* A;
	int capacity;
	int heap_size;
	Heap(int capacity);

	void insert(int n);
	int Delete();
	void display();
	void displayAll();

};
Heap::Heap(int sz) {
	this->capacity = sz;
	heap_size = 0;
	A = new int[capacity + 1];
	for (int i = 0;i <= capacity;i++) {
		A[i] = 0;
	}
}
void Heap::insert(int n) {
	int i = heap_size + 1;

	while (i > 1 && A[i / 2] < n) {
		A[i] = A[i / 2];
		i = i / 2;
	}
	A[i] = n;
	heap_size++;
	cout << "Cuurent Heap Size" << heap_size << endl;
	return;
}

void Heap::display() {
	for (int i = 1;i <= heap_size;i++) {
		cout << A[i] << " ";
	}
}

void Heap::displayAll() {
	for (int i = 1;i <= capacity;i++) {
		cout << A[i] << " ";
	}
}

int Heap::Delete() {
	int val = A[1]; // Value to be Deleted
	A[1] = A[heap_size]; // Least value to the top.. To be compared with children
	int x = A[heap_size]; // Dummy variable to compare
	A[heap_size] = val; // Deleted value to be added at last

	int i = 1; int j = 2 * i;
	while (j < heap_size - 1) {
		if (A[j] > A[j + 1]) j = j + 1;
		if (A[i] < A[j]) {
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;

			i = j; j = 2 * j;
		}
		else break;
	}
	heap_size--;
	return val;
}

int main(int argc, char const* argv[])
{
	Heap hp(20);
	// hp.A[1] = 0;	
	hp.insert(20);
	hp.insert(30);
	hp.insert(40);
	hp.insert(50);
	hp.insert(60);
	hp.insert(70);
	hp.insert(80);
	hp.insert(90);
	hp.insert(100);
	hp.insert(10);

	hp.display();
	cout << endl << "Deleting Mode" << endl;
	cout << hp.Delete();
	cout << hp.Delete();
	cout << hp.Delete();
	cout << hp.Delete();
	cout << hp.Delete();
	cout << hp.Delete();
	cout << hp.Delete();
	cout << hp.Delete();
	cout << hp.Delete();
	cout << hp.Delete();

	cout << endl << "Deleting Mode" << endl;
	hp.displayAll();

	return 0;
}

