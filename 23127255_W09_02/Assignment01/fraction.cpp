#include "fraction.h"

Fraction::Fraction() : num{0}, den{1} {}
Fraction::Fraction(int _num, int _den) : num{_num} {
	if (_den == 0) {
		throw std::invalid_argument("Error: Denominator cannot be zero.");
	}
	den = _den;
	reduce();
}

Fraction::Fraction(const string &s) {
	if (s.empty()) {
		return;
	}
	unsigned long long pos = s.find_first_not_of(",;/:");

	if (pos == 0) {
		den = 1;
		return;
	}

	try {
		num = std::stoi(s.substr(0, pos));
		if (pos != string::npos && pos != s.size() - 1) {
			den = std::stoi(s.substr(pos + 1));
			if (den == 0) {
				throw std::invalid_argument("Error: Denominator cannot be zero.");
			}
		} else {
			den = 1;
		}
	} catch (const std::invalid_argument &e) {
		throw std::invalid_argument("Error: Non-numeric value found. " + string(e.what()));
	} catch (const std::out_of_range &e) {
		throw std::invalid_argument("Error: Value out of range. " + string(e.what()));
	}
	reduce();
}

Fraction Fraction::operator+(const Fraction &other) const {
	Fraction f = {num * other.den + other.num * den, den * other.den};
	return f.reduce();
}

Fraction Fraction::operator-(const Fraction &other) const {
	Fraction f = {num * other.den - other.num * den, den * other.den};
	return f.reduce();
}

Fraction Fraction::operator*(const Fraction &other) const {
	Fraction f = {num * other.num, den * other.den};
	return f.reduce();
}

Fraction Fraction::operator/(const Fraction &other) const {
	if (other.num == 0) {
		throw std::invalid_argument("Error: Division by zero");
	}
	Fraction f = {num * other.den, den * other.num};
	return f.reduce();
}

bool Fraction::operator<(const Fraction &other) const {
	return num * other.den < other.num * den;
}

bool Fraction::operator>(const Fraction &other) const {
	return other < *this;
}

bool Fraction::operator<=(const Fraction &other) const {
	return !(other < *this);
}

bool Fraction::operator>=(const Fraction &other) const {
	return !(*this < other);
}

bool Fraction::operator==(const Fraction &other) const {
	return num * other.den == other.num * den;
}

bool Fraction::operator!=(const Fraction &other) const {
	return !(*this == other);
}

Fraction &Fraction::reduce() {
	int d = den;
	int gcd = num;
	while (d != 0) {
		int temp = d;
		d = gcd % d;
		gcd = temp;
	}

	num /= gcd;
	den /= gcd;
	return *this;
}

Fraction Fraction::reduceCopy() const {
	Fraction f = *this;
	return f.reduce();
}

std::ostream &operator<<(std::ostream &os, const Fraction &f) {
	return os << f.num << (f.den == 1 ? "" : "/" + std::to_string(f.den));
}

Fraction &Fraction::set(int _num, int _den) {
	if (_den == 0) {
		throw std::invalid_argument("Error: Denominator cannot be zero.");
	}
	num = _num;
	den = _den;
	reduce();
	return *this;
}

Fraction &Fraction::setNum(int _num) {
	num = _num;
	reduce();
	return *this;
}

Fraction &Fraction::setDen(int _den) {
	if (_den == 0) {
		throw std::invalid_argument("Error: Denominator cannot be zero.");
	}
	den = _den;
	reduce();
	return *this;
}

int Fraction::getNum() const{ return num; }
int Fraction::getDen() const{ return den; }

Fraction::operator float() const {
	return (float) num * 1.0f / (float) den;
}

Fraction::operator double() const {
	return num * 1.0 / den;
}
