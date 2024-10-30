#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
	Fraction f1, f2;
	Fraction f3;
	Fraction f4;
	Fraction f5;
	Fraction f6, f7, f8;

	cout << "1) ";
	f1.input();
	cout << "2) ";
	f2.input();
	cout << "3) ";
	f3.input();
	cout << "4) ";
	f4.input();
	cout << "5) ";
	f5.input();
	cout << "6) ";
	f6.input();
	cout << "7) ";
	f7.input();
	cout << "8) ";
	f8.input();

	f6 = f3;

	f7 = f1 + f5;
	f8 = f2 - f4;
	f2 = f3 * f4;
	f5 = f6 / f3;

	cout << "f2 == f3: " << (f2 == f3) << '\n';
	cout << "f3 != f1: " << (f3 != f1) << '\n';
	cout << "f2 >= f5: " << (f2 >= f5) << '\n';
	cout << "f2 >  f5: " << (f2 > f5) << '\n';
	cout << "f5 <= f3: " << (f5 <= f3) << '\n';
	cout << "f5 <  f3: " << (f5 < f3) << '\n';


	f1 = f2 + 3;
//	f1.output();
	f3 = -7 + f1;
//	f3.output();
	f5 = 7 * f3;
	f6 = f4 - 6;

	cout << "f3: " << f3 << '\n';
	cout << "f6: " << f6 << '\n';

	f1 += f5;
	f6 -= f7;
	f8 *= f1;
	f8 /= f2;

	cout << "f8++: " << f8++ << '\n';
	cout << "++f7: " << ++f7 << '\n';

	cout << "f8--: " << f8-- << '\n';
	cout << "--f7: " << --f7 << '\n';

	float f = (float) f3;
	cout << "f = (float) f3: " << f << '\n';
	return 0;
}