#include <iostream>
#include "citems.h"
#include "cfolder.h"
#include "cfile.h"

using namespace std;

int main() {
	CFolder C("C"); // (1)
	CFolder System("System");
	CFolder Windows("Windows");
	CFolder Downloads("Downloads");

	CFile a_txt("a.txt", 123); // (2)
	CFile b_doc("b.doc", 456);
	CFile c_png("c.png", 1922, false, true);

	System.add(&a_txt); // (3)
	Windows.add(&b_doc);
	Windows.add(&c_png);

	C.add(&System); // (4)
	C.add(&Windows);
	C.add(&Downloads);
	std::cout << "Content of folder C ->" << '\n';
	bool isPrintHiddenItems = false;
	C.print(isPrintHiddenItems); // print hidden items or not? 1/0 (5)
	std::cout << '\n';


	CItems *p = C.removeByName("System"); // (6)
	if (p == nullptr) {
		std::cout << "Folder System does not exist in folder C!\n";
	} else {
		std::cout << "Content of folder C after removing folder System ->" << '\n';
		C.print(false);
	}
	std::cout << '\n';

	p = C.findByName("b.doc"); // (7)
	if (p != nullptr) {
		std::cout << "b.doc is found in folder C" << '\n';
	} else {
		std::cout << "b.doc is not found in folder C" << '\n';
	}
	std::cout << '\n';

	p = C.findByName("a.txt");
	if (p != nullptr) {
		std::cout << "a.txt is found in folder C" << '\n';
	} else {
		std::cout << "a.txt is not found in folder C" << '\n';
	}
	std::cout << '\n';

	p = C.findByName("Windows"); // (8)
	bool isHidden;
	bool isAlsoApplyToChildren;
	if (p != nullptr) {
		std::cout << "Folder Windows is found. Content of folder Windows ->" << '\n';
		isHidden = true;
		isAlsoApplyToChildren = false;
		// set HIDDEN to folder p and do not change hidden attributes of its sub-items
		p->setHidden(isHidden, isAlsoApplyToChildren); // (9)
		p->print(true);
		std::cout << '\n';

		// set HIDDEN to folder p and all its items
		isHidden = true; isAlsoApplyToChildren = true;
		p->setHidden(isHidden, isAlsoApplyToChildren); // (10)
		p->print(true);
		std::cout << '\n';
	} else {
		std::cout << "Folder Windows is not found" << '\n';
	}

	int CSize = (int) C.getItemSize();
	std::cout << "Size of folder C finally is " << CSize << '\n';

	return 0;
}
