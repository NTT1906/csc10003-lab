#ifndef GROWTHBILL_H
#define GROWTHBILL_H

#include "Bill.h";

class GrowthBill : public Bill {
	double tax;
public:
	GrowthBill();
	GrowthBill(const std::string &id, const std::string &userName, const std::string &productName, double productPrice, double tax);
	int getBillType() const override;
	double getTax() const;
	double getFinalPrice() override;
};

#endif //GROWTHBILL_H
