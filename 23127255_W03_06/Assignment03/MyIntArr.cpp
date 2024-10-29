#include "MyIntArr.h"

MyIntArr::MyIntArr() : a(nullptr), n(0) {
	std::cout << "MyIntArr::Default constructor called\n";
}
MyIntArr::MyIntArr(int _n) : a(new int[_n]{0}), n(_n) {
	std::cout << "MyIntArr::Sized constructor called\n";
}

MyIntArr::MyIntArr(const int *_a, int _n) : a(new int[_n]{0}), n(_n) {
	std::cout << "MyIntArr::Copy array constructor called\n";
	for (int i = 0; i < n; ++i) this->a[i] = _a[i];
}

MyIntArr::MyIntArr(const MyIntArr &other) : a(new int[other.getSize()]), n(other.getSize()){
	std::cout << "MyIntArr::Copy constructor called\n";
	for (int i = 0; i < this->n; ++i) this->a[i] = other.getValue(i);
}

MyIntArr::MyIntArr(MyIntArr &&other) noexcept : a(other.a), n(other.n) {
	std::cout << "MyIntArr::Move constructor called\n";
	other.a = nullptr;
	other.n = 0;
}

bool isValidNumber(const std::string &s) {
	if (s.empty()) {
		return false;
	}
	size_t i = 0;
	if (s[0] == '-' || s[0] == '+') {
		i = 1;
	}
	while (s[i]) {
		if (s[i] < '0' || s[i] > '9')
			return false;
		i++;
	}

	return true;
}

MyIntArr::MyIntArr(const std::string &s) {
	std::cout << "MyIntArr::String constructor called\n";
	std::string tmp;

	int cC = 0;
	if (!s.empty()) {
		cC = 1;
	}

	for (char c : s) {
		if (c == ',') {
			cC++;
		}
	}

	this->a = new int[cC]{0};
	std::istringstream ss(s);

	int i = 0;

	this->n = cC;

	while (std::getline(ss, tmp, ',')) {
		int value{0};
		if (isValidNumber(tmp))
			value = std::stoi(tmp);
		this->a[i++] = value;
	}
}

std::string MyIntArr::toString() const {
	if (n == 0) return "";
	std::ostringstream ss;
	ss << a[0];
	for (int i = 1; i < n; ++i) {
		ss << "," << a[i];
	}
	return ss.str();

//	if (n == 0) return "";
//	string s = itoa(12);
//	std::string result(itoa(a[0]));
//	std::string result = std::to_string(a[0]);
//	for (int i = 1; i < n; ++i) {
//		result += "," + std::to_string(a[i]);
//	}
//	return result;
}

int MyIntArr::getSize() const { return this->n; }

int MyIntArr::getValue(int idx) const {
	if (idx < 0 || idx > this->n) {
		std::cout << "Index is out of the array size (" << idx << ":" << this->n << ")\n";
		return -1;
	}
	return this->a[idx];
}

MyIntArr::~MyIntArr() {
	std::cout << "MyIntArr::Deconstructor called\n";
	delete[] this->a;
}

MyIntArr MyIntArr::clone() {
	return MyIntArr{*this};
}
