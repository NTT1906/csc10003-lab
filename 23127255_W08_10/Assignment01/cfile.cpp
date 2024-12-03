#include "cfile.h"

CFile::CFile() : size(0), readonly(false) {}
CFile::CFile(const std::string &name, unsigned long long size, bool isHidden, bool isReadonly) : CItems(name, isHidden), size(size), readonly(isReadonly) {}

bool CFile::isFolder() { return false; }
unsigned long long CFile::getItemSize() { return size; }
void CFile::setHidden(bool isHidden, bool applyToChildren) { hidden = isHidden; }
bool CFile::isReadonly() const { return readonly; }
void CFile::setReadonly(bool isReadonly) { readonly = isReadonly; }

void CFile::print(bool printHidden) {
	if (!hidden || printHidden) {
		std::cout << name << " - " << size << " bytes" << (readonly ? " - (readonly)" : "") << (hidden ? " - (hidden)" : "") << "\n";
	}

}
