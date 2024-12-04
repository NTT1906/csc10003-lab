#include <iostream>
#include "vector.h"
#include "fraction.h"

using namespace std;

template<>
string MyVector<int>::getTypeName() const {
	return "int";
}

template<>
string MyVector<Fraction>::getTypeName() const {
	return "Fraction";
}

void mainIntVector() {
	cout << "--= Int MyVector =--\n";
	int a[] = {1, 2, 3, 4, 5};
	int n = 5;
	MyVector<int> v(a, n);
	cout << "[+] Init MyVector<int> with input int[5](1, 2, 3, 4, 5).\n";
	cout << "[>] Current MyVector<int>: \n" << v.toString() << "\n";
	int a2[] = {6, 7, 8, 7};
	cout << "[+] Add int[4](6, 7, 8, 7) to MyVector<int>.\n";
	v.addRange(a2, 4);
	cout << "[>] Current MyVector<int>: \n" << v.toString() << "\n";

	cout << "[-] Remove 7 from MyVector<int>.\n";
	v.remove(7);
	cout << "[>] Current MyVector<int>: \n" << v.toString() << '\n';
	cout << "[?] Is 2 in MyVector<int>? " << (v.contains( 2) ? "YES" : "NO") << '\n';
	cout << "[?] Is 9 in MyVector<int>? " << (v.contains( 9) ? "YES" : "NO") << '\n';
	cout << "[-] Clearing MyVector<int>...\n";
	v.clear();
	cout << "[>] Current MyVector<int>: \n" << v.toString() << '\n';
	int a3[] = {2, 3, 4, 5};
	v.addRange(a3, 4);
	cout << "[+] Add int[4](2, 3, 4, 5) to MyVector<int>.\n";
	cout << "[>] Current MyVector<int>: \n" << v.toString() << '\n';
	try {
		cout << "[-] Removing value at index 3...\n";
		v.removeAt(3);
		cout << "[-] Removing value at index 4...\n";
		v.removeAt(4);
	} catch (std::invalid_argument &e) {
		cout << "[!] " << e.what() << '\n';
	}
	cout << "[>] Current MyVector<int>: \n" << v.toString() << '\n';
	try {
		cout << "[+] Inserting value 9 at index 2...\n";
		v.insert(9, 2);
		cout << "[+] Removing value 8 at index 4...\n";
		v.insert(8, 4);
	} catch (std::invalid_argument &e) {
		cout << "[!] " << e.what() << '\n';
	}
	cout << "[>] Current MyVector<int>: \n" << v.toString() << '\n';
	v.addRange(a3, 4);
	cout << "[+] Add int[4](2, 3, 4, 5) to MyVector<int>.\n";
	cout << "[>] Current MyVector<int>: \n" << v.toString() << '\n';
	v.reverse();
	cout << "[>] Reversed MyVector<int>: \n" << v.toString() << '\n';
	v.sortAsc();
	cout << "[>] Sorted Ascending MyVector<int>: \n" << v.toString() << '\n';
	v.sortDesc();
	cout << "[>] Sorted Descending MyVector<int>: \n" << v.toString() << '\n';
}

void mainFractionVector() {
	cout << "--= Fraction MyVector =--\n";
	Fraction f[] = {
		{1, 2},
		{2, 3},
		{3, 4},
		{2, 4}
	};
	cout << "[+] Init MyVector<Fraction> with input Fraction[4](1/2, 2/3, 3/4, 2/4).\n";
	MyVector<Fraction> v(f, 4);
	cout << "[>] Current MyVector<Fraction>: \n" << v.toString() << '\n';
	Fraction a2[] = {{11, 23}, {22, 37}, {12, 2}, {11, 12}};
	cout << "[+] Add Fraction[4](11/23, 22/37, 6, 11/12) to MyVector<int>.\n";
	v.addRange(a2, 4);
	cout << "[>] Current MyVector<Fraction>: \n" << v.toString() << "\n";

	try {
		cout << "[+] Creating Fraction f = 1/0\n";
		Fraction f(1, 0);
	} catch (std::invalid_argument &e) {
		cout << "[!] " << e.what() << '\n';
	}

	cout << "[-] Remove 7 from MyVector<Fraction>.\n";
	v.remove(7);
	cout << "[>] Current MyVector<Fraction>: \n" << v.toString() << '\n';
	cout << "[?] Is 11/23 in MyVector<Fraction>? " << (v.contains( {11, 23}) ? "YES" : "NO") << '\n';
	cout << "[?] Is 21/29 in MyVector<Fraction>? " << (v.contains( {21, 29}) ? "YES" : "NO") << '\n';
	cout << "[-] Clearing MyVector<Fraction>...\n";
	v.clear();
	cout << "[>] Current MyVector<Fraction>: \n" << v.toString() << '\n';
	Fraction a3[] = {{2, 3}, {5, 6}, {4, 5}, {3, 4}};
	v.addRange(a3, 4);
	cout << "[+] Add Fraction[4](2/3, 5/6, 4/5, 3/4) to MyVector<Fraction>.\n";
	cout << "[>] Current MyVector<Fraction>: \n" << v.toString() << '\n';
	try {
		cout << "[-] Removing value at index 3...\n";
		v.removeAt(3);
		cout << "[-] Removing value at index 4...\n";
		v.removeAt(4);
	} catch (std::invalid_argument &e) {
		cout << "[!] " << e.what() << '\n';
	}
	cout << "[>] Current MyVector<Fraction>: \n" << v.toString() << '\n';
	try {
		cout << "[+] Inserting value 111/123 at index 2...\n";
		v.insert({111, 123}, 2);
		cout << "[+] Removing value 11/23 at index 4...\n";
		v.insert({11, 23}, 4);
	} catch (std::invalid_argument &e) {
		cout << "[!] " << e.what() << '\n';
	}
	cout << "[>] Current MyVector<Fraction>: \n" << v.toString() << '\n';
	v.addRange(a3, 4);
	cout << "[+] Add Fraction[4](2/3, 5/6, 4/5, 3/4) to MyVector<Fraction>.\n";
	cout << "[>] Current MyVector<Fraction>: \n" << v.toString() << '\n';
	v.reverse();
	cout << "[>] Reversed MyVector<Fraction>: \n" << v.toString() << '\n';
	v.sortAsc();
	cout << "[>] Sorted Ascending MyVector<Fraction>: \n" << v.toString() << '\n';
	v.sortDesc();
	cout << "[>] Sorted Descending MyVector<Fraction>: \n" << v.toString() << '\n';
}

int main() {
	mainIntVector();
	cout << '\n';
	mainFractionVector();
	return 0;
}
