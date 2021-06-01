#include <iostream>
using namespace std;

class Rectangle {
private:
	int length;
	int breadth;
public:
	Rectangle(int l = 0, int b = 0) {
		length = l;
		breadth = b;
	}
	int area() { return length * breadth; }
	int perimetre() { return 2 * (length + breadth); }

	void setLength(int l) { length = l; }
	void setBreadth(int b) { breadth = b; }

	int getLength(int l) { return length; }
	int getBreadth(int l) { return breadth; }

	~Rectangle() { cout << "Destroying"; }

}r1;

int main(int argc, char const* argv[])
{
	cout << r1.area();
	return 0;
}
