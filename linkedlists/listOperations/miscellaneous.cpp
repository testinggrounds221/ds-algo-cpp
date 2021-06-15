#include "listOperations.h"


// int isSorted() {
// 	if (!head) return 0;
// 	Node* ptr = head;
// 	while (ptr->next) {
// 		if (ptr->value > ptr->next->value)
// 			return 0;
// 		ptr = ptr->next;
// 	}
// 	return 1;
// }

int main(int argc, char const* argv[])
{
	int A[] = {};
	head = arrToList(A, sizeof(A) / sizeof(int));
	cout << isSorted() << endl;
	return 0;
}
