#include "stackLinkedList.h"
#include <string.h>

bool isOperand(char c) {
	if (c == '+' || c == '*' || c == '/' || c == '-') return 0;
	return 1;
}

int precedence(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '/' || c == '*') return 2;
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
			if (precedence(infix[i]) > precedence(st.stackTop())) st.push(infix[i++]);
			else postfix.push_back(st.pop());
		}
	}
	while (!st.isEmpty()) postfix.push_back(st.pop());
	return postfix;
}

int main(int argc, char const* argv[])
{
	string infix = "a+b*c-d/e";
	string postfix = convert(infix);
	cout << postfix;
	return 0;

}
// abc*de/+# 	mine
// abc*+de/-# 	abdul;