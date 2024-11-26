#ifndef INC_23127255_W07_GATE_H
#define INC_23127255_W07_GATE_H

#include "../prince.h"

class GateType{ // Enumerated Gate Type
public:
	static const int TYPE_BUSINESS = 0;
	static const int TYPE_ACADEMIC = 1;
	static const int TYPE_POWER = 2;
};

class Gate{
public:
	Gate();
	~Gate() = default;
	Gate(Gate &&other) noexcept;
	virtual int getType() = 0;
	virtual bool dealPrince(Prince &prince);
};

#endif //INC_23127255_W07_GATE_H