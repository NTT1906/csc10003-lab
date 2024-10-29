#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <sstream>
#include <string>
#include "point2d.h"

class Triangle{
	Point2D a, b, c;
public:
	Triangle();
	Triangle(int x1, int y1);
	Triangle(int x1, int y1, int x2, int y2);
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	Triangle(const Point2D &a);
	Triangle(const Point2D &a, const Point2D &b);
	Triangle(const Point2D &a, const Point2D &b, const Point2D &c);
	Triangle(const Triangle &other);
	Triangle(Triangle &&other) noexcept;
	Triangle(const std::string &s);
	std::string toString() const;
	Triangle clone();
	Point2D getA() const;
	Point2D getB() const;
	Point2D getC() const;
	Triangle& setA(int x, int y);
	Triangle& setB(int x, int y);
	Triangle& setC(int x, int y);
	~Triangle();
};

#endif // TRIANGLE_H

