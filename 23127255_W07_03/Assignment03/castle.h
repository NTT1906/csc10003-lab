#ifndef INC_23127255_W07_CASTLE_H
#define INC_23127255_W07_CASTLE_H

#include "gate/gate.h"
#include "gate/academic_gate.h"
#include "gate/business_gate.h"
#include "gate/power_gate.h"

#include "prince.h"

#include <iostream>
#include <vector>

class Castle{
	std::vector<Gate *> gates;
public:
	Castle();
	~Castle();
	void addGate(Gate *gate);
	unsigned long long entry(Prince prince);
	unsigned long long getGateAmount() const;
	Castle &displayGateList(unsigned long long start = 0);
};

#endif //INC_23127255_W07_CASTLE_H