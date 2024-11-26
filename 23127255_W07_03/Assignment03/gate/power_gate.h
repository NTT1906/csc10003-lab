#ifndef INC_23127255_W07_POWER_GATE_H
#define INC_23127255_W07_POWER_GATE_H

#include "gate.h"

#ifndef u64
#define u64 unsigned long long
#endif

class PowerGate : public Gate{
	u64 strength;
	u64 reduceStrength;
public:
	PowerGate(u64 warriorStrength, u64 reduceStrength = 0);
	int getType() override;
	u64 getStrength() const;
	u64 getReduceStrength() const;
	bool dealPrince(Prince &prince) override;
};

#endif //INC_23127255_W07_POWER_GATE_H