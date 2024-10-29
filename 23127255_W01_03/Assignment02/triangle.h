#ifndef LAB1_ASSIGN2_TRIANGLE_H
#define LAB1_ASSIGN2_TRIANGLE_H

struct Point{
	double x, y;
	void input();
	void output() const;
	double distance(Point p) const;
	double distanceOx() const;
	double distanceOy() const;
};

struct Triangle{
	Point a, b, c;
	void input();
	void output();
	bool isValidTriangle() const;
	void getTypeOfTriangle() const;
	double getPerimeter() const;
	double getArea() const;
	Point getCenterG() const;
};

#endif //LAB1_ASSIGN2_TRIANGLE_H
