#include <iostream>

#include "fraction.h"

using namespace std;

int main() {
    Fraction f;
    f = Input();
    cout << "Fraction: "; Output(f);
    cout << "Reduced f: "; Output(f = Reduce(f));
    cout << "Add f with 1/2: "; Output(f = Add(f, {1, 2}));
    cout << "Reduced f: "; Output(f = Reduce(f));
    cout << "Minus f with 0/32: "; Output(f = Subtract(f, {0, 32}));
    cout << "Reduced f: "; Output(f = Reduce(f));
    cout << "Multiply f with 1/3: "; Output(f = Multiply(f, {1, 3}));
    cout << "Reduced f: "; Output(f = Reduce(f));
    cout << "Compare 2/3 and 3/4: " << Compare({2, 3}, {3, 4}) << "\n";
    cout << "Compare 2/4 and 3/6: " << Compare({2, 4}, {3, 6}) << "\n";
    cout << "Compare 3/4 and 3/6: " << Compare({3, 4}, {3, 6}) << "\n";
    cout << "Is 2/3 positive? : " << (IsPositive({2, 3}) ? "Yes" : "No") << "\n";
    cout << "Is -2/3 positive? : " << (IsPositive({-2, 3}) ? "Yes" : "No") << "\n";
    cout << "Is -2/3 negative? : " << (IsNegative({-2, 3}) ? "Yes" : "No") << "\n";
    cout << "Is 0/3 positive? : " << (IsPositive({0, 3}) ? "Yes" : "No") << "\n";
    cout << "Is 0/32 zero? : " << (IsZero({0, 32}) ? "Yes" : "No") << "\n";
    cout << "Devide f with 0/32: "; Output(f = Devide(f, {0, 33}));
    return 0;
}
