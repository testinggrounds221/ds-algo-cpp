#include "stackLinkedList.h"

int main(int argc, char const* argv[])
{
	StckLL st;
	char br[5] = { '(','(',')',')' };

	for (char ch : br) {
		cout << ch;
	}
	st.push(5);
	st.push(3);
	st.push(4);
	st.push(1);
	cout << st.peek(1);
	cout << st.peek(2);
	cout << st.peek(3);

	cout << st.pop();
	cout << st.pop();
	cout << st.pop();
	cout << st.pop();
	cout << st.pop();
	cout << st.pop();
	cout << st.pop();


	st.traverse();
	return 0;
}
