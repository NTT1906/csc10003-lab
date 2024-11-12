#ifndef INC_23127255_W05_VOUCHER_H
#define INC_23127255_W05_VOUCHER_H

#include <iostream>

class Voucher{
	int type;
	double data;
public:
	const static int TYPE_PERCENT;
	const static int TYPE_DISCOUNT;
	Voucher();
	Voucher(double data, int type = TYPE_PERCENT);
	int getVoucherType() const;
	double getData() const;
};

#endif //INC_23127255_W05_VOUCHER_H
