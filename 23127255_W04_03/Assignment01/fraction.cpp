#include "fraction.h"

Fraction &Fraction::input() {
	std::cout << "Input num, den (split by space): ";
	std::cin >> num >> denom;
	return *this;
}

Fraction &Fraction::output() {
	std::cout << num << "/" << denom << "\n";
	return *this;
}

int Fraction::compare(const Fraction& f) const {
	int diff = num * f.getDenom() - f.getNum() * denom;
	if (diff < 0) return -1;
    return diff > 0;
}

bool Fraction::isPositive() const {
	return (num > 0 && denom > 0) || (num < 0 && denom < 0);
}

bool Fraction::isNegative() const {
	return !isZero() && !isPositive();
}

bool Fraction::isZero() const { return num == 0; }

Fraction &Fraction::setNum(int n) {
	num = n;
	return *this;
}

Fraction &Fraction::setDenom(int d) {
	denom = d;
	return *this;
}

int Fraction::getNum() const { return num; }
int Fraction::getDenom() const { return denom; }

int gcd(int a, int b) { // NOLINT(*-no-recursion)
	return b == 0 ? a : gcd(b, a % b);
}

Fraction &Fraction::reduce() {
	int common = gcd(num, denom);
	num /= common;
	denom /= common;
	return *this;
}

Fraction::Fraction() : num{}, denom{} {}

Fraction::Fraction(int _num, int _denom) : num(_num), denom(_denom) {
	if (_denom == 0) {
		throw std::invalid_argument("Fraction's denom cannot be zero!");
	}
}

Fraction::Fraction(const Fraction &other) : num(other.num), denom(other.denom) {}

Fraction Fraction::operator+(Fraction &f) const {
	return {num * f.getDenom() + f.getNum() * denom, denom * f.getDenom()};
}

Fraction Fraction::operator-(Fraction &f) const {
	return {num * f.getDenom() - f.getNum() * denom, denom * f.getDenom()};
}

Fraction Fraction::operator*(Fraction &f) const {
	return {num * f.getNum(), denom * f.getDenom()};
}

Fraction Fraction::operator/(Fraction &f) const {
	if (f.getNum() == 0) {
		throw std::invalid_argument("Cannot divide by zero!");
	}
	return {num * f.getDenom(), denom * f.getNum()};
}

Fraction Fraction::operator+(int x) const {
	return {num + x * denom, denom};
}

Fraction Fraction::operator-(int x) const {
	return {num - x * denom, denom};
}

Fraction Fraction::operator*(int x) const {
	return {num * x, denom};
}

Fraction Fraction::operator/(int x) const {
	if (x == 0) {
		throw std::invalid_argument("Cannot divide by zero!");
	}
	return {num, denom * x};
}

void Fraction::operator+=(Fraction &f) {
	num = num * f.getDenom() + f.getNum() * denom;
	denom *= f.getDenom();
}

void Fraction::operator-=(Fraction &f) {
	num = num * f.getDenom() - f.getNum() * denom;
	denom *= f.getDenom();
}

void Fraction::operator*=(Fraction &f) {
	num *= f.getNum();
	denom *= f.getDenom();
}

void Fraction::operator/=(Fraction &f) {
	if (f.getNum() == 0) {
		throw std::invalid_argument("Fraction's denom cannot be zero!");
	}
	num *= f.getDenom();
	denom *= f.getNum();
}

void Fraction::operator+=(int x) {
	num += x * denom;
}

void Fraction::operator-=(int x) {
	num -= x * denom;
}

void Fraction::operator*=(int x) {
	num *= x;
}

void Fraction::operator/=(int x) {
	if (x == 0) {
		throw std::invalid_argument("Fraction's denom cannot be zero!");
	}
	denom *= x;
}

Fraction &Fraction::set(int _num, int _denom) {
	if (_denom == 0) {
		throw std::invalid_argument("");
	}
	num = _num;
	denom = _denom;
	return *this;
}

bool Fraction::operator==(Fraction &f) const {
//	return compare(f) == 0;
	return num * f.getDenom() == f.getNum() * denom;
}

bool Fraction::operator!=(Fraction &f) const {
//	return compare(f) != 0;
	return num * f.getDenom() != f.getNum() * denom;
}

bool Fraction::operator<=(Fraction &f) const {
//	return compare(f) <= 0;
	return num * f.getDenom() <= f.getNum() * denom;
}

bool Fraction::operator>=(Fraction &f) const {
//	return compare(f) >= 0;
	return num * f.getDenom() >= f.getNum() * denom;
}

bool Fraction::operator<(Fraction &f) const {
//	return compare(f) < 0;
	return num * f.getDenom() < f.getNum() * denom;
}

bool Fraction::operator>(Fraction &f) const {
//	return compare(f) > 0;
	return num * f.getDenom() > f.getNum() * denom;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
	os << f.num << "/" << f.denom;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
	char tmp;
	is >> f.num >> tmp >> f.denom;
	f.reduce();
	return is;
}

Fraction::operator float() const {
	return 1.0f * num / denom;
}

Fraction::operator double() const {
	return 1.0 * num / denom;
}

Fraction &Fraction::operator=(const Fraction &f) {
	num = f.getNum();
	denom = f.getDenom();
	return *this;
}

Fraction &Fraction::operator=(int x) {
	num = x;
	denom = 1;
	return *this;
}

Fraction operator+(int x, Fraction &f) {
	Fraction r(x, 1);
	return r + f;
}

Fraction operator-(int x, Fraction &f) {
	Fraction r(x, 1);
	return r - f;
}

Fraction operator*(int x, Fraction &f) {
	Fraction r(x, 1);
	return r * f;
}

Fraction operator/(int x, Fraction &f) {
	Fraction r(x, 1);
	return r / f;
}

Fraction &Fraction::operator++() {
	num += denom;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this; //copy
	num += denom;
	return temp;
}

Fraction &Fraction::operator--() {
	num -= denom;
	return *this;
}

Fraction Fraction::operator--(int) {
	Fraction temp = *this; //Copy
	num -= denom;
	return temp;
}
