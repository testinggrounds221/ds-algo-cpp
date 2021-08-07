#include <iostream>

using namespace std;

// Linked List node

class Node {

public:
	int data;
	Node* next;
};
// Hash Table
class HashTable {

public:
	Node** HT;
	HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
	void print();
	~HashTable();
};

HashTable::HashTable() {
	HT = new Node * [10];
	for (int i = 0; i < 10; i++) {
		HT[i] = nullptr;
	}
}

int HashTable::hash(int key) {
	return key % 10;
}

void HashTable::Insert(int key) {
	int hIdx = hash(key);
	Node* t = new Node;
	t->data = key;
	t->next = nullptr;
	// Case: No nodes in the linked list
	if (HT[hIdx] == nullptr) {
		HT[hIdx] = t;
	}
	else {
		Node* p = HT[hIdx];
		Node* q = HT[hIdx];
		// Traverse to find insert position
		while (p && p->data < key) {
			q = p;
			p = p->next;
		}
		// Case: insert position is first
		if (q == HT[hIdx]) {
			t->next = HT[hIdx];
			HT[hIdx] = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}
}

void HashTable::print()
{
	int i;

	for (i = 0; i < 10; i++)
	{
		Node* temp = HT[i];
		printf("chain[%d]-->", i);
		while (temp)
		{
			printf("%d -->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

int HashTable::Search(int key) {
	int hIdx = hash(key);
	Node* p = HT[hIdx];
	while (p) {
		if (p->data == key) {
			return p->data;
		}
		p = p->next;
	}
	return -1;
}

HashTable::~HashTable() {
	for (int i = 0; i < 10; i++) {
		Node* p = HT[i];
		while (HT[i]) {
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete[] HT;
}

int main() {
	int A[] = { 16, 12, 25, 39, 6, 122, 5, 68, 75, 98,49,96,99 };
	int n = sizeof(A) / sizeof(A[0]);
	HashTable H;
	for (int i = 0; i < n; i++) {
		H.Insert(A[i]);
	}
	H.print();
	// cout << "Successful Search" << endl;
	// int key = 6;
	// int value = H.Search(key);
	// cout << "Key: " << key << ", Value: " << value << endl;
	// cout << "Unsuccessful Search" << endl;
	// key = 95;
	// value = H.Search(key);
	// cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}