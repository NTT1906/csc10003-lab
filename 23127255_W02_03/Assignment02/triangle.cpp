#include <iostream>
#include <cmath>
#include "triangle.h"

Point *Point::setX(double x) {
	this->x = x;
	return this;
}

Point *Point::setY(double y) {
	this->y = y;
	return this;
}

void Point::input() {
	double x, y;
	std::cin >> x >> y;
	this->setX(x)
	    ->setY(y);
}

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y) : x(x), y(y) {}

void Point::output() {
	std::cout << "(" << this->distanceOy() << ", " << this->distanceOx() << ")";
}

double squaredDistance(Point p1, Point p2) {
	return (p1.distanceOy() - p2.distanceOy()) * (p1.distanceOy() - p2.distanceOy()) + (p1.distanceOx() - p2.distanceOx()) * (p1.distanceOx() - p2.distanceOx());
}

double Point::distance(Point p) {
	return sqrt(squaredDistance(*this, p));
}

double Point::distanceOx() {
	return y;
}

double Point::distanceOy() {
	return x;
}

void Triangle::input() {
	std::cout << "Input A(x, y): ";
	this->a.input();
	std::cout << "Input B(x, y): ";
	this->b.input();
	std::cout << "Input C(x, y): ";
	this->c.input();
}

void Triangle::output() {
	std::cout << "{";
	this->a.output();
	std::cout << ", ";
	this->b.output();
	std::cout << ", ";
	this->c.output();
	std::cout << "}";
}

bool Triangle::isValidTriangle() {
	double ab = this->a.distance(this->b);
	double bc = this->b.distance(this->c);
	double ca = this->c.distance(this->a);
	return ab + bc > ca && bc + ca > ab && ca + ab > bc;
}

void Triangle::getTypeOfTriangle() {
	double s_ab = squaredDistance(this->a, this->b);
	double s_bc = squaredDistance(this->b, this->c);
	double s_ca = squaredDistance(this->c, this->a);
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

double Triangle::getPerimeter() {
	return this->a.distance(this->b) + this->b.distance(this->c) + this->c.distance(this->a);
}

double Triangle::getArea() {
	double ab = this->a.distance(this->b);
	double bc = this->b.distance(this->c);
	double ca = this->c.distance(this->a);
	double hp = (ab + bc + ca) / 2.0;
	return sqrt(hp * (hp - ab) * (hp - bc) * (hp - ca));
}

Point Triangle::getCenterG() {
	return {(this->a.distanceOy() + this->b.distanceOy() + this->c.distanceOy()) / 3.0, (this->a.distanceOx() + this->b.distanceOx() + this->c.distanceOx()) / 3.0};
}
