#include <iostream>

#include "triangle.h"

using namespace std;

int main() {;
	Triangle t{};
	do {
		cout << "Input triangle: \n";
		t.input();
		cout << "Inputted triangle: ";
		t.output();
		cout << '\n';
		if (t.isValidTriangle()) {
			break;
		}
		cout << "Triangle is not valid.\n";
	} while (true);

	t.getTypeOfTriangle();
	cout << "Triangle's perimeter: " << t.getPerimeter() << '\n';
	cout << "Triangle's area: " << t.getArea() << '\n';
	return 0;
}
