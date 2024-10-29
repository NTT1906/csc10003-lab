#include "theater.h"

Theater::Theater() : totalPrice{}, seatSold{}, auditorium{} {}

Auditorium Theater::getAuditorium() {
	return this->auditorium;
}

void Theater::displaySeatingChart() const {
	std::cout << "\n                     Seats\n         ";
	for (int seat = 1; seat <= Auditorium::MAX_COL; ++seat) {
		std::cout << seat % 10;
	}
	std::cout << "\n";

	for (int row = 1; row <= Auditorium::MAX_ROW; ++row) {
		std::cout << "Row " << std::left << std::setw(5) << row;
		for (int col = 1; col <= Auditorium::MAX_COL; ++col) {
			std::cout << (auditorium.isSeatEmpty(row, col) ? "#" : "*");
		}
		std::cout << "\n";
	}
}

void Theater::sellTicket() {
	int row, col;
	std::cout << "Enter the row number (1-15): ";
	std::cin >> row;
	std::cout << "Enter the seat number (1-30): ";
	std::cin >> col;

	if (auditorium.isSeatValid(row, col)) {
		if (auditorium.isSeatEmpty(row, col)) {
			auditorium.setSeat(row, col, false);
			seatSold++;
			double price = auditorium.getPrice(row);
			totalPrice += price;
			std::cout << "Ticket sold for $" << totalPrice << "\n";
		} else {
			std::cout << "Seat already taken!\n";
		}
	} else {
		std::cout << "Seat is invalid.\n";
	}
}

void Theater::setPrices() {
	double price;
	for (int i = 1; i <= Auditorium::MAX_ROW; ++i) {
		std::cout << "Enter the price for row " << i << ": ";
		std::cin >> price;
		auditorium.setPrice(i, price);
	}
}

void Theater::displayTotalSales() const {
	std::cout << "Total ticket sales: $" << totalPrice << "\n";
	std::cout << "Total seats taken: " << seatSold << "\n";
}

void Theater::displaySeatAvailability() const {
	int totalAvailable = 0, rowAvailable;
	std::cout << "\nSeat Availability:\n";
	for (int i = 1; i <= Auditorium::MAX_ROW; ++i) {
		rowAvailable = auditorium.getAmountOfAvailableSeat(i);
		totalAvailable += rowAvailable;
		std::cout << "Row " << i << " - Available Seats: " << rowAvailable << "\n";
	}
	std::cout << "Total available seats in theater: " << totalAvailable << "\n";
}

void Theater::displaySeatPrice() const {
	for (int i = 1; i <= Auditorium::MAX_ROW; ++i) {
		std::cout << "Row " << i << " - Available Seats: " << auditorium.getPrice(i) << "\n";
	}
}

#include <fstream>
void Theater::loadFromFile(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Failed to load from file \"" << filename << "\"\n";
		return;
	}
	std::string line;
	if (std::getline(file, line)) {
		if (!line.empty()) {
			totalPrice = std::stod(line);
		}
	}
	if (std::getline(file, line)) {
		if (!line.empty()) {
			seatSold = std::stoi(line);
		}
	}
	if (std::getline(file, line)) {
		if (!line.empty()) {
			char ch;
			file >> ch;
			for (int i = 1; i <= Auditorium::MAX_ROW; ++i) {
				for (int j = 1; j <= Auditorium::MAX_COL; ++j) {
					file >> ch;
					auditorium.setSeat(i, j, ch == '#');
				}
			}
		}
	}
	if (std::getline(file, line)) {
		if (!line.empty()) {
			for (int i = 1; i <= Auditorium::MAX_ROW; ++i) {
				double price;
				file >> price;
				auditorium.setPrice(i, price);
			}
		}
	}
	file.close();
}


