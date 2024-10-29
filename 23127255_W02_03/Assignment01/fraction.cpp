#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-make-member-function-const"
#pragma ide diagnostic ignored "ArgumentSelectionDefects"
#include "fraction.h"

Fraction::Fraction(int num, int denom) : num(num), denom(denom) {}

void Fraction::input() {
	std::cout << "Input num, den (split by space): ";
	std::cin >> this->num >> this->denom;
}

void Fraction::output() {
	std::cout << this->num << "/" << this->denom << "\n";
}

Fraction Fraction::add(Fraction f) {
	return {this->num * f.getDenom() + f.getNum() * this->denom, this->denom * f.getDenom()};
}

Fraction Fraction::sub(Fraction f) {
	return this->add({f.getNum(), -(f.getDenom())});
}

Fraction Fraction::mul(Fraction f) {
	return {this->num * f.getNum(), this->denom * f.getDenom()};
}

Fraction Fraction::div(Fraction f) {
	if (f.getNum() == 0) throw "Cannot devide a by 0";
	return mul({f.getDenom(), f.getNum()});
}

int Fraction::compare(Fraction f) {
	this->reduce();
	f.reduce();
	if (this->num < f.num) return -1;
    return this->num > f.num;
}

bool Fraction::isPositive() {
	return (this->num > 0 && this->denom > 0) || (this->num < 0 && this->denom < 0);
}

bool Fraction::isNegative() {
	return !this->isZero() && !this->isPositive();
}

bool Fraction::isZero() { return this->num == 0; }

Fraction *Fraction::setNum(int n) {
	this->num = n;
	return this;
}

int Fraction::getNum() { return this->num; }

Fraction *Fraction::setDenom(int d) {
	this->denom = d;
	return this;
}

int Fraction::getDenom() { return this->denom; }

Fraction *Fraction::reduce() {
	int common = gcd(this->num, this->denom);
	this->num /= common;
	this->denom /= common;
	return this;
}

int Fraction::gcd(int a, int b) { // NOLINT(*-no-recursion)
	return b == 0 ? a : gcd(b, a % b);
}

#pragma clang diagnostic pop