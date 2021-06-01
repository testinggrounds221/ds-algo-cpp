#include <iostream>
using namespace std;

template <typename T, typename U>
class Arithmetic {
private:
	T a;
	U b;
public:
	Arithmetic(T x, U y) { a = x; b = y; }
	U add() { return a + b; }
	U sub() { return a - b; }
	U multiply();
};


template<class T, class U>
U Arithmetic<T, U>::multiply() { return this->a * this->b; }


// U Arithmetic::multiply(){
// 	cout
// }


int main(int argc, char const* argv[])
{
	Arithmetic <int, double>a1(5, 6.0);
	cout << a1.add() << endl;
	cout << a1.multiply() << endl;

	return 0;
}
