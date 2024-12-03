#include <iostream>
#include "vector.h"
#include "fraction.h"

using namespace std;

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int n = 5;
	MyVector<int> v(a, n);
	cout << v.toString() << "\n";
	int a2[] = {6, 7, 8};
	v.addRange(a2, 3);
	cout << v.toString() << "\n";
	Fraction f[] = {
		{1, 2},
		{2, 3},
		{3, 4}
	};
	MyVector<Fraction> v2(f, 3);
	cout << v2.toString() << '\n';
	return 0;
}
