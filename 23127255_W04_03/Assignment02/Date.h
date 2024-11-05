#ifndef INC_23127255_W04_DATE_H
#define INC_23127255_W04_DATE_H

#include <iostream>
#include <string>

class Date{
	int day,  month, year;
public:
	Date();
	Date(int day, int month = 0, int year = 0);
	Date(const Date &other);

	Date &input();
	Date &output();

	bool isLeapYear() const;
	int daysInMonth() const;

	Date tomorrow() const;
	Date yesterday() const;

	Date operator+(const Date &other) const;
	Date operator-(const Date &other) const;
	Date operator+(int x) const;
	Date operator-(int x) const;

	Date &operator=(const Date &other);

	bool operator==(const Date &other) const;
	bool operator!=(const Date &other) const;
	bool operator<(const Date &other) const;
	bool operator>(const Date &other) const;
	bool operator<=(const Date &other) const;
	bool operator>=(const Date &other) const;

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	friend std::ostream& operator<<(std::ostream &os, const Date &date);
	friend std::istream& operator>>(std::istream &is, Date &date);

	operator int() const;
	operator long() const;

	void operator+=(const Date &other);
	void operator-=(const Date &other);
	void operator+=(int x);
	void operator-=(int x);
};

#endif //INC_23127255_W04_DATE_H
