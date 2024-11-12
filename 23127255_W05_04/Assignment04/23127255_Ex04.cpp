#include "inventory.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
	// Clear screen for Windows
	std::system("cls");
#else
	// Clear screen for Linux and other Unix-like systems; ignoring MAC, Android, ...
	std::system("clear");
#endif
}

int main() {
	Inventory inv = Inventory::getInstance();
//	inv.addProduct({"Shirt", "M", "LocalBranch", 250.230}, 1)
//			.addProduct({"Dress", "L", "MALL LiTU", 311.21}, 3)
//			.addProduct({"Shirt", "M", "LocalBranch", 250.230}, 2)
//			.addProduct({"Bra", "M", "LocalBranch", 41.21}, 3)
//			.addProduct({"Shirt", "L", "LocalBranch", 257.230}, 3)
//			.addProduct({"Coffee", "10 packs", "Trung Nguyen", 111.21}, 3)
//			.display();


	int choice = -1;
	do {
		cout << "Menu:\n";
		cout << "1. Add product\n";
		cout << "2. Remove product by search\n";
		cout << "3. Remove product by slot's ID\n";
		cout << "4. Display Inventory/Price\n";
		cout << "5. Display Inventory/Price (List)\n";
		cout << "6. Change slot quantity\n";
		cout << "7. Load products from file (delete existed products)\n";
		cout << "8. Add products from file\n";
		cout << "9. Save orders to file\n";
		cout << "10. Add promotions (vouchers)\n";
		cout << "11. Display promotions (vouchers)\n";
		cout << "12. Exit\n";
		cout << "0. Clear screen\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 0: {
				clearScreen();
				break;
			}
			case 1: {
				string pName, pSize, pShop;
				double uPrice = -1;
				int quantity = 0;
				cin.ignore();
				cout << "Enter product name: ";
				getline(cin, pName);
				cout << "Enter product size: ";
				getline(cin, pSize);
				cout << "Enter shop's name: ";
				getline(cin, pShop);
				do {
					cout << "Enter unit price: ";
					cin >> uPrice;
					if (quantity < 0) {
						cout << "Invalid price!\n";
					}
				} while (uPrice < 0);

				do {
					cout << "Enter quantity: ";
					cin >> quantity;
					if (quantity <= 0) {
						cout << "Invalid quantity!\n";
					}
				} while (quantity <= 0);
				inv.addProduct({pName, pSize, pShop, uPrice}, quantity);
				break;
			}
			case 2: {
				string pName, pSize, pShop;
				cin.ignore();
				cout << "Enter product name: ";
				getline(cin, pName);
				cout << "Enter product size: ";
				getline(cin, pSize);
				cout << "Enter shop's name: ";
				getline(cin, pShop);
				int idx = inv.searchProduct({pName, pSize, pShop, -1});
				if (idx == -1) {
					cout << "Product with the exact information does not exist in the inventory.\n";
				} else {
					cout << "Product is removed from the inventory!\n";
					inv.removeProduct(idx);
				}
				break;
			}
			case 3: {
				inv.displayEnumeratedList();
				int idx = -1;
				size_t l = inv.getInventorySize();
				do {
					cout << "Enter idx (enter -1 to return to main menu): ";
					cin >> idx;
					if (idx == -1) break;
					if (idx >= l || idx < 0) {
						cout << "Invalid index, please input the correct value (0-" << l << ")\n";
					}
				} while (idx != -1 && (idx >= l || idx < 0));
				if (idx == -1) {
					cout << "Return to main MENU\n";
				} else if (l != 0) {
					Product p = inv.getProduct(idx);
					cout << "Product " << idx << " with name (" << p.getName() << ") is removed from the inventory.\n";
					inv.removeProduct(idx);
				}
				break;
			}
			case 4: {
				inv.display();
				break;
			}
			case 5: {
				inv.displayEnumeratedList();
				break;
			}
			case 6: {
				inv.displayEnumeratedList();
				int idx = -1;
				size_t l = inv.getInventorySize();
				cout << "Enter idx (enter -1 to return to main menu): ";
				do {
					cin >> idx;
					if (idx == -1) break;
					if (idx >= l || idx < 0) {
						cout << "Invalid index, please input the correct value (0-" << l << ")\n";
					}
				} while (idx != -1 && idx < l && idx >= 0);
				if (idx == -1) {
					cout << "Return to main MENU\n";
				} else if (l != 0) {
					cout << "Input new quantity: \n";
					Slot s = inv.getSlot(idx);
					int nQuantity;
					cin >> nQuantity;
					s.setQuantity(nQuantity);
					cout << "Product with given information had been updated its quantity to " << nQuantity << "!\n";
				}
				break;
			}
			case 7: {
				cin.ignore();
				cout << "Enter file path: ";
				string fileName;
				getline(cin, fileName);
				if (inv.loadProductFromFile(fileName)) {
					cout << "Successfully load products from file \"" << fileName << "\"\n";
				} else {
					cout << "Failed to load products from file \"" << fileName << "\"\n";
				}
				break;
			}
			case 8: {
				cin.ignore();
				cout << "Enter file path: ";
				string fileName;
				getline(cin, fileName);
				if (inv.addProductFromFile(fileName)) {
					cout << "Successfully add products from file \"" << fileName << "\"\n";
				} else {
					cout << "Failed to add products from file \"" << fileName << "\"\n";
				}
				break;
			}
			case 9: {
				cin.ignore();
				cout << "Enter file path: ";
				string fileName;
				getline(cin, fileName);
				if (inv.saveOrderToFile(fileName)) {
					cout << "Successfully saved the orders to file \"" << fileName << "\"\n";
				} else {
					cout << "Failed to save the orders to file \"" << fileName << "\"\n";
				}
				break;
			}
			case 10: {
				cout << "Enter voucher type (percent = 0, discount = 1): ";
				int type;
				cin >> type;
				if (type == Voucher::TYPE_DISCOUNT) {
					cout << "Enter discount amount: ";
				} else {
					cout << "Enter percentage amount (<=100%): ";
				}
				double data;
				cin >> data;
				inv.addVoucher({data, type});
				break;
			}
			case 11: {
				inv.displayVouchers();
				break;
			}
			case 12: {
				cout << "Exiting...\n";
				choice = -1;
				break;
			}
			default:
				cout << "Invalid choice. Please try again.\n";
				break;
		}
	} while (choice != -1);
	delete &Inventory::getInstance();
	return 0;
}
