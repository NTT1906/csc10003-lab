#ifndef FRACTION_H
#define FRACTION_H

struct Fraction {
    int Numerator;
    int Denominator;
};

Fraction Input();
void Output(Fraction f);
Fraction Add(Fraction a, Fraction b);
Fraction Subtract(Fraction a, Fraction b);
Fraction Multiply(Fraction a, Fraction b);
Fraction Devide(Fraction a, Fraction b);
Fraction Reduce(Fraction f);
int Compare(Fraction a, Fraction b);
bool IsPositive(Fraction f);
bool IsNegative(Fraction f);
bool IsZero(Fraction f);

#endif // FRACTION_H
