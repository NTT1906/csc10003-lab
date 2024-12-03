#ifndef INC_23127255_W07_CFOLDER_H
#define INC_23127255_W07_CFOLDER_H

#include <iostream>
#include <vector>
#include "citems.h"

class CFolder : public CItems{
	std::vector<CItems *> items;
public:
	CFolder();
	CFolder(const std::string &name, bool isHidden = false);
	void add(CItems *item);
	void print(bool printHidden) override;
	void print(bool printHidden, const std::string& prefix);
	bool isFolder() override;
	unsigned long long getItemSize() override;
	void setHidden(bool isHidden, bool applyToChildren) override;
	CItems *removeByName(const std::string &name, bool recursive = true);
	CItems *findByName(const std::string &name, bool recursive = true);
};

#endif //INC_23127255_W07_CFOLDER_H