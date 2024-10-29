#ifndef LAB1_ASSIGN2_TRIANGLE_H
#define LAB1_ASSIGN2_TRIANGLE_H

class Point{
	double x, y;
public :
	Point();
	Point(double x, double y);
	void input();
	void output();
	double distance(Point p);
	double distanceOx();
	double distanceOy();
	Point *setX(double x);
	Point *setY(double y);
};

class Triangle{
	Point a, b, c;
public:
	void input();
	void output();
	bool isValidTriangle();
	void getTypeOfTriangle();
	double getPerimeter();
	double getArea();
	Point getCenterG();
};

#endif //LAB1_ASSIGN2_TRIANGLE_H
