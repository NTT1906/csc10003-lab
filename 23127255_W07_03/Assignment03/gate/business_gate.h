#ifndef INC_23127255_W07_BUSINESS_GATE_H
#define INC_23127255_W07_BUSINESS_GATE_H

#include "gate.h"

class BusinessGate : public Gate{
	Product product;
	unsigned int requireAmount;
public:
	BusinessGate(Product product, unsigned int requireAmount);
	int getType() override;
	double getUnitPrice() const;
	unsigned int getRequireAmount() const;
	double getCost() const;
	Product getProduct() const;
	bool dealPrince(Prince &prince) override;
};

#endif //INC_23127255_W07_BUSINESS_GATE_H
