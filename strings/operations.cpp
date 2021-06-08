#include<iostream>
using namespace std;

int getLength(char* s) {
	int i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}

int isUpperCase(char s) {
	if (((int)(s) >= 65) && ((int)(s) <= 90))
		return 1;
	return 0;
}

int isLowerCase(char s) {
	if (((int)(s) >= 97) && ((int)(s) <= 122))
		return 1;
	return 0;
}

char toLowerCase(char c) {
	if (isLowerCase(c))
		return c;
	return (char)((int)(c)+32);
}

char toUpperCase(char c) {
	if (isUpperCase(c))
		return c;
	return (char)((int)(c)-32);
}

void reversed(char* s) {
	int last_index = getLength(s) - 1;
	for (int i = 0; i <= last_index;i++) {
		char temp = s[i];
		s[i] = s[last_index - 1];
		s[last_index - 1] = temp;
	}
}

void swapCase(char* s) {
	for (int i = 0; s[i] != '\0';i++) {
		if (isLowerCase(s[i]))
			s[i] = toUpperCase(s[i]);
		else if (isUpperCase(s[i]))
			s[i] = toLowerCase(s[i]);
	}
}

int main(int argc, char const* argv[])
{
	char name[20];
	gets(name);

	printf("%d\n", getLength(name));
	cout << isUpperCase('A') << endl;
	cout << isLowerCase('a') << endl;
	cout << toLowerCase('A') << endl;
	cout << toUpperCase('a') << endl;


	swapCase(name);
	printf("%s", name);
	reversed(name);
	printf("%s", name);

	return 0;
}
