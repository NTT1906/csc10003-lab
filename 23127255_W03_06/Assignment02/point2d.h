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
	Point2D(const std::string &s); // s = "15,-2"
	Point2D clone();
	std::string toString() const;
	int getX() const;
	int getY() const;
	Point2D& fromString(const std::string &s);
	Point2D& set(int _x, int _y);
	~Point2D();
};

#endif // POINT2D_H
