#include <iostream>
#include "IntArray.h"

using namespace std;

int main() {
	IntArray m1;
	IntArray m2;

	IntArray m3;
	IntArray m4;
	IntArray m5;

	cout << "[INPUT M1]\n";
	m1.input();
	cout << "[INPUT M2]\n";
	m2.input();
	cout << "[INPUT M3]\n";
	m3.input();
	cout << "[INPUT M4]\n";
	m4.input();
	cout << "[INPUT M5]\n";
	m5.input();

	m5 = m2;

	cin >> m2;
	cout << m2 << '\n';

	cout << m3[3] << '\n';
	m3[4] = 1;

	cout << (int) m4 << '\n';
	return 0;
}