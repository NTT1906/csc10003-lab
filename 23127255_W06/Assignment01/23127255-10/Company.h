#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <vector>
#include "BillType.h"
#include "Bill.h"
#include "GrowthBill.h"

class Company{
	std::vector<Bill *> bills;
public:
	Company();
	~Company();
	Company &input();
	Company &output();

	bool addBill(const std::string &id, const std::string &userName, const std::string &productName, double productPrice, double tax = 0);
	bool addBill(const Bill &bill);
	bool addBill(const GrowthBill &bill);
	Company &sortBill();
	std::vector<Bill> getBillsWithUserName(const std::string &userName) const;
	int countGrowthBill() const;
	double getTotalIncome() const;
};

#endif //COMPANY_H
