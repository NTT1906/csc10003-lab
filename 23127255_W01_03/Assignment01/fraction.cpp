#include "fraction.h"

Fraction Input() {
    Fraction f;
    std::cout << "Input num, den (split by space): ";
    std::cin >> f.Numerator >> f.Denominator;
    return f;
}

void Output(Fraction f) {
    std::cout << f.Numerator << "/" << f.Denominator << "\n";
}

Fraction Add(Fraction a, Fraction b) {
    return {a.Numerator * b.Denominator + b.Numerator * a.Denominator, a.Denominator * b.Denominator};
}

Fraction Subtract(Fraction a, Fraction b) {
    return Add(a, {-b.Numerator, b.Denominator});
}

Fraction Multiply(Fraction a, Fraction b) {
    return {a.Numerator * b.Numerator, a.Denominator * b.Denominator};
}

Fraction Devide(Fraction a, Fraction b) {
    if (b.Numerator == 0) throw "Cannot devide a by 0";
    return Multiply(a, {b.Denominator, b.Numerator});
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

Fraction Reduce(Fraction f) {
    int common = gcd(f.Numerator, f.Denominator);
    f.Numerator /= common;
    f.Denominator /= common;
    return f;
}

int Compare(Fraction a, Fraction b) {
    a = Reduce(a);
    b = Reduce(b);
    if (a.Numerator < b.Numerator) return -1;
    return a.Numerator > b.Numerator;
}

bool IsPositive(Fraction f) {
    return (f.Numerator > 0 && f.Denominator > 0) || (f.Numerator < 0 && f.Denominator < 0);
}

bool IsNegative(Fraction f) {
    return !IsZero(f) && !IsPositive(f);
}

bool IsZero(Fraction f) {
    return f.Numerator == 0;
}
