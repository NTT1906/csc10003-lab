#include <iostream>
#include "theater.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
	// Clear screen for Windows
	std::system("cls");
#else
	// Clear screen for Linux and other Unix-like systems
	std::system("clear");
#endif
}

int main() {
	Theater theater;
	theater.setPrices();

	int choice;
	do {
		cout << "\nMenu:\n";
		cout << "1. Display Seating Chart\n";
		cout << "2. Sell Ticket\n";
		cout << "3. Display Total Sales\n";
		cout << "4. Display Seat Availability\n";
		cout << "5. Display Seat Price\n";
		cout << "6. Exit\n";
		cout << "0. Clear screen\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 0:
				clearScreen();
				break;
			case 1:
				theater.displaySeatingChart();
				break;
			case 2:
				theater.sellTicket();
				break;
			case 3:
				theater.displayTotalSales();
				break;
			case 4:
				theater.displaySeatAvailability();
				break;
			case 5:
				theater.displaySeatPrice();
				break;
			case 6:
				cout << "Exiting...\n";
				choice = -1;
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
				break;
		}
	} while (choice != -1);

	return 0;
}
