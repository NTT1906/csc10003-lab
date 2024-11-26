#include "business_gate.h"

BusinessGate::BusinessGate(Product _product, unsigned int _requireAmount) : product(_product), requireAmount{_requireAmount} {}

int BusinessGate::getType() { return GateType::TYPE_BUSINESS; }

bool BusinessGate::dealPrince(Prince &prince) {
	double pMoney = prince.getMoney();
	double cost = getCost();
	if (cost > pMoney) {
		return false;
	}
	prince.setMoney(pMoney - cost);
	return true;
}

double BusinessGate::getCost() const { return getUnitPrice() * requireAmount; }
double BusinessGate::getUnitPrice() const { return product.getUnitPrice(); }
unsigned int BusinessGate::getRequireAmount() const {return requireAmount; }
Product BusinessGate::getProduct() const { return product; }
