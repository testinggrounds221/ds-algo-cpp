#include<iostream>
using namespace std;

class Term {
public:
	int coef;
	int exp;
};

class Polynomial {
public:
	int n;
	Term* t;
	Polynomial(int n) {
		this->n = n;
		t = new Term[this->n];
	}

};

int main(int argc, char const* argv[]) {
	/* code */
	return 0;
}