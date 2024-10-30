#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction {
private:
	int num;
    int denom;
public:
	Fraction();
	Fraction(int num, int denom);
	Fraction(const Fraction &other);

	Fraction &input();
	Fraction &output();
	Fraction &setNum(int num);
	Fraction &setDenom(int denom);
	Fraction &set(int num, int denom);
	int getNum() const;
	int getDenom() const;

	Fraction &reduce();
	int compare(const Fraction& f) const;
	bool isPositive() const;
	bool isNegative() const;
	bool isZero() const;
	Fraction operator+(Fraction &f) const;
	Fraction operator-(Fraction &f) const;
	Fraction operator*(Fraction &f) const;
	Fraction operator/(Fraction &f) const;
	Fraction operator+(int x) const;
	Fraction operator-(int x) const;
	Fraction operator*(int x) const;
	Fraction operator/(int x) const;

	Fraction &operator=(const Fraction &f);
	Fraction &operator=(int x);
	void operator+=(Fraction &f);
	void operator-=(Fraction &f);
	void operator*=(Fraction &f);
	void operator/=(Fraction &f);
	void operator+=(int x);
	void operator-=(int x);
	void operator*=(int x);
	void operator/=(int x);

	bool operator==(Fraction &f) const;
	bool operator!=(Fraction &f) const;
	bool operator<(Fraction &f) const;
	bool operator<=(Fraction &f) const;
	bool operator>(Fraction  &f) const;
	bool operator>=(Fraction &f) const;

	friend std::ostream& operator<<(std::ostream &os, const Fraction &f);
	friend std::istream& operator>>(std::istream &is, Fraction &f);
	friend Fraction operator+(int lhs, Fraction& rhs);
	friend Fraction operator-(int lhs, Fraction& rhs);
	friend Fraction operator*(int lhs, Fraction& rhs);
	friend Fraction operator/(int lhs, Fraction& rhs);

	operator float() const;
	operator double() const;

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
};

#endif // FRACTION_H
