#include "GrowthBill.h"
GrowthBill::GrowthBill() : Bill(), tax{} {}
GrowthBill::GrowthBill(const std::string &_id, const std::string &_userName, const std::string &_productName, double _productPrice, double _tax) : Bill(_id, _userName, _productName, _productPrice), tax{_tax} {}

int GrowthBill::getBillType() const { return BillType::TYPE_GROWTH; }

double GrowthBill::getTax() const { return tax; }
double GrowthBill::getFinalPrice() { return productPrice * (100.0 + tax) / 100.0; }
