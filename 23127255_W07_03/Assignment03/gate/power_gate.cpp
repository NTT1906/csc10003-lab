#include "power_gate.h"

PowerGate::PowerGate(u64 warriorStrength, u64 reduceStrength) : strength{warriorStrength}, reduceStrength{reduceStrength} {}

int PowerGate::getType() { return GateType::TYPE_POWER; }

bool PowerGate::dealPrince(Prince &prince) {
	if (prince.getStrength() >= strength) {
		prince.setStrength(prince.getStrength() - reduceStrength);
		return true;
	}
	return false;
}

u64 PowerGate::getStrength() const { return strength; }
u64 PowerGate::getReduceStrength() const { return reduceStrength; }
