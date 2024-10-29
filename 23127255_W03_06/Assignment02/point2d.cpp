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

Point2D::Point2D(const std::string &s) { // NOLINT(*-pro-type-member-init)
	std::cout << "Point2D::String param cons called\n";
	this->fromString(s);
}

std::string Point2D::toString() const {
	std::ostringstream ss;
	ss << x << "," << y;
	return ss.str();
}

Point2D Point2D::clone() {
	return Point2D{*this};
}

int Point2D::getX() const { return this->x; }
int Point2D::getY() const { return this->y; }

Point2D::~Point2D() {
	std::cout << "Point2D::Deconstructor called\n";
}

Point2D &Point2D::set(int _x, int _y) {
	this->x = _x;
	this->y = _y;
	return *this;
}

Point2D &Point2D::fromString(const std::string &s) {
	std::istringstream ss(s);
	char comma;
	if (!(ss >> x) || !(ss >> comma) || (comma != ',')) {
		this->x = 0;
		this->y = 0;
	} else if (!(ss >> this->y)) {
		this->y = 0;
	}
	return *this;
}
