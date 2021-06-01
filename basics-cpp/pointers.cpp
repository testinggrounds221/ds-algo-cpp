#include <iostream>
using namespace std;

// Ireeespective of datatype, pointer takes same memory

struct Rectangle
{
	int length;
	int breadth;
}r1{ 1,2 };



int main(int argc, char const* argv[])
{
	/* code */
	int a = 10;
	int* p = &a;
	// cout << "Dereferencing " <<*p<<endl;
	// cout << "Address of variable " <<p<<endl;


	int A[5] = { 1,3,5,7,9 };
	int* arr_ptr = A;// For Arrays the name of the array itself is Address
	//int *arr_ptr=&A[0]; Alternative
	cout << A << endl;
	for (int i = 0; i < sizeof(A) / sizeof(int); i++)
	{
		// cout << A[i]<<endl;
		// cout << arr_ptr[i]<<endl;
	}


	Rectangle r2{ 12,24 };
	Rectangle* struc_ptr;
	*struc_ptr = r1;
	cout << struc_ptr->breadth;
	// We cannot use *p.breadth because '.' operator is given precedence
	return 0;
}
