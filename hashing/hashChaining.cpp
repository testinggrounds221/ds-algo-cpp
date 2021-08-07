#include<iostream>
using namespace std;
// AFTER DELETING FIRST NODE, GARBAGE NODES ARE ATTACHED
class Node {
public:
	int key;
	Node* next;
};

class ChainHash {
public:
	int size;
	Node** HT;
	ChainHash(int sz);

	int Search(int key);
	void insert(int key);
	int Delete(int ket);
	int hash(int index);
	void print();

};

ChainHash::ChainHash(int sz) {
	size = sz;
	HT = new Node * [size];
	for (int i = 0;i < size;i++)
		HT[i] = nullptr;
}

int ChainHash::hash(int ind) {
	return ind % size;
}

int ChainHash::Search(int key) {
	int hash_ind = hash(key);
	Node* ptr = HT[hash_ind];
	while (ptr && ptr->key <= key) {
		if (ptr->key == key) return ptr->key;
		ptr = ptr->next;
	}
	return -1;
}

void ChainHash::insert(int k) {
	Node* ptr = new Node;
	ptr->next = NULL;
	ptr->key = k;

	int hash_index = hash(k);
	if (!HT[hash_index]) {
		HT[hash_index] = ptr;
	}
	else {
		Node* temp = HT[hash_index];
		while (temp->next) temp = temp->next;
		temp->next = ptr;
	}
}

int ChainHash::Delete(int k) {
	int hash_ind = hash(k);
	Node* temp = HT[hash_ind];
	if (temp) {
		if (temp->key == k) {
			Node* del = temp;
			if (!temp->next) HT[hash_ind] = nullptr;
			else temp = temp->next;
			delete del;
			return k;
		}
		else
		{
			while (temp->next) {
				if (temp->next->key == k) {
					Node* del = temp->next;
					temp->next = temp->next->next;
					delete del;
					return k;
				}
				temp = temp->next;
			}
		}
	}
	return -1;
}

void ChainHash::print()
{
	int i;

	for (i = 0; i < size; i++)
	{
		Node* temp = HT[i];
		printf("chain[%d]-->", i);
		while (temp)
		{
			printf("%d -->", temp->key);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

int main(int argc, char const* argv[])
{
	ChainHash ch(10);
	for (int i = 0;i < 10;i++) {
		ch.insert(i);
	}
	cout << "After Inserting : " << endl;
	ch.print();

	// for (int j = 0;j < 10;j++) {
	// 	cout << ch.Delete(j) << endl;
	// }	
	// ch.print();
	// ch.insert(31);
	// ch.print();
	// ch.Delete(31);
	// ch.print();

	ch.Delete(1);
	ch.print();

	// cout << ch.Delete(31) << endl;

	// cout << ch.Delete(3) << endl;
	// ch.print();



	return 0;
}
