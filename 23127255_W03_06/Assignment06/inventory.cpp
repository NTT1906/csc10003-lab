#include "inventory.h"

Slot::Slot() : product(), quantity{}, totalPrice{} {}
Slot::Slot(const Product &product, int quantity) : product(product), quantity(quantity), totalPrice{} {}
Product &Slot::getProduct() { return product; }

int Slot::getQuantity() const { return quantity; }

Slot &Slot::setQuantity(int _quantity) {
	quantity = _quantity;
	return *this;
}

double Slot::getTotalPrice() const { return quantity * product.getPrice(); }

Slot &Inventory::getSlot(int slot) {
	if (!isValidSlot(slot)) {
		throw std::invalid_argument("Slot must be in the initiated list!");
	}
	return slots[slot];
}

Product &Inventory::getProduct(int slot) { return this->getSlot(slot).getProduct(); }

Inventory *Inventory::instance = nullptr;

Inventory &Inventory::getInstance() {
	if (instance == nullptr) instance = new Inventory;
	return *instance;
}

Inventory &Inventory::removeProduct(int slot) {
	if (!isValidSlot(slot)) {
		throw std::invalid_argument("Slot must be in the initiated list!");
	}
	slots.erase(slots.begin() + slot);
	return *this;
}

bool Inventory::isValidSlot(int slot) const {
	return slot >= 0 && slot < slots.size();
}

bool compareByShop(Slot &a, Slot &b) {
	return a.getProduct().getShop() < b.getProduct().getShop();
}

#include <algorithm>

void Inventory::display() const {
	std::vector<Slot> cp = slots;

	std::sort(cp.begin(), cp.end(), compareByShop);

	double totalPrice = 0;

	size_t l = cp.size();

	for (int i = 0; i < l; i++) {
		Slot slot = cp[i];
		Product prod = slot.getProduct();
		if (i == 0 || cp[i - 1].getProduct().getShop() != cp[i].getProduct().getShop()) {
			std::cout << "SHOP: " << prod.getShop() << "\n";
		}

		std::cout << "Name:       " << prod.getName() << "\n";
		std::cout << "Size:       " << prod.getSize() << "\n";
		std::cout << "Unit Price: " << prod.getPrice() << "\n";
		std::cout << "Quantity:   " << slot.getQuantity() << "\n";
		std::cout << "Price:      " << slot.getTotalPrice() << "\n\n";

		if (i == l - 1 || cp[i].getProduct().getShop() != cp[i + 1].getProduct().getShop()) {
			std::cout << "        -=-\n";
		}
		totalPrice += slot.getTotalPrice();
	}
	std::cout << "\n---------------------\n";
	std::cout << "TOTAL PRICE: " << totalPrice << "\n";
}

Inventory &Inventory::addProduct(const Product &product, int amount = 1) {
	int i = searchProduct(product);
	if (i != -1) { // product already added
		this->slots[i].setQuantity(this->slots[i].getQuantity() + amount);
		this->slots[i].getProduct().setPrice(product.getPrice()); // take the newest price as the current price
		return *this;
	}
	this->slots.emplace_back(product, amount);
	return *this;
}

int Inventory::searchProduct(const Product &product) {
	for (int i = 0; i < slots.size(); ++i) {
		if (product.getName() == slots[i].getProduct().getName() && product.getShop() == slots[i].getProduct().getShop()
		&& product.getSize() == slots[i].getProduct().getSize()) {
			return i;
		}
	}
	return -1;
}

void Inventory::displayEnumeratedList() const {
	size_t l = slots.size();
	std::cout << "                         ENUMERATED INVENTORY:\n";
	printf("%-7s | %-30s | %-10s | %-30s | %-20s\n", "Idx", "Product Name", "Size", "Shop", "Price");
	for (int i = 0; i < l; ++i) {
		Slot slot = slots[i];
		Product product = slot.getProduct();
		printf("%-7d | %-30s | %-10s | %-30s | %-20.2f\n", i, product.getName().c_str(), product.getSize().c_str(), product.getShop().c_str(), product.getPrice());
//		std::cout << i << ") " << product.getName() << " | " << product.getSize() << " | " << product.getShop() << " | " << product.getPrice() << " = " << slot.getQuantity() << "\n";
	}
}

size_t Inventory::getInventorySize() const { return slots.size(); }

Inventory::Inventory() = default;

