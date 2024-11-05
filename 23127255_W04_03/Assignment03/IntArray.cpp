#include "IntArray.h"

IntArray::IntArray() : data{nullptr}, n{0} {}

IntArray::IntArray(const int arr[], int _n) : n{_n} {
	data = new int[n]{};
	for (int i = 0; i < n; ++i) data[i] = arr[i];
}

IntArray::IntArray(const IntArray &other) {
	if (n != other.n || data == nullptr) {
		delete[] data;
		n = other.n;
		data = new int[n]{};
	}
	for (int i = 0; i < n; ++i) data[i] = other.data[i];
}

IntArray::~IntArray() {
	delete[] data;
}

void IntArray::input() {
	std::cout << "Input n: ";
	int old_n = n;
	do {
		std::cin >> n;
		if (n < 1) {
			std::cout << "Array size must be greater than 0\n";
		}
	} while (n < 1);
	if (n != old_n) {
		delete[] data;
		data = new int[n]{};
	}
	std::cout << "Input arr (split by space): ";
	for (int i = 0; i < n; ++i) std::cin >> data[i];
}

void IntArray::output() const {
	std::cout << "Arr(" << n << "): " << *this << "\n";
}

IntArray &IntArray::operator=(const IntArray &other) {
	if (this == &other) return *this;
	if (n != other.n) {
		delete[] data;
		n = other.n;
		data = new int[n]{};
	}
	if (other.data != nullptr) {
		for (int i = 0; i < n; ++i) data[i] = other.data[i];
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const IntArray &arr) {
	int n = arr.n;
	os << "{";
	for (int i = 0; i < n; ++i) {
		os << arr.data[i];
		if (i != n - 1) os << ", ";
	}
	os << "}";
	return os;
}

std::istream &operator>>(std::istream &is, IntArray &arr) {
	int *old = arr.data;
	int n = arr.n;
	arr.data = new int[n + 1];
	for (int i = 0; i < n; ++i) arr[i] = old[i];
	std::cin >> arr.data[n];
	++arr.n;
	delete[] old;
	return is;
}

int &IntArray::operator[](int i) {
	if (i >= n) throw std::invalid_argument("Cannot access array at given position!");
	return data[i];
}

int IntArray::operator[](int i) const {
	if (i >= n) throw std::invalid_argument("Cannot access array at given position!");
	return data[i];
}

IntArray::operator int() const {
	return n;
}
