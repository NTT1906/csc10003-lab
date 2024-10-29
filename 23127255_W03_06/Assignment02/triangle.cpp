#include "triangle.h"

Triangle::Triangle() {
	std::cout << "Triangle::Default cons called\n";
}

Triangle::Triangle(int x1, int y1) : a(x1, y1) {
	std::cout << "Triangle::One point arg input cons called\n";
}

Triangle::Triangle(int x1, int y1, int x2, int y2) : a(x1, y1), b(x2, y2) {
	std::cout << "Triangle::Two points arg input cons called\n";
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : a(x1, y1), b(x2, y2), c(x3, y3) {
	std::cout << "Triangle::Three points arg input cons called\n";
}

Triangle::Triangle(const Point2D &a) : a(a.getX(), a.getY()) {
	std::cout << "Triangle::One point input cons called\n";
}

Triangle::Triangle(const Point2D &a, const Point2D &b) : a(a.getX(), a.getY()), b(b.getX(), b.getY()) {
	std::cout << "Triangle::Two point input cons called\n";
}

Triangle::Triangle(const Point2D &a, const Point2D &b, const Point2D &c) : a(a.getX(), a.getY()), b(b.getX(), b.getY()),  c(c.getX(), c.getY()) {
	std::cout << "Triangle::Three point input cons called\n";
}

Triangle::Triangle(const Triangle &other) : a(other.a), b(other.b), c(other.c) {
	std::cout << "Triangle::Copy cons called\n";
}

Triangle::Triangle(Triangle &&other) noexcept : a(other.getA()), b(other.getB()), c(other.getC()) {
	std::cout << "Point2D::Move constructor called\n";
	Triangle::setA(0, 0).setB(0, 0).setC(0, 0);
}

Point2D Triangle::getA() const{ return this->a; }
Point2D Triangle::getB() const{ return this->b; }
Point2D Triangle::getC() const{ return this->c; }

Triangle::Triangle(const std::string &s) {
	std::cout << "Triangle::String param cons called\n";
	std::istringstream ss(s);
	std::string tmp;
	bool sA{false}, sB{false}, sC{false};
	if (getline(ss, tmp, ';')) {
		a.fromString(tmp);
		sA = true;
	}
	if (getline(ss, tmp, ';')) {
		b.fromString(tmp);
		sB = true;
	}
	
	if (getline(ss, tmp, ';')) {
		c.fromString(tmp);
		sC = true;
	}
	if (!sA) a.set(0, 0);
	if (!sB) b.set(0, 0);
	if (!sC) c.set(0, 0);
}

std::string Triangle::toString() const {
	std::ostringstream ss;
    ss << a.toString() << ";" << b.toString() << ";" << c.toString();
    return ss.str();
}

Triangle Triangle::clone() { return *this; }

Triangle::~Triangle() {
	std::cout << "Triangle::Deconstructor called\n";
}

Triangle &Triangle::setA(int x, int y) {
	this->a.set(x, y);
	return *this;
}

Triangle &Triangle::setB(int x, int y) {
	this->b.set(x, y);
	return *this;
}

Triangle &Triangle::setC(int x, int y) {
	this->c.set(x, y);
	return *this;
}
