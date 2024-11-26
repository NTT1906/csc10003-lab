#include "castle.h"

Castle::Castle() = default;

Castle::~Castle() {
	for (auto &gate : gates) {
		delete gate;
	}
}

unsigned long long Castle::entry(Prince prince) {
	unsigned long long i = prince.getLevel();
	unsigned long long n = gates.size();
	while (i < n) {
		Gate *gate = gates[i];
		if (!gate->dealPrince(prince)) {
			return i;
		}
		if (gate->getType() == GateType::TYPE_BUSINESS) {
			auto *bGate = static_cast<BusinessGate *>(gate); // NOLINT(*-pro-type-static-cast-downcast)
			Product product = bGate->getProduct();
			prince.useProduct(product, bGate->getRequireAmount());
		}
		++i;
	}
	return i;
}

unsigned long long Castle::getGateAmount() const { return gates.size(); }

Castle &Castle::displayGateList(unsigned long long int start) {
	unsigned long long i = start;
	unsigned long long n = gates.size();
	while (i < n) {
		Gate *gate = gates[i];
		std::cout << "Gate " << i + 1 << ": ";
		switch (gate->getType()) {
			case GateType::TYPE_BUSINESS: {
				std::cout << "Bussiness Gate\n";
				auto *castGate = static_cast<BusinessGate *>(gate); // NOLINT(*-pro-type-static-cast-downcast)
				Product product = castGate->getProduct();
				std::cout << " + Product: ";
				switch (product.getType()) {
					case ProductType::TYPE_BOOK:
						std::cout << "Book [Add IQ]\n";
						break;
					case ProductType::TYPE_POTION:
						std::cout << "Potion [Add strength]\n";
						break;
					case ProductType::TYPE_WEAPON:
						std::cout << "Weapon [Add strength]\n";
						break;
					default: {
						std::cout << "Unknown?\n";
						continue;
					}
				}
				std::cout << " + Required quantity: " << castGate->getRequireAmount() << "\n";
				break;
			}
			case GateType::TYPE_ACADEMIC: {
				std::cout << "Academic Gate\n";
				auto *castGate = static_cast<AcademicGate *>(gate); // NOLINT(*-pro-type-static-cast-downcast)
				std::cout << " + Required intelligence level: " << castGate->getRequiredIQ() << "\n";
				break;
			}
			case GateType::TYPE_POWER: {
				std::cout << "Power Gate\n";
				auto *castGate = static_cast<PowerGate *>(gate); // NOLINT(*-pro-type-static-cast-downcast)
				std::cout << " + Warrior Strength Level: " << castGate->getStrength() << "\n";
				std::cout << " + Reduced Strength Level (After victory): " << castGate->getReduceStrength() << "\n";
				break;
			}
			default:
				std::cout << "Unknown gate! Skipping...\n";
				continue;
		}
		++i;
	}
	return *this;
}

void Castle::addGate(Gate *gate) { if (gate != nullptr) gates.push_back(gate); }

