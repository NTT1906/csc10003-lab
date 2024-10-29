#include "auditorium.h"

Auditorium::Auditorium() : seats{}, prices{} {
	cleanUp(true);
}

Auditorium::Auditorium(const double _prices[]) : seats{}, prices{} {
	for (int i = 0; i < MAX_ROW; ++i) this->prices[i] = _prices[i];
}

Auditorium::Auditorium(std::string &s) : seats{}, prices{} {
	std::istringstream ss(s);
	char ch;
	ss >> ch;
	for (auto &row : seats) {
		for (bool &seat : row) {
			ss >> ch;
			seat = (ch == '*');
		}
		ss >> ch; // '_'
	}
	std::string tmp;
	getline(ss, tmp, '\n');
	for (double &price : prices) {
		ss >> price;
	}
}

//#*#****_#*#****_#*#****_#*#****_#*#****_#*#****_#*#****_#*#****
//131 213.2 123 131231 2131 3123 13 23 13
std::string Auditorium::toString() {
	std::ostringstream ss;
	ss << (seats[0][0] ? "*" : "#");
	for (auto &row : seats) {
		for (bool seat : row) {
			ss << "_" << (seat ? "*" : "#");
		}
	}
	ss << "\n" << prices[0];
	for (double price : prices) {
		ss << " " << price;
	}
	return ss.str();
}

Auditorium::Auditorium(const Auditorium &other) : seats{}, prices{} {
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			seats[i][j] = other.seats[i][j];
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		this->prices[i] = other.prices[i];
	}
}

Auditorium::Auditorium(Auditorium &&other) noexcept : seats{}, prices{} {
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			seats[i][j] = other.seats[i][j];
			other.seats[i][j] = false;
		}
	}
	for (int i = 0; i < MAX_ROW; ++i) {
		prices[i] = other.prices[i];
		prices[i] = 0;
	}
}

bool Auditorium::isSeatValid(int r, int c) const {
	return r >= 1 && r <= MAX_ROW && c >= 1 && c <= MAX_COL;
}

bool Auditorium::isSeatEmpty(int r, int c) const{
	if (!isSeatValid(r, c)) {
		std::cout << "Input row or col is out of bound!\n";
		return false;
	}
	return !seats[r - 1][c - 1];
}

Auditorium &Auditorium::setPrice(int r, double price) {
	if (r < 1 || r > MAX_ROW) {
		std::cout << "Input row is out of bound, input must be from 1 to " << MAX_ROW << "!\n";
		return *this;
	}
	this->prices[r - 1] = price;
	return *this;
}

Auditorium &Auditorium::setSeat(int r, int c, bool available = false) {
	if (!isSeatValid(r, c)) {
		std::cout << "Input row or col is out of bound!\n";
		return *this;
	}
	this->seats[r - 1][c-1] = !available;
	return *this;
}

int Auditorium::getAmountOfAvailableSeat(int r) const {
	if (r < 1 || r > MAX_ROW) {
		std::cout << "Input row is out of bound, input must be from 1 to " << MAX_ROW << "!\n";
		return 0;
	}
	int count = 0;
	r--;
	for (int i = 0; i < MAX_COL; ++i)
		if (!seats[r][i]) ++count;
	return count;
}

int Auditorium::getTotalAmountOfAvailableSeats() const {
	int count = 0;
	for (int i = 1; i <= MAX_ROW; i++) count += getAmountOfAvailableSeat(i);
	return count;
}

double Auditorium::getPrice(int r) const {
	if (r < 1 || r > MAX_ROW) {
		std::cout << "Input row is out of bound, input must be from 1 to " << MAX_ROW << "!\n";
		return 0;
	}
	return this->prices[r - 1];
}

Auditorium &Auditorium::cleanUp(bool cleanPrice = false) {
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			seats[i][j] = false;
		}
	}
	if (cleanPrice) {
		for (double &price : prices) {
			price = 0;
		}
	}

	return *this;
}
