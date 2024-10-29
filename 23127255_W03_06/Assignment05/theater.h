#ifndef THEATER_H
#define THEATER_H

#include "auditorium.h"
#include <iomanip>

class Theater{
	Auditorium auditorium;
	int seatSold{};
	double totalPrice;
public:
	Theater();
	Auditorium getAuditorium();
	void displaySeatingChart() const;
	void sellTicket();
	void setPrices();
	void displayTotalSales() const;
	void displaySeatAvailability() const;
	void displaySeatPrice() const;
	void loadFromFile(const std::string& filename);
};


#endif //THEATER_H
