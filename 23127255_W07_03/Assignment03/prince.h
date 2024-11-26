#ifndef INC_23127255_W07_PRINCE_H
#define INC_23127255_W07_PRINCE_H

#ifndef u64
#define u64 unsigned long long
#endif

#include "product/product.h"

class Prince{
	double money;
	u64 iq;
	u64 strength;
	u64 level;
public:
	Prince() : money{0.0}, iq{0}, level{0}, strength{0} {}
	Prince(double money, u64 iq, u64 strength, u64 level = 0);
	Prince &setMoney(double money);
	Prince &setIQ(u64 iq);
	Prince &setStrength(u64 strength);
	Prince &setLevel(u64 level);
	Prince &addLevel(u64 level);
	Prince &useProduct(const Product &product, unsigned int amount = 1);
	double getMoney() const;
	u64 getIQ() const;
	u64 getStrength() const;
	u64 getLevel() const;
	void displayInformation() const;
};

#endif //INC_23127255_W07_PRINCE_H