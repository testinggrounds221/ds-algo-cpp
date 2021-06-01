#include <iostream>
using namespace std;

struct Rectangle {
	int length;
	int breadth;
}r1{ 12,100 };

int areaByAddress(Rectangle* ptr) { return ptr->breadth * ptr->length; }
int areaByReference(Rectangle& ptr) { return ptr.breadth * ptr.length; }


int main(int argc, char const* argv[])
{
	cout << areaByAddress(&r1) << endl;
	cout << areaByReference(r1) << endl;

	return 0;
}

