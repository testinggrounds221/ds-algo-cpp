#include <iostream>
using namespace std;

// Refernce is "nick nme" gven to variable

int main(int argc, char const* argv[])
{
	/* code */

	int a = 10;
	int* pointer = &a;
	int& reference = a; // Now, A can be accessed, modified using reference
						// Cannot be changed later

	a++;
	*pointer = *pointer + 1;
	reference++;

	cout << a << endl;


	return 0;
}
