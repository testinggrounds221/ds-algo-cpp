#include<stdio.h>
#include<string.h>
struct stak {
	int stax[20];
	int top;
};
int N = 20;
struct stak s = { {},-1 };

void push(char n);

char pop();

int isoperator(char t);

char top();

int pri(char t);

int main() {
	char exp[20], pfix[20], token, toptoken, tokenout;
	int cnt = 0;
	printf("Enter the infix expression");
	gets(exp);
	while (cnt <= strlen(exp))
	{
		token = exp[cnt];
		if (token == '(') {
			push(token);
		}
		else if (!strcmp(token, ")"))
		{
			token = pop();
			while (strcmp(token, "(")) {
				strcat(pfix, token);
				token = pop();
			}

		}
		else if (isoperator(token)) {
			toptoken = top();
			while (s.top != -1 && pri(token) < pri(toptoken))
			{
				tokenout = pop();
				strcat(pfix, tokenout);
				toptoken = top();
			}
			push(token);

		}
		else {
			strcat(pfix, token);
		}
		cnt = cnt + 1;
	}
	while (s.top != -1)
	{
		token = pop();
		strcat(pfix, token);
	}

	printf("%s", pfix);
	return 0;
}

void push(char n) {

	if (s.top == N - 1) {
		printf("stack is full \n");
	}
	else {

		s.top = s.top + 1;
		s.stax[s.top] = n;

	}
	return;
}

char pop() {
	int n, i;
	if (s.top == -1)
	{
		printf("stack is empty\n");
	}
	else {
		n = s.stax[s.top];
		s.top = s.top - 1;
		return n;
	}

}

int isoperator(char t) {
	if (strcmp(t, "+") || strcmp(t, "-") || strcmp(t, "*") || strcmp(t, "/")) {
		return 1;
	}
	else {
		return 0;

	}
}

char top() {
	return s.top;
}

int pri(char t)
{
	switch (t)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}