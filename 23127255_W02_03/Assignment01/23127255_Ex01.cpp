#include <iostream>

#include "fraction.h"

using namespace std;

int main() {
    Fraction f(0, 0);
	f.setNum(12)->setDenom(32);
	f.input();
    cout << "Fraction: "; f.output();
    cout << "Reduced f: "; f.reduce()->output();
    cout << "Add f with 1/2: "; f.add(Fraction(1, 2)).output();
    cout << "Reduced f: "; f.reduce()->output();
    cout << "Minus f with 0/32: "; f.sub({0, 32}).output();
    cout << "Reduced f: "; f.reduce()->output();
    cout << "Multiply f with 1/3: "; f.mul({1, 3}).output();
    cout << "Reduced f: "; f.reduce()->output();
    cout << "Compare 2/3 and 3/4: " << Fraction(1, 2).compare({3, 4}) << "\n";
    cout << "Compare 2/4 and 3/6: " << Fraction(2, 4).compare({3, 6}) << "\n";
    cout << "Compare 3/4 and 3/6: " << Fraction{3, 4}.compare({3, 6}) << "\n";
    cout << "Is 2/3 positive? : " << (Fraction(2, 3).isPositive() ? "Yes" : "No") << "\n";
    cout << "Is -2/3 positive? : " << (Fraction(-2, 3).isPositive() ? "Yes" : "No") << "\n";
    cout << "Is -2/3 negative? : " << (Fraction({-2, 3}).isNegative() ? "Yes" : "No") << "\n";
    cout << "Is 0/3 positive? : " << (Fraction({0, 3}).isZero() ? "Yes" : "No") << "\n";
    cout << "Is 0/32 zero? : " << (Fraction({0, 32}).isZero() ? "Yes" : "No") << "\n";
    cout << "Divide f with 0/32: "; f.div({0, 33});
    return 0;
}
