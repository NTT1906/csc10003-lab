#include <cmath>
#include <iostream>
#include "triangle.h"

void Point::input() {
	std::cin >> x >> y;
}

void Point::output() const {
	std::cout << "(" << x << ", " << y << ")";
}

double squaredDistance(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

double Point::distance(Point p) const {
	return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
}

double Point::distanceOx() const {
	return y;
}

double Point::distanceOy() const {
	return x;
}

void Triangle::input() {
	std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
}

void Triangle::output() {
	std::cout << "{";
	a.output();
	std::cout << ", ";
	b.output();
	std::cout << ", ";
	c.output();
	std::cout << "}";
}

bool Triangle::isValidTriangle() const {
	double ab = a.distance(b);
	double bc = b.distance(c);
	double ca = c.distance(a);
	return ab + bc > ca && bc + ca > ab && ca + ab > bc;
}

void Triangle::getTypeOfTriangle() const {
	double s_ab = squaredDistance(a, b);
	double s_bc = squaredDistance(b, c);
	double s_ca = squaredDistance(c, a);
	std::cout << "Triangle is ";
	if (s_ab == s_bc + s_ca || s_bc == s_ab + s_ca || s_ca == s_ab + s_bc) {
		std::cout << "right";
	} else if (s_ab + s_bc > s_ca || s_bc + s_ca > s_ab || s_ca + s_ab > s_bc) {
		std::cout << "acute";
	} else {
		std::cout << "obtuse";
	}
	std::cout << ", and ";
	if (s_ab == s_bc && s_bc == s_ca)
		std::cout << "equilateral.";
	else if (s_ab == s_bc || s_bc == s_ca || s_ca == s_ab)
		std::cout << "isosceles.";
	else
		std::cout << "scalene.";
	std::cout << '\n';
}

double Triangle::getPerimeter() const {
	return a.distance(b) + b.distance(c) + c.distance(a);
}

double Triangle::getArea() const {
	double ab = a.distance(b);
	double bc = b.distance(c);
	double ca = c.distance(a);
	double hp = (ab + bc + ca) / 2.0;
	return sqrt(hp * (hp - ab) * (hp - bc) * (hp - ca));
}

Point Triangle::getCenterG() const {
	return {(a.x + b.x + c.x) / 3.0, (a.y + b.y + c.y) / 3.0};
}
