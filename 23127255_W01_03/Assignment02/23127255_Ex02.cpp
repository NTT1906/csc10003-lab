#include <iostream>

#include "triangle.h"

using namespace std;

int main() {
	bool hasValidTriangle = false;
	Triangle t{};
	do {
		cout << "Input triangle: ";
		t.input();
		cout << "Inputted triangle: ";
		t.output();
		cout << '\n';
		if (!t.isValidTriangle()) {
			cout << "Triangle is not valid.\n";
			continue;
		}
		hasValidTriangle = true;
	} while (!hasValidTriangle);

	t.getTypeOfTriangle();
	cout << "Triangle's perimeter: " << t.getPerimeter() << '\n';
	cout << "Triangle's area: " << t.getArea() << '\n';
	return 0;
}
