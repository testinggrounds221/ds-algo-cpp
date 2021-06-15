#include "listOperations.h"

// int deleteIndex(int index) {
// 	if (head == NULL) return -1;
// 	if (index == 1) {
// 		Node* tempHead = head;
// 		head = head->next;
// 		int deletedValue = head->value;
// 		delete tempHead;
// 		return deletedValue;
// 	}
// 	Node* ptr = head;
// 	int i = 1;
// 	while (i < index - 1 && ptr) {
// 		i++;
// 		ptr = ptr->next;
// 	}
// 	if (ptr == NULL || ptr->next == NULL) return -1;
// 	int deletedValue = ptr->next->value;
// 	ptr->next = ptr->next->next;
// 	delete ptr->next;
// 	return deletedValue;
// }

// void deleteNode(Node* deletePtr) {
// 	if (head == NULL || deletePtr == NULL) return;
// 	if (deletePtr == head) {
// 		head = head->next;
// 		return;
// 	}
// 	Node* ptr = head;
// 	while (ptr && ptr->next != deletePtr) {
// 		ptr = ptr->next;
// 	}
// 	ptr->next = ptr->next->next;
// 	delete ptr->next;
// }


int main(int argc, char const* argv[])
{
	int A[] = { 1,6,23,45,50 };
	head = arrToList(A, sizeof(A) / sizeof(int));
	cout << "Inital List :	" << endl;
	traverse(head);

	cout << "Delete in List :	" << endl;
	deleteNode(getPointer(20));
	traverse(head);

	cout << "Delete in List :	" << endl;
	deleteIndex(8);
	traverse(head);

	return 0;
}
