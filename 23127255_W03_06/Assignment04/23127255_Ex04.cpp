#include <iostream>
#include "student.h"

using namespace std;

int main() {
	// Create Students with different constructors
	Student s1;
	Student s2(1, "John Doe");
	Student s3(2, "Jane Smith", "123 Main St");
	Student s4(3, "Alice Johnson", "456 Elm St", 3.9);

	// Copy constructor
	Student s5(s4);

	// Move constructor
	Student s6(std::move(s4));

	// String constructor
	Student s7("4,Charlie Brown,789 Oak St,3.5");

	// Output student details
	std::cout << "Student s1: \"" << s1.toString() << "\"\n";
	std::cout << "Student s2: \"" << s2.toString() << "\"\n";
	std::cout << "Student s3: \"" << s3.toString() << "\"\n";
	std::cout << "Student s4: \"" << s4.toString() << "\"\n"; // Moved, should be empty/default
	std::cout << "Student s5 (copy of s4): \"" << s5.toString() << "\"\n";
	std::cout << "Student s6 (moved s4): \"" << s6.toString() << "\"\n";
	std::cout << "Student s7: \"" << s7.toString() << "\"\n";

	// Clone method
	Student s8 = s7.clone();
	std::cout << "Student s8 (clone of s7): \"" << s8.toString() << "\"\n";

	return 0;
}