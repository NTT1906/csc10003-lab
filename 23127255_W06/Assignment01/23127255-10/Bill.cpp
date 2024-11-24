#include "Bill.h"
Bill::Bill() : productPrice{} {}
Bill::Bill(const std::string &_id, const std::string &_userName, const std::string &_productName, double _productPrice) : id(_id), userName(_userName), productName(_productName), productPrice{_productPrice} {}

int Bill::getBillType() const { return BillType::TYPE_NORMAL; }
std::string Bill::getId() const { return id; }
std::string Bill::getUserName() const { return userName; }
std::string Bill::getProductName() const { return productName; }
double Bill::getProductPrice() const { return productPrice; }
double Bill::getFinalPrice() { return productPrice; }
