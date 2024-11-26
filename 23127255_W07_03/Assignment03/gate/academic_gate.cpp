#include "academic_gate.h"

AcademicGate::AcademicGate(unsigned long long int requiredIQ) : requiredIQ{requiredIQ} {}
int AcademicGate::getType() { return GateType::TYPE_ACADEMIC; }
bool AcademicGate::dealPrince(Prince &prince) { return requiredIQ < prince.getIQ(); }
unsigned long long AcademicGate::getRequiredIQ() const { return requiredIQ; }
