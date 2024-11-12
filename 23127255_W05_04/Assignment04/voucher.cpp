#include "voucher.h"

const int Voucher::TYPE_PERCENT = 0;
const int Voucher::TYPE_DISCOUNT = 1;

Voucher::Voucher() : data{}, type{TYPE_PERCENT} {}
Voucher::Voucher(double _data, int _type) : data{_data} {
	if (_type == TYPE_DISCOUNT) {
		type = TYPE_DISCOUNT;
	} else {
		type = TYPE_PERCENT;
		if (data > 100.0) data = 100.0;
	}
}

int Voucher::getVoucherType() const { return type; }
double Voucher::getData() const { return data; }
