#include <iostream>
using namespace std;

// e^x = 1 + x/1! + (x^2)/2! + (x^3)/3! + ... n terms

double taylorNaive(int x, int n) {
	static double p = 1, f = 1;


	double r;
	if (n == 0) { return 1; }
	else {
		r = taylorNaive(x, n - 1);
		p = p * x;
		f = f * n;
		return r + (p / f);
	}
}

double taylorHorner(int x, int n) {
	static double s;
	if (n == 0)return s;
	s = 1 + (x * s / n);
	return taylorHorner(x, n - 1);
}



int main(int argc, char const* argv[])
{
	int x, n;
	cin >> x >> n;
	cout << taylorNaive(x, n) << endl;
	cout << taylorHorner(x, n);

	return 0;
}

