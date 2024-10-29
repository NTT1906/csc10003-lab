#ifndef MYINTARR_H
#define MYINTARR_H

#include <iostream>
#include <string>
#include <sstream>

class MyIntArr{
	int *a;
	int n;
public:
	MyIntArr();
	MyIntArr(int _n);
	MyIntArr(const int *_a, int _n);
	MyIntArr(const MyIntArr &other);
	MyIntArr(MyIntArr &&other) noexcept;
	MyIntArr(const std::string &s);
	MyIntArr clone();
	std::string toString() const;
	int getSize() const;
	int getValue(int idx) const;
	~MyIntArr();
};

#endif //MYINTARR_H
