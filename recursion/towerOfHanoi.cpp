#include <iostream>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C) {
	/*
	n <- Number of Towers
	A <- Source Tower
	B <- Helping Tower
	c <- Destination Tower
	*/
	if (n > 0) {
		towerOfHanoi(n - 1, A, C, B);
		cout << "Move Disk from " << A << " To " << C << endl;
		towerOfHanoi(n - 1, B, A, C);
	}
}

int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	towerOfHanoi(n, 'A', 'B', 'C');
	return 0;
}
