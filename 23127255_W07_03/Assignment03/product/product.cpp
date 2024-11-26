#include "product.h"

Product::Product(int type, double unitPrice) : type{type}, unitPrice{unitPrice} {}

int Product::getEffect() const {
	switch (type) {
		case ProductType::TYPE_BOOK:
			return 5;
		case ProductType::TYPE_POTION:
			return 2;
		case ProductType::TYPE_WEAPON:
			return 3;
		default:
			return 0;
	}
}

int Product::getType() const { return type; }
double Product::getUnitPrice() const { return unitPrice; }

