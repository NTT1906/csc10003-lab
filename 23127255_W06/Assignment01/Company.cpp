#include "Company.h"
#include <algorithm>

Company::Company() = default;

Company::~Company() {
	for (auto &bill : bills) {
		delete bill;
	}
}

Company &Company::input() {
	std::string id, userName, productName;
	do {
		std::cout << "Enter Bill ID: ";
		std::getline(std::cin, id);
		if (id.empty() || id.length() > 7) {
			std::cout << "Bill ID must have less than 7 characters and non empty!\n";
		}
	} while (id.empty() || id.length() > 7);
	std::cout << "Enter User Name: ";
	std::getline(std::cin, userName);
	std::cout << "Enter Product Name: ";
	getline(std::cin, productName);
	std::cout << "Enter Product Price: ";
	double productPrice;
	std::cin >> productPrice;
	std::cout << "Is growth bill? (0 = skip, 1 = yes): ";
	int skipGrowth;
	std::cin >> skipGrowth;
	if (skipGrowth != 0) {
		double tax;
		std::cout << "Enter Bill Tax: ";
		std::cin >> tax;
		addBill(GrowthBill(id, userName, productName, productPrice, tax));
	} else {
		addBill({id, userName, productName, productPrice});
	}
	std::cin.ignore();
	return *this;
}

Company &Company::output() {
	for (auto const &bill : bills) {
		std::cout << "Bill ID: " << bill->getId() << "\n";
		std::cout << "Bill User Name: " << bill->getUserName() << "\n";
		std::cout << "Bill Product Name: " << bill->getProductName() << "\n";
		std::cout << "Bill Product Price: " << bill->getProductPrice() << "\n";
		std::cout << "Bill Type: " << (bill->getBillType() == BillType::TYPE_GROWTH ? "growth" : "normal") << "\n";
		if (bill->getBillType() == BillType::TYPE_GROWTH) {
			std::cout << "Bill Tax: " << static_cast<const GrowthBill *> (bill)->getTax() << "\n";
		}
		std::cout << "\n";
	}
	return *this;
}

double Company::getTotalIncome() const {
	double totalIncome = 0.0;
	for (auto &bill : bills) {
		totalIncome += bill->getFinalPrice();
	}
	return totalIncome;
}

bool Company::addBill(const std::string &id, const std::string &userName, const std::string &productName, double productPrice, double tax) {
	for (const auto &bill : bills) {
		if (bill->getId() == id) {
			return false;
		}
	}
	if (tax == 0) {
		bills.push_back(new Bill(id, userName, productName, productPrice));
	} else {
		bills.push_back(new GrowthBill(id, userName, productName, productPrice, tax));
	}
	return true;
}

bool Company::addBill(const Bill &bill) {
	return addBill(bill.getId(), bill.getUserName(), bill.getProductName(), bill.getProductPrice());
}

bool Company::addBill(const GrowthBill &bill) {
	return addBill(bill.getId(), bill.getUserName(), bill.getProductName(), bill.getProductPrice(), bill.getTax());
}

int sortBillByPrice(Bill *a, Bill *b) {
	double pDiff =  a->getFinalPrice() - b->getFinalPrice();
	if (pDiff == 0.0) {
		return a->getUserName() < b->getUserName();
	}
	return pDiff > 0;
}

Company &Company::sortBill() {
	std::sort(bills.begin(), bills.end(), sortBillByPrice);
	return *this;
}

std::vector<Bill> Company::getBillsWithUserName(const std::string &userName) const {
	std::vector<Bill> r;
	for (auto &bill : bills) {
		if (bill->getUserName() == userName) {
			r.push_back(*bill);
		}
	}
	return r;
}

int Company::countGrowthBill() const {
	int c = 0;
	for (auto &bill : bills) {
		if (bill->getBillType() == BillType::TYPE_GROWTH) c++;
	}
	return c;
}

