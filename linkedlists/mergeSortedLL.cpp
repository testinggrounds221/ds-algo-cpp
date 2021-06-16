// ORDER OF STATEMENTS ARE VERY IMPORTANT
#include "listOperations.h"

Node* mergeSorted(Node* head, Node* head2) {
	Node* third = NULL;
	Node* last = NULL;

	if (head->value < head2->value) {
		third = last = head;

		head = head->next;
		last->next = NULL;
	}
	else {
		third = last = head2;

		head2 = head2->next;
		last->next = NULL;
	}

	while (head && head2) {
		if (head->value < head2->value) {

			last->next = head;
			last = head;

			head = head->next;
			last->next = NULL;
		}
		else {

			last->next = head2;

			last = head2;
			head2 = head2->next;
			last->next = NULL;
		}
	}
	if (head) last->next = head;

	if (head2) last->next = head2;

	head = third;
	return head;
}

int main(int argc, char const* argv[]) {
	int A[] = { 1,3,5,7,9 };
	head = arrToList(A, sizeof(A) / sizeof(int));

	int B[] = { 2,4,6,8 };

	Node* head2 = arrToList(B, sizeof(B) / sizeof(int));
	head = mergeSorted(head, head2);
	traverse(head);




	return 0;
}
