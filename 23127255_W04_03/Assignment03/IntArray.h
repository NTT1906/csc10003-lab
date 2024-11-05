#ifndef INC_23127255_W04_INTARRAY_H
#define INC_23127255_W04_INTARRAY_H

#include <iostream>

class IntArray{
	int *data;
	int n;
public:
	IntArray();
	IntArray(const int arr[], int n);
	IntArray(const IntArray &other);
	~IntArray();
	void input();
	void output() const;

	IntArray &operator=(const IntArray &other);

	friend std::ostream& operator<<(std::ostream &os, const IntArray &arr);
	friend std::istream& operator>>(std::istream &is, IntArray &arr);

	int& operator[](int i);
	int operator[](int i) const;

	operator int() const;
};

#endif //INC_23127255_W04_INTARRAY_H
