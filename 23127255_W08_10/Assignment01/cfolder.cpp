#include "cfolder.h"

CFolder::CFolder() = default;
CFolder::CFolder(const std::string &name, bool isHidden) : CItems(name, isHidden) {}

bool CFolder::isFolder() { return true; }

unsigned long long CFolder::getItemSize() {
	unsigned long long size = 0;
	for (auto &item : items) {
		size += item->getItemSize();
	}
	return size;
}

CItems *CFolder::removeByName(const std::string &name, bool recursive) {
	unsigned long long l = items.size();
	for (int i = 0; i < l; ++i) {
		if (name == items[i]->getName()) {
			CItems *tmp = items[i];
			items.erase(items.begin() + i);
			return tmp;
		}
	}
	if (recursive) {
		for (CItems *item : items) {
			if (item->isFolder()) {
				CItems *tmp = static_cast<CFolder *>(item)->removeByName(name); // NOLINT(*-pro-type-static-cast-downcast)
				if (tmp != nullptr) {
					return tmp;
				}
			}
		}
	}
	return nullptr;
}

CItems *CFolder::findByName(const std::string &name, bool recursive) {
	for (auto &item : items) {
		if (name == item->getName()) {
			return item;
		}
	}
	if (recursive) {
		for (CItems *item : items) {
			if (item->isFolder()) {
				CItems *tmp = static_cast<CFolder *>(item)->findByName(name); // NOLINT(*-pro-type-static-cast-downcast)
				if (tmp != nullptr) {
					return tmp;
				}
			}
		}
	}
	return nullptr;
}

void CFolder::setHidden(bool isHidden, bool applyToChildren) {
	hidden = isHidden;
	if (applyToChildren) {
		for (auto &item : items) {
			item->setHidden(isHidden, applyToChildren);
		}
	}
}

void CFolder::print(bool printHidden, const std::string &prefix) {
	if (!hidden || printHidden) {
		std::cout << name << " - " << getItemSize() << " bytes" << (hidden ? " - (hidden)" : "") << "\n";

		for (int i = 0; i < items.size(); ++i) {
			bool isLast = (i == items.size() - 1);
			std::cout << prefix << (isLast ? "└── " : "├── ");
			if (items[i]->isFolder()) {
				static_cast<CFolder *>(items[i])->print(printHidden, prefix + "│   "); // NOLINT(*-pro-type-static-cast-downcast)
			} else {
				items[i]->print(printHidden);
			}
		}
	}
}


void CFolder::add(CItems *item) {
	items.push_back(item);
}

void CFolder::print(bool printHidden) {
	CFolder::print(printHidden, "");
}
