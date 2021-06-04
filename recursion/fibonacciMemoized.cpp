#include <iostream>
using namespace std;

int memoized_arr[10];

void initialize() {
	memoized_arr[0] = 0;
	memoized_arr[1] = 1;

	for (int i = 0;i < 10;i++) {
		memoized_arr[i] = -1;
	}
}

int memoizedFib(int n) {
	int* element_pointer = &memoized_arr[n]; //  TO Change

	if (memoized_arr[n] != -1) {
		return memoized_arr[n];
	}

	if (n == 0 || n == 1) {

		return n;
	}
	memoized_arr[n] = memoizedFib(n - 2) + memoizedFib(n - 1);
	return memoized_arr[n];
}



int main(int argc, char const* argv[])
{
	initialize();
	int n;
	cin >> n;
	printf("%d", memoizedFib(n));
	return 0;
}
