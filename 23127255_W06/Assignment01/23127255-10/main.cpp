#include <iostream>
using namespace std;

#include <iostream>
#include "Company.h"

using namespace std;

int main() {
	int choice = -1;
	Company abc;
	do {
		cout << "MENU\n"
			 << "1) Add bill.\n"
			 << "2) Find all bills with user name.\n"
			 << "3) Sort bills.\n"
			 << "4) Print bills.\n"
			 << "5) Print total income.\n"
			 << "6) Count growth bills.\n"
			 << "0) Exit.\n"
		;
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 0: {
			cout << "Exitting...\n";
			choice = -1;
			break;
		}
		case 1: {
			abc.input();
			break;
		}
		case 2: {
			cout << "Enter User Name: ";
			string userName;
			getline(cin, userName);
			vector<Bill> bills = abc.getBillsWithUserName(userName);
			for (auto &bill : bills) {
				std::cout << "Bill ID: " << bill.getId() << "\n";
				std::cout << "Bill User Name: " << bill.getUserName() << "\n";
				std::cout << "Bill Product Name: " << bill.getProductName() << "\n";
				std::cout << "Bill Product Price: " << bill.getProductPrice() << "\n";
				if (bill.getBillType() == BillType::TYPE_GROWTH) {
					std::cout << "Bill Tax: " << static_cast<GrowthBill *>(&bill)->getTax() << "\n";
				}
				std::cout << "\n";
			}
			break;
		}
		case 3: {
			abc.sortBill();
			break;
		}
		case 4: {
			abc.output();
			break;
		}
		case 5: {
			cout << "Company's total income: " << abc.getTotalIncome() << "\n";
			break;
		}
		case 6: {
			cout << "Company's growth bill count: " << abc.countGrowthBill() << '\n';
			break;
		}
		default: {
			cout << "Invalid input. Please try again!\n";
			break;
		}
		}
	} while (choice != -1);
	return 0;
}