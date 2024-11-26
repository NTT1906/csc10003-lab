#include <iostream>
#include "castle.h"
#include "prince.h"

using namespace std;

int main() {
	Castle castle;
	Prince prince;
	int choice;
	do {
		cout << "[MAIN MENU]\n"
				"1) View prince's information\n"
				"2) Edit prince's information\n"
				"3) Add Gate\n"
				"4) Enter Castle\n"
				"5) Castle Information\n"
				"0) Exit MENU\n";
		cin >> choice;
		switch (choice) {
			case 0: {
				choice = -1;
				cout << "Exiting...\n";
				break;
			}
			case 1: {
				cout << "[VIEW PRINCE INFORMATION]\n";
				prince.displayInformation();
				break;
			}
			case 2: {
				cout << "[EDIT PRINCE INFORMATION]\n";
				char validate;
				cout << "Do you want to edit prince's money? (Y/N, other = skip): ";
				cin >> validate;
				if (validate == 'Y' || validate == 'y') {
					cout << "Enter prince's money: ";
					double money;
					cin >> money;
					cout << "Prince's money has been set to " << money << "\n";
					prince.setMoney(money);
				}
				cout << "Do you want to edit prince's IQ? (Y/N, other = skip): ";
				cin >> validate;
				if (validate == 'Y' || validate == 'y') {
					cout << "Enter prince's IQ: ";
					unsigned long long iq;
					cin >> iq;
					cout << "Prince's IQ has been set to " << iq << "\n";
					prince.setIQ(iq);
				}
				cout << "Do you want to edit prince's strength? (Y/N, other = skip): ";
				cin >> validate;
				if (validate == 'Y' || validate == 'y') {
					cout << "Enter prince's strength: ";
					unsigned long long strength;
					cin >> strength;
					cout << "Prince's strength has been set to " << strength << "\n";
					prince.setStrength(strength);
				}
				cout << "Do you want to edit prince's level? (Y/N, other = skip): ";
				cin >> validate;
				if (validate == 'Y' || validate == 'y') {
					cout << "Enter prince's level: ";
					unsigned long long level;
					cin >> level;
					cout << "Prince's level has been set to " << level << "\n";
					prince.setLevel(level);
				}
				break;
			}
			case 3: {
				cout << "[ADD GATE]\n";
				cout << "Type of gate: \n";
				cout << " + bussiness: 0\n";
				cout << " + academic : 1\n";
				cout << " + power    : 2\n";
				int type;
				do {
					cout << "Enter type of gate: ";
					cin >> type;
					if (type < 0 || type > 2) {
						cout << "Invalid type. Please re-enter the type!\n";
					}
				} while (type < 0 || type > 2);
				Gate *gate = nullptr;
				switch (type) { // NOLINT(*-multiway-paths-covered)
					case GateType::TYPE_BUSINESS: {
						cout << "[Bussiness gate - CONFIG]\n";
						cout << "Type of product: \n";
						cout << " + book  : 0\n";
						cout << " + potion: 1\n";
						cout << " + weapon: 2\n";
						int typeProd;
						do {
							cout << "Enter type of product: ";
							cin >> typeProd;
							if (typeProd < 0 || typeProd > 2) {
								cout << "Invalid type. Please re-enter the type!\n";
							}
						} while (typeProd < 0 || typeProd > 2);
						double unitPrice;
						do {
							cout << "Enter product's unit price: ";
							cin >> unitPrice;
							if (unitPrice < 0) {
								cout << "Unit price must be greater than zero!\n";
							}
						} while (unitPrice < 0);
						unsigned int requireAmount;
						do {
							cout << "Enter required amount: ";
							cin >> requireAmount;
							if (requireAmount == 0) {
								cout << "Require amount must be greater than zero!\n";
							}
						} while (requireAmount == 0);
						cout << "Added a bussiness gate!\n";
						gate = new BusinessGate({typeProd, unitPrice}, requireAmount);
						break;
					}
					case GateType::TYPE_ACADEMIC: {
						unsigned long long iq;
						do {
							cout << "Enter question's intelligence level (>0): ";
							cin >> iq;
							if (iq == 0) {
								cout << "Intelligence not found! Please retype :>\n";
							}
						} while (iq == 0);
						cout << "Added a academic gate!\n";
						gate = new AcademicGate(iq);
						break;
					}
					case GateType::TYPE_POWER: {
						unsigned long long strength, reduceStrength;
						do {
							cout << "Enter warrior's strength level: ";
							cin >> strength;
							if (strength == 0) {
								cout << "Warrior's strength level must be greater than zero!\n";
							}
						} while (strength == 0);
						do {
							cout << "Enter reduced strength amount (after victory): ";
							cin >> reduceStrength;
							if (reduceStrength == 0) {
								cout << "Reduced strength amount must be greater than zero!\n";
							}
						} while (strength == 0);
						cout << "Added a power gate!\n";
						gate = new PowerGate(strength, reduceStrength);
						break;
					};
				}
				castle.addGate(gate);
				break;
			}
			case 4: {
				unsigned long long finalLevel = castle.entry(prince);
				if (finalLevel == castle.getGateAmount()) {
					cout << "Result: prince CAN rescue the princess.\n";
					cout << "Prince's remaining parameters: \n";
					prince.displayInformation();
				} else {
					cout << "Result: prince CANNOT rescue the princess.\n";
					cout << "Castle remaining gates: \n";
					castle.displayGateList(prince.getLevel());
				}
				break;
			}
			case 5: {
				castle.displayGateList();
				break;
			}
			default: {
				cout << "Invalid choice! Please select other choices...\n";
			}
		}
	} while (choice != -1);

	return 0;
}