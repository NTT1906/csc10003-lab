#ifndef INC_23127255_W07_CITEMS_H
#define INC_23127255_W07_CITEMS_H

#include <iostream>
#include <string>

class CItems{
protected:
	std::string name;
	bool hidden;
public:
	CItems();
	CItems(const std::string &name, bool isHidden = false);
	virtual ~CItems() = default;
	virtual void print(bool printHidden) = 0;
	virtual void setHidden(bool isHidden, bool applyToChildren) = 0;
	virtual bool isFolder() = 0;
	virtual unsigned long long getItemSize() = 0;
	bool isHidden() const;
	std::string getName() const;
};

#endif //INC_23127255_W07_CITEMS_H