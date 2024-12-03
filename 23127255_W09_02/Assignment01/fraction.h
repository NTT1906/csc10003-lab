#ifndef INC_23127255_W09_FRACTION_H
#define INC_23127255_W09_FRACTION_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Fraction{
	int num;
	int den;
public:
	Fraction();
	Fraction(int num, int den = 1);
	Fraction(const string &s);

	Fraction &set(int num, int den);
	Fraction &setNum(int num);
	Fraction &setDen(int den);
	int getNum() const;
	int getDen() const;

	Fraction &reduce();
	static Fraction reduceCopy() ;

	Fraction operator+(const Fraction &other) const;
	Fraction operator-(const Fraction &other) const;
	Fraction operator*(const Fraction &other) const;
	Fraction operator/(const Fraction &other) const;

	bool operator<(const Fraction &other) const;
	bool operator>(const Fraction &other) const;
	bool operator<=(const Fraction &other) const;
	bool operator>=(const Fraction &other) const;

	friend std::ostream& operator<<(std::ostream& os, const Fraction &f);

	operator float() const;
	operator double () const;
};

#endif //INC_23127255_W09_FRACTION_H