#include "stackLinkedList.h"
#include <string.h>

bool isOperand(char c) {
	if (c == '+' || c == '*' || c == '/' || c == '-' || c == ')' || c == '(' || c == '^') return 0;
	return 1;
}

int precedence(char c, int loc) {
	// LOC -> in-stack 1 and out-stack 0
	if (c == '+' || c == '-') {
		if (loc) return 2;
		return 1;
	}
	if (c == '*' || c == '/') {
		if (loc) return 4;
		return 3;
	}
	if (c == '^') {
		if (loc) return 5;
		return 6;
	}
	if (c == '(') {
		if (loc) return 0;
		return 7;
	}
	if (c == ')') {
		if (!loc) return 0;
	}
	return 0;
}

string convert(string infix) {
	string postfix;
	StckLL st;
	st.push('#');
	int i = 0;
	int j = 0;
	while (infix[i]) {
		// ONLY INCREMENT i IF OPERAND OR GREATER PRECENDENCE THAN STACK TOP
		// CHECK WITH SAME CUREENT i AFTER POPPING
		// SO WHILE LOOP USED
		if (isOperand(infix[i])) postfix.push_back(infix[i++]);
		else {
			if (precedence(infix[i], 0) > precedence(st.stackTop(), 1)) st.push(infix[i++]);
			else if (precedence(infix[i], 0) == precedence(st.stackTop(), 1)) {
				// FOR BRACKETS, IF SAME PREC, (OPENING AND CLOSING),
				// POP OUT OPENING and PROCEED TO NEXT CHARACTER
				st.pop();
				i++;
			}
			else postfix.push_back(st.pop());
		}
	}
	while (!st.isEmpty()) postfix.push_back(st.pop());
	return postfix;
}

int main(int argc, char const* argv[])
{
	string infix = "(a+b)*c-d^e^f";
	string postfix = convert(infix);
	cout << postfix;
	return 0;

}
// abc*de/+# 	mine
// abc*+de/-# 	abdul;