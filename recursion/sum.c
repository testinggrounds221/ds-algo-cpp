#include <stdio.h>

int sum(int n) {
	if (n > 0) {
		return sum(n - 1) + n;
	}
	return 0;
}

int sumWithStaticTail(int n) {
	static int x = 0;
	if (n > 0) {
		// x++;
		return ++x + sumWithStaticTail(n - 1);
	}
	return 0;
}

int sumWithStaticHead(int n) {
	static int y = 0;
	if (n > 0) {
		// y++;
		return sumWithStaticHead(n - 1) + ++y;
	}
	return 0;
}

int main(int argc, char const* argv[])
{
	printf("Normal Sum %d \n", sum(7));
	printf("sumWithStaticHead ~ %d \n", sumWithStaticHead(7));
	printf("sumWithStaticTail ~ %d \n", sumWithStaticTail(7));


	return 0;
}
