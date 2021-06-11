#include<iostream>
using namespace std;

class Element {
public:
	int i;
	int j;
	int x;
};

class Sparse {
public:
	Element* ele;
	int m;
	int n;
	int num;

	Sparse(int m, int n, int num)
	{
		this->m = m;
		this->n = n;
		this->num = num;
		ele = new Element[this->num];
	}

	Sparse add(Sparse s2) {
		int i, j, k;
		if (m != s2.m || n != s2.n)
			return Sparse(0, 0, 0);

		Sparse sum(m, n, m + s2.m);
		while ((i < num) && (j < s2.num)) {
			if (ele[i].i < s2.ele[j].i)
				sum.ele[k++] = ele[i++];
			else if (ele[i].i > s2.ele[j].i)
				sum.ele[k++] = s2.ele[j++];
			else {
				if (ele[i].j < s2.ele[j].j)
					sum.ele[k++] = ele[i++];
				else if (ele[i].j > s2.ele[j].j)
					sum.ele[k++] = s2.ele[j++];
				else {
					sum.ele[k] = ele[i];
					sum.ele[k++].x = ele[i++].x + s2.ele[j++].x;
				}
			}
		}


		for (;i < num;i++)sum.ele[k++] = ele[i];
		for (;j < s2.num;j++)sum.ele[k++] = s2.ele[j];
		sum.num = k;
		return sum;

		// if ((m != s2.m) || (n != s2.n)) return 0;

	}

	friend istream& operator>>(istream& is, Sparse& s);
	friend ostream& operator<<(ostream& is, Sparse& s);

	void create()
	{
		int i;
		for (i = 0;i < num;i++)
			cin >> ele[i].i >> ele[i].j >> ele[i].x;
	}
	void display()
	{
		int i, j, k = 0;
		for (i = 0;i < m;i++) {
			for (j = 0;j < n;j++) {
				if (i == ele[k].i && j == ele[k].j)
					printf("%d ", ele[k++].x);
				else
					printf("0 ");
			}
			printf("\n");
		}
	}
};

ostream& operator<<(ostream& is, Sparse& s) {
	int i;
	for (i = 0;i < s.num;i++)
		cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
}

istream& operator>>(istream& is, Sparse& s) {
	int i, j, k = 0;
	for (i = 0;i < s.m;i++) {
		for (j = 0;j < s.n;j++) {
			if (i == s.ele[k].i && j == s.ele[k].j)
				printf("%d ", s.ele[k++].x);
			else
				printf("0 ");
		}
		printf("\n");
	}
}


int main(int argc, char const* argv[])
{
	Sparse s(2, 2, 1);
	s.create();
	s.display();

	Sparse s2(2, 2, 1);
	s2.create();
	s2.display();

	cout << "Sum" << endl;
	s.add(s2).display();

	return 0;
}
