#ifndef INVENTORY_H
#define INVENTORY_H

#include "product.h"
#include <vector>

class Slot{
	Product product;
	int quantity;
	double totalPrice;
public:
	Slot();
	Slot(const Product &product, int quantity);
	int getQuantity() const;
	Product &getProduct();
	double getTotalPrice() const;
	Slot &setQuantity(int _quantity);
};

class Inventory{
	std::vector<Slot> slots;
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
};

#endif //INVENTORY_H
