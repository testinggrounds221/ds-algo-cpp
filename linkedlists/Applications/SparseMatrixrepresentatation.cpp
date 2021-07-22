#include "listOperations.h"
using namespace std;

void createSparseMatrix(int A[][2], int n, Node** sparse) {


	Node* ptr = NULL;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (A[i][j] != 0) {
				Node* temp = new Node;
				temp->value = A[i][j];
				temp->index = j;
				temp->next = NULL;
				if (sparse[i] == NULL) {
					sparse[i] = temp;
				}
				else {
					ptr = sparse[i];
					while (ptr->next != NULL) {
						ptr = ptr->next;
					}
					ptr->next = temp;
				}
			}
		}
	}

}

void displaySparse(Node** sparse, int n) {
	Node* ptr = NULL;
	for (int i = 0; i < n;i++) {
		if (sparse[i] != NULL) {
			ptr = sparse[i];

		}
	}
}

int main() {
	int a[][2] = { {0,2},{3,0} };

	Node* sparse[2] = { NULL };
	createSparseMatrix(a, 2, sparse);

	return 0;
}

