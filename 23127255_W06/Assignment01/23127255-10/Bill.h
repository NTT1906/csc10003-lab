#ifndef BILL_H
#define BILL_H

#include <iostream>
#include "BillType.h"

class Bill {
protected:
	BillType type;
	std::string id;
    std::string userName;
	std::string productName;
	double productPrice;
public:
	Bill();
	Bill(const std::string &id, const std::string &userName, const std::string &productName, double productPrice);
	virtual int getBillType() const;
	std::string getId() const;
	std::string getUserName() const;
	std::string getProductName() const;
	double getProductPrice() const;
	virtual double getFinalPrice();
};

#endif //BILL_H
