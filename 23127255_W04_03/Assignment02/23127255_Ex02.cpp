#include <iostream>

using namespace std;

#include "Date.h"

int main() {
//	Date d1;
//	Date d2;
//	Date d3;
//	Date d4;
//	Date d5;
//	Date d6;
//	d1.input();
//	d2.input();
//	d3.input();
//	d4.input();
//	d5.input();
//	d6.input();
	Date d1(2, 1, 1);
	Date d2(1, 1, 1);
	Date d3(31, 12, 2020);
	Date d4(28, 2, 2020);
	Date d5(29, 2, 2020);
	Date d6(30, 2, 2020);

	d2 = d3;

	d4 = d4.tomorrow();
	d5 = d5.yesterday();

	cout << d6.tomorrow() << '\n';
	cout << d6.yesterday() << '\n';

	cout << (d6 == d4) << '\n';
	cout << (d6 != d4) << '\n';
	cout << (d6 >= d4) << '\n';
	cout << (d6 <= d4) << '\n';
	cout << (d6 > d4) << '\n';
	cout << (d6 < d4) << '\n';

	d3 = d2 + 1;
	d2 = d3 - 2;
	d4++;
	++d2;
	d5--;
	--d6;

	cout << d3 << '\n';
	cin >> d4;

	cout << (int) d3 << '\n';            // from the first day of current year
	cout << (long) d4 << '\n';        // from 1/1/1

	Date d7;
	d7 += 7;
	d2 -= 6;
	return 0;
}