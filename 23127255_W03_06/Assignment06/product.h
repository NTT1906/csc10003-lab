#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <sstream>

class Product{
	std::string name;
	std::string size;
	std::string shop;
	double price;
public:
	Product();
	Product(const std::string &name, const std::string &shop, double price);
	Product(const std::string &name, const std::string &size, const std::string &shop, double price);
	Product(const Product &other);
	std::string getName() const;
	std::string getSize() const;
	std::string getShop() const;
	double getPrice() const;
	Product &setPrice(double price);
};

#endif //PRODUCT_H
