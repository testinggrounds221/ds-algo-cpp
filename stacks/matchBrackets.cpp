#include "stackLinkedList.h"
#include "string.h"

void traverse1(Node* top) {
	Node* ptr = top;
	while (ptr) {
		cout << char(ptr->val) << " | ";
		ptr = ptr->next;
	}

}

int isBalanced(char* exp) {
	StckLL st;
	for (int i = 0; i < strlen(exp); i++) {
		char ch = exp[i];
		if (ch == '{' || ch == '(' || ch == '[')
			st.push(ch);
		else if (ch == '}' || ch == ')' || ch == ']') {
			if (st.isEmpty()) return 0;
			if ((ch == '}' && st.stackTop() == '{') ||
				(ch == ')' && st.stackTop() == '(') ||
				(ch == ']' && st.stackTop() == '['))
				st.pop();
			else return 0;
		}
	}
	return st.isEmpty();
}

int main(int argc, char const* argv[])
{
	char A[] = "{([a+b]*[c-d])/e}";
	cout << isBalanced(A) << endl;

	char B[] = "{([a+b]}*[c-d])/e}";
	cout << isBalanced(B) << endl;

	char C[] = "{([{a+b]*[c-d])/e}";
	cout << isBalanced(C) << endl;

	return 0;
}
// if ((ch == '}' && st.stackTop() == '{') ||
// 	(ch == ')' && st.stackTop() == '(') ||
// 	(ch == ']' && st.stackTop() == '[')) {	
// 	st.pop();
// }