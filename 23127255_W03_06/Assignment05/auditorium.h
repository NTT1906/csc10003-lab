#ifndef AUDITORIUM_H
#define AUDITORIUM_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Auditorium{
public:
	static const int MAX_ROW = 15;
	static const int MAX_COL = 30;
private:
	bool seats[MAX_ROW][MAX_COL];
	double prices[MAX_ROW];
public:
	Auditorium();
	Auditorium(const double prices[]);
	Auditorium(std::string &s);
	Auditorium(const Auditorium &other);
	Auditorium(Auditorium &&other) noexcept;
	std::string toString();
	bool isSeatValid(int r, int c) const;
	bool isSeatEmpty(int r, int c) const;
	Auditorium &setPrice(int r, double price);
	double getPrice(int r) const;
	double getTotalPrice() const;
	Auditorium &setTotalPrice(double price);
	Auditorium &calculateTotalPrice(double price);
	Auditorium &setSeat(int r, int c, bool available);
	int getAmountOfAvailableSeat(int r) const;
	int getTotalAmountOfAvailableSeats() const;
	Auditorium &cleanUp(bool cleanPrice);
};

#endif //AUDITORIUM_H
