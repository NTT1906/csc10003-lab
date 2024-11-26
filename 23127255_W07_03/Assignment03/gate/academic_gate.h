#ifndef INC_23127255_W07_ACADEMIC_GATE_H
#define INC_23127255_W07_ACADEMIC_GATE_H

#include "gate.h"

class AcademicGate : public Gate{
	unsigned long long requiredIQ;
public:
	AcademicGate(unsigned long long requiredIQ);
	int getType() override;
	unsigned long long getRequiredIQ() const;
	bool dealPrince(Prince &prince) override;
};

#endif //INC_23127255_W07_ACADEMIC_GATE_H