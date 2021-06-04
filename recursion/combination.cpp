#include <iostream>
using namespace std;

int dynamic_combinations[10][10];
void initialize() {

	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			dynamic_combinations[i][j] = -1;
		}
	}
}
int memoizedCombination(int n, int r) {//USE POINTER FOR OPTIMIZATIONS
	if (dynamic_combinations[n][r] != -1) return dynamic_combinations[n][r];

	if (n == r || r == 0) return 1;
	dynamic_combinations[n][r] = memoizedCombination(n - 1, r - 1) + memoizedCombination(n - 1, r);
	return dynamic_combinations[n][r];
}

int Combination(int n, int r) {
	if (n == r || r == 0) {
		return 1;
	}
	return Combination(n - 1, r - 1) + Combination(n - 1, r);
}

int main(int argc, char const* argv[])
{
	initialize();
	int n, r;
	cin >> n >> r;
	printf("%d", memoizedCombination(n, r));
	return 0;
}
