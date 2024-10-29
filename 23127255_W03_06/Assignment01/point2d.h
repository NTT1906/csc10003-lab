#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <sstream>
#include <string>

class Point2D{
	int x, y;
public:
	Point2D();
	Point2D(int x);
	Point2D(int x, int y);
	Point2D(const Point2D &other);
	Point2D(Point2D &&other) noexcept;
	Point2D(const std::string& s); // s = "15,-2"
	std::string toString() const;
	Point2D clone();
	~Point2D();
};

#endif // POINT2D_H
