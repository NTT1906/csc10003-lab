#include "point2d.h"

Point2D::Point2D() : x(0), y(0) {
	std::cout << "Point2D::Default cons called\n";
}

Point2D::Point2D(int x) : x(x), y(0) {
	std::cout << "Point2D::One param cons called\n";
}

Point2D::Point2D(int x, int y) : x(x), y(y) {
	std::cout << "Point2D::Two param cons called\n";
}

Point2D::Point2D(const Point2D &other) : x(other.x), y(other.y) {
	std::cout << "Point2D::Copy cons called\n";
}

Point2D::Point2D(Point2D &&other) noexcept : x(other.x), y(other.y) {
	std::cout << "Point2D::Move constructor called\n";
	other.x = 0;
	other.y = 0;
}

Point2D::Point2D(const std::string &s) {
	std::cout << "Point2D::String param cons called\n";
	std::istringstream ss(s);
	char comma;
	if (!(ss >> x) || !(ss >> comma) || (comma != ',')) {
		x = 0;
		y = 0;
		return;
	}
	if (!(ss >> y)) {
		y = 0;
	}
}

std::string Point2D::toString() const {
	std::ostringstream ss;
    ss << x << "," << y;
    return ss.str();
}

Point2D Point2D::clone() {
	return Point2D{*this};
}

Point2D::~Point2D() {
	std::cout << "Point2D::Deconstructor called\n";
}
