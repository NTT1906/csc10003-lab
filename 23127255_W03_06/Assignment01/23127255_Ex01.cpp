#include <iostream>

#include "point2d.h"

using namespace std;

int main() {
	Point2D p1;
    Point2D p2(10);
	Point2D p3(5, 15);
	Point2D p4("20,-30");

    cout << "P1: " << p1.toString() << '\n';
    cout << "P2: " << p2.toString() << '\n';
    cout << "P3: " << p3.toString() << '\n';
    cout << "P4: " << p4.toString() << '\n';
    
	cout << "Clone p3 to p5\n";
	Point2D p5 = p3.clone();
    cout << "P5: " << p5.toString() << '\n';
	
	cout << "Move p3 to p6\n";
	Point2D p6 = std::move(p3);
    cout << "P6: " << p6.toString() << '\n';
    cout << "P3: " << p3.toString() << '\n';
	return 0;
}
