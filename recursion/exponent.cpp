#include <iostream>
using namespace std;

unsigned long long recursizeExponent(int m, int n) {
	cout << "Function Call\n";
	if (n == 0) return 1;
	else if (n % 2 == 0) return recursizeExponent(m * m, n / 2);
	else return m * recursizeExponent(m * m, (n - 1) / 2);
}


int main(int argc, char const* argv[])
{
	int m, n;
	cin >> m >> n;
	cout << recursizeExponent(m, n);
	return 0;
}

