#ifndef INC_23127255_W07_CFILE_H
#define INC_23127255_W07_CFILE_H

#include "citems.h"

class CFile : public CItems{
	unsigned long long size;
	bool readonly;
public:
	CFile();
	CFile(const std::string &name, unsigned long long size, bool isHidden = false, bool isReadonly = false);
	void print(bool printHidden) override;
	bool isFolder() override;
	unsigned long long getItemSize() override;
	bool isReadonly() const;
	void setHidden(bool isHidden, bool applyToChildren) override;
	void setReadonly(bool isReadonly);
};

#endif //INC_23127255_W07_CFILE_H