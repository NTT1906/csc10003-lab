#include "product.h"

Product::Product() : name("N/A"), size("N/A"), shop("N/A"), price(-1.0) {}
Product::Product(const std::string &_name, const std::string &_size, const std::string &_shop, double _price) : name(_name), size(_size), shop(_shop), price{_price} {}
Product::Product(const std::string &_name, const std::string &_shop, double _price) : name(_name), size("NA"), shop(_shop), price{_price} {}
Product::Product(const Product &other) : name(other.name), size(other.size), shop(other.shop), price(other.price) {}
std::string Product::getName() const { return name; }
std::string Product::getSize() const { return size; }
std::string Product::getShop() const { return shop; }
double Product::getPrice() const { return price; }

Product &Product::setPrice(double _price) {
	this->price = _price;
	return *this;
}
