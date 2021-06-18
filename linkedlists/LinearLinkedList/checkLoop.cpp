// ORDER OF STATEMENTS ARE VERY IMPORTANT
#include "listOperations.h"

int checkLoop() {
	Node* ptr = head, * q = head;
	do {
		ptr = ptr->next;
		q = q->next;
		if (q)
			q = q->next;

	} while (ptr && q && ptr != q);

	if (ptr == q) return 1;
	return 0;

}

int main(int argc, char const* argv[]) {
	int A[] = { 10,20,30,40,50 };
	head = arrToList(A, sizeof(A) / sizeof(int));

	Node* t1, * t2;

	t1 = head->next->next;
	t2 = head->next->next->next->next;
	t2->next = t1;

	printf("%d\n", checkLoop());


	return 0;
	return 0;
}
