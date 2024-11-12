#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <fstream>
#include <sstream>
#include "product.h"
#include "voucher.h"

class Slot{
	Product product;
	int quantity;
public:
	Slot();
	Slot(const Product &product, int quantity);
	int getQuantity() const;
	Product &getProduct();
	double getTotalPrice() const;
	Slot &setQuantity(int quantity);
};

class Inventory{
	std::vector<Slot> slots;
	std::vector<Voucher> vouchers;
	static Inventory *instance;
	Inventory();
public:
	static Inventory &getInstance();
	Slot &getSlot(int slot);
	Product &getProduct(int slot);
	Inventory &removeProduct(int slot);
	Inventory &addProduct(const Product &product, int amount);
	int searchProduct(const Product &product);
	bool isValidSlot(int slot) const;
	size_t getInventorySize() const;
	void display() const;
	void displayEnumeratedList() const;
	bool loadProductFromFile(const std::string &fileName);
	bool addProductFromFile(const std::string &fileName);
	bool saveOrderToFile(const std::string &fileName);
	Inventory &addVoucher(const Voucher &voucher);
	void displayVouchers() const;
};

#endif //INVENTORY_H
