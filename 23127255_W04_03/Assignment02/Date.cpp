#include "Date.h"

Date::Date() : day{0}, month{0}, year{0} {}
Date::Date(int _day, int _month, int _year) : day{_day}, month{_month}, year{_year} {
	year += month / 12;
	month = month % 12 + 1;
	while (day > daysInMonth()) {
		day -= daysInMonth();
		if (++month == 13) {
			month = 1;
			++year;
		}
	}
}

Date::Date(const Date &other) : day{other.day}, month{other.month}, year{other.year} {}

inline bool is_leap_year(int _year) {
	return (_year % 100 != 0 && _year % 4 == 0) || _year % 400 == 0;
}

bool Date::isLeapYear() const {
	return is_leap_year(year);
}

Date Date::operator+(const Date &other) const {
	Date r = *this;
	r.day += other.day;
	while (r.day > r.daysInMonth()) {
		r.day -= r.daysInMonth();
		++r.month;
		if (r.month == 13) {
			r.month = 1;
			++r.year;
		}
	}
	r.month += other.month;
	r.year += r.month / 12 + other.year;
	r.month = r.month % 12 + 1;
	return r;
}

Date Date::operator-(const Date &other) const {
	Date r = *this;
	r.day -= other.day;
	while (r.day < 0) {
		--r.month;
		r.day += r.daysInMonth();
		if (r.month == 0) {
			r.month = 12;
			--r.year;
		}
	}
	r.month -= other.month;
	r.year += r.month / 12 - other.year;
	r.month = r.month % 12 + 1;
	if (r.month < 0) {
		r.month += 12;
		--r.year;
	}
	return r;
}

Date &Date::operator=(const Date &other) {
	day = other.day;
	month = other.month;
	year = other.year;
	return *this;
}

int days_in_month(int _month, int _year) {
	switch (_month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
		case 4: case 6: case 9: case 11: return 30;
		case 2: return is_leap_year(_year) ? 29 : 28;
		case 0: return 0; // special case
		default: throw std::invalid_argument("Invalid month");
	}
}

int Date::daysInMonth() const {
	return days_in_month(month, year);
}

Date Date::tomorrow() const {
	Date next = *this;
	next.day++;
	if (next.day > next.daysInMonth()) {
		next.day = 1;
		next.month++;
		if (next.month > 12) {
			next.month = 1;
			next.year++;
		}
	}
	return next;
}

Date Date::yesterday() const {
	Date prev = *this;
	prev.day--;
	if (prev.day < 1) {
		prev.month--;
		if (prev.month < 1) {
			prev.month = 12;
			prev.year--;
		}
		prev.day = prev.daysInMonth();
	}
	return prev;
}

bool Date::operator==(const Date &other) const {
	return (day == other.day && month == other.month && year == other.year);
}

bool Date::operator!=(const Date &other) const {
	return !(*this == other);
}

bool Date::operator<(const Date &other) const {
	return year < other.year || (year == other.year && (month < other.month || (month == other.month && day < other.day)));
}

bool Date::operator>(const Date &other) const {
	return year > other.year || (year == other.year && (month > other.month || (month == other.month && day > other.day)));
}

bool Date::operator<=(const Date &other) const {
	return *this < other || *this == other;
}

bool Date::operator>=(const Date &other) const {
	return *this > other || *this == other;
}

Date Date::operator+(int x) const {
	return *this + Date{x, 0, 0};
}

Date Date::operator-(int x) const {
	return *this - Date{x, 0, 0};
}

Date &Date::operator++() {
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int) {
	Date r = *this;
	*this = *this + 1;
	return r;
}

Date &Date::operator--() {
	return *this = *this - 1;
}

Date Date::operator--(int) {
	Date r = *this;
	*this = *this + 1;
	return r;
}

Date &Date::input() {
	std::cout << "Input day, month, year (each skipped by space): ";
	std::cin >> day >> month >> year;

	year += month / 12;
	month = month % 12 + 1;

	while (day > daysInMonth()) {
		day -= daysInMonth();
		if (++month == 13) {
			month = 12;
			++year;
		}
	}
	return *this;
}

Date &Date::output() {
	std::cout << "Date: " << *this << '\n';
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}

std::istream &operator>>(std::istream &is, Date &date) {
	is >> date.day >> date.month >> date.year;
	date.year += date.month / 12;
	date.month = date.month % 12 + 1;
	while (date.day > date.daysInMonth()) {
		date.day -= date.daysInMonth();
		if (++date.month == 13) {
			date.month = 1;
			++date.year;
		}
	}
	return is;
}

Date::operator int() const {
	int days = day;
	for (int i = 1; i < month; ++i) days += days_in_month(i, year);
	return days;
}

Date::operator long() const {
	long days = (year - 1) * 365 + (int) *this;
	for (int i = 1; i < year; ++i) if (is_leap_year(i)) ++days;
	return days;
}

void Date::operator+=(const Date &other) {
	*this = *this + other;
}

void Date::operator-=(const Date &other) {
	*this = *this - other;
}

void Date::operator+=(int x) {
	*this = *this + x;
}

void Date::operator-=(int x) {
	*this = *this - x;
}



