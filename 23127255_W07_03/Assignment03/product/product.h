#ifndef INC_23127255_W07_PRODUCT_H
#define INC_23127255_W07_PRODUCT_H

class ProductType{ // Enumerated Gate Type
public:
	static const int TYPE_BOOK = 0; // Improve IQ, add 5 IQ points
	static const int TYPE_POTION = 1; // Improve Strength, add 2 strength level
	static const int TYPE_WEAPON = 2; // Improve Strength, add 3 strength level
};

class Product{
	int type;
	double unitPrice;
public:
	Product(int type, double unitPrice);
	int getType() const;
	int getEffect() const;
	double getUnitPrice() const;
};

#endif //INC_23127255_W07_PRODUCT_H