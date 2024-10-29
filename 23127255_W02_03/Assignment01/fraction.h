#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction {
private:
	int num;
    int denom;
	int gcd(int a, int b);
public:
	void input();
	void output();

	Fraction *setNum(int num);
	int getNum();

	Fraction *setDenom(int denom);
	int getDenom();

	Fraction add(Fraction f);
	Fraction sub(Fraction f);
	Fraction mul(Fraction f);
	Fraction div(Fraction f);
	Fraction *reduce();
	int compare(Fraction f);
	bool isPositive();
	bool isNegative();
	bool isZero();

	Fraction(int num, int den);
};

#endif // FRACTION_H
