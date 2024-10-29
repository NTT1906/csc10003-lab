#include "MyIntArr.h"

int main() {
	// Default constructor
	MyIntArr arr1;
	std::cout << "Array 1 (Default Constructor): \"" << arr1.toString() << "\"\n";

	// Sized constructor
	MyIntArr arr2(5);
	std::cout << "Array 2 (Sized Constructor): \"" << arr2.toString() << "\"\n";

	// Copy array constructor
	int data[] = {1, 2, 3, 4, 5};
	MyIntArr arr3(data, 5);
	std::cout << "Array 3 (Copy Array Constructor): \"" << arr3.toString() << "\"\n";

	// Copy constructor
	MyIntArr arr4 = arr3;
	std::cout << "Array 4 (Copy Constructor): \"" << arr4.toString() << "\"\n";

	// Move constructor
	MyIntArr arr5 = std::move(arr4);
	std::cout << "Array 5 (Move Constructor): \"" << arr5.toString() << "\"\n";
	std::cout << "Array 4 after move: \"" << arr4.toString() << "\"\n";

	// String constructor
	MyIntArr arr6("10,20,30,40,50");
	std::cout << "Array 6 (String Constructor): \"" << arr6.toString() << "\"\n";

	std::cout << "Clone array 5 into array 7\n";
	MyIntArr arr7 = arr5.clone();
	std::cout << "Array 7 (Clone from array 5): \"" << arr7.toString() << "\"\n";

	return 0;
}
