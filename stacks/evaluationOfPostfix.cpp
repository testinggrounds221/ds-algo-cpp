#include "stackLinkedList.h"
#include <string.h>

bool isOperand(char c) {
	if (c == '+' || c == '*' || c == '/' || c == '-' || c == ')' || c == '(' || c == '^') return 0;
	return 1;
}

int operate(int op1, int op2, char opr) {
	if (opr == '+')  return op1 + op2;
	if (opr == '-')  return op1 - op2;
	if (opr == '*')  return op1 * op2;
	if (opr == '/')  return op1 / op2;
	return 0;
}

int evaluate(string postfix) {
	int i = 0;
	StckLL st;
	int op1 = 0;
	int op2 = 0;
	char opr = ' ';

	while (postfix[i]) {
		if (isOperand(postfix[i])) {
			int op = postfix[i] - '0';
			st.push(op);
		}
		else {
			op2 = st.pop();
			op1 = st.pop();
			opr = postfix[i];
			st.push(operate(op1, op2, opr));
		}
		i++;
	}
	return st.pop();
}

int main(int argc, char const* argv[])
{
	cout << evaluate("35*62/+4-") << endl;


	return 0;
}
