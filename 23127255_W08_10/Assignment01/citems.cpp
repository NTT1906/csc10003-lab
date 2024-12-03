#include "citems.h"

CItems::CItems() : hidden(false) {}
CItems::CItems(const std::string &name, bool isHidden) : name(name), hidden(isHidden) {}

bool CItems::isHidden() const { return hidden; }
std::string CItems::getName() const { return name; }
