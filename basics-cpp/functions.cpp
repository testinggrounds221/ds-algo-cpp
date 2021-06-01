#include <iostream>
using namespace std;

int factorial(int n) // PROTOTYPE; n-> Formal Parametre
// BODY OF FUNCTION
{
	if (n == 1) return 1;
	else return n * factorial(n - 1);
}
// BODY OF FUNCTION

void swapByReference(int& x, int& y) {
	int z = x;
	x = y;
	y = z;
}

void swapByAddress(int* r, int* s) {
	int t = *r;
	*r = *s;
	*s = t;
}

int main(int argc, char const* argv[])
{
	cout << factorial(5) << endl;
	// 5 is Actual Parametre
	int a = 12, b = 10;
	cout << "\nSwapping by Reference" << endl;
	cout << "\na = " << a << " b = " << b;
	swapByReference(a, b);
	cout << "\na = " << a << " b = " << b << endl;


	int p = 0, q = 1;
	int* p_ptr = &p;
	cout << "\nSwapping by Reference" << endl;

	cout << "\np = " << p << " q = " << q;
	swapByAddress(&p, &q);
	cout << "\np = " << p << " q = " << q;


	return 0;
}
