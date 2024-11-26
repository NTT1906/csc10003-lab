#include "prince.h"

Prince::Prince(double money, u64 iq, u64 strength, u64 level) : money{money}, iq{iq}, strength{strength}, level{level} {}

Prince &Prince::setMoney(double _money) {
	money = _money;
	return *this;
}

Prince &Prince::setIQ(u64 _iq) {
	iq = _iq;
	return *this;
}

Prince &Prince::setStrength(u64 _strength) {
	strength = _strength;
	return *this;
}

Prince &Prince::setLevel(u64 int _level) {
	level = _level;
	return *this;
}

Prince &Prince::addLevel(u64 int _level) {
	level += _level;
	return *this;
}

double Prince::getMoney() const { return money; }
u64 Prince::getIQ() const { return iq; }
u64 Prince::getStrength() const { return strength; }
u64 Prince::getLevel() const { return level; }

Prince &Prince::useProduct(const Product &product, unsigned int amount) {
	switch (product.getType()) {
		case ProductType::TYPE_BOOK:
			iq += product.getEffect() * amount;
			break;
		case ProductType::TYPE_POTION:
		case ProductType::TYPE_WEAPON:
			strength += product.getEffect() * amount;
			break;
		default:
			return *this;
	}
	return *this;
}

#include <iostream>

void Prince::displayInformation() const {
	std::cout << "Money   : " << std::fixed << money << "\n"
			  << "IQ      : " << iq << "\n"
			  << "Strength: " << strength << "\n"
			  << "Level   : " << level << "\n";
}
