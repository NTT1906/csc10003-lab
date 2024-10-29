#include <cstring>
#include "student.h"

Student::Student() : id(0), fullname(nullptr), address(nullptr), gpa(0) {
	std::cout << "Student::Default constructor called\n";
}

Student::Student(int _id, const char *_fullname) : id(_id), fullname(new char[strlen(_fullname)]),  address(nullptr), gpa(0) {
	std::cout << "Student::ID & Fullname constructor called\n";
	strcpy(this->fullname, _fullname);
}

Student::Student(int _id, const char *_fullname, const char *_address) : id(_id), fullname(new char[strlen(_fullname)]), address(new char[strlen(_address)]), gpa(0) {
	std::cout << "Student::ID & Fullname & Address constructor called\n";
	strcpy(this->fullname, _fullname);
	strcpy(this->address, _address);
}

Student::Student(int _id, const char *_fullname, const char *_address, double _gpa) : id(_id), fullname(new char[strlen(_fullname)]), address(new char[strlen(_address)]), gpa(_gpa) {
	std::cout << "Student::ID & Fullname & Address & GPA constructor called\n";
	strcpy(this->fullname, _fullname);
	strcpy(this->address, _address);
}

Student::Student(const Student &other) : id(other.id), gpa(other.gpa), fullname(nullptr), address(nullptr) {
	std::cout << "Student::Copy constructor called\n";
	std::string tmp = other.getFullName();
	if (!tmp.empty()) {
		this->fullname = new char[tmp.size() + 1];
		strcpy(this->fullname, tmp.c_str());
	}
	tmp = other.getAddress();
	if (!tmp.empty()) {
		this->address = new char[tmp.size() + 1];
		strcpy(this->address, tmp.c_str());
	}
}

Student::Student(Student &&other) noexcept : id(other.id), gpa(other.gpa), fullname(other.fullname), address(other.address) {
	std::cout << "Student::Move constructor called\n";
	other.id = 0;
	other.gpa = 0.0;
	other.fullname = nullptr;
	other.address = nullptr;
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

Student::Student(const std::string &s) : id(0), gpa(0.0), fullname(nullptr), address(nullptr) {
	std::cout << "Student::String constructor called\n";
	std::istringstream ss(s);
	std::string tmp;
	if (std::getline(ss, tmp, ',')) {
		if (tmp.empty() || tmp[0] == '-' || !isValidNumber(tmp)) {
			std::cout << "Student's ID is not valid (\"" << tmp << "\")\n";
		} else {
			this->id = std::stoi(tmp);
		}
	} else {
		std::cout << "Cannot find Student's ID in the inputted string\n";
		return;
	}
	if (std::getline(ss, tmp, ',')) {
		if (tmp.empty()) {
			std::cout << "Student's fullname is empty\n";
		} else {
			this->fullname = new char[tmp.size() + 1];
			strcpy(this->fullname, tmp.c_str());
		}
	} else {
		std::cout << "Cannot find Student's fullname in the inputted string\n";
		return;
	}
	if (std::getline(ss, tmp, ',')) {
		if (tmp.empty()) {
			std::cout << "Student's address is empty\n";
		} else {
			this->address = new char[tmp.size() + 1];
			strcpy(this->address, tmp.c_str());
		}
	} else {
		std::cout << "Cannot find Student's address in the inputted string\n";
		return;
	}
	if (std::getline(ss, tmp)) {
		if (tmp.empty()) {
			std::cout << "Student's GPA is not valid (\"" << tmp << "\")\n";
		} else {
			this->gpa = std::stod(tmp); // TODO: Error handling...
		}
	} else {
		std::cout << "Cannot find Student's GPA in the inputted string\n";
		return;
	}
}

Student::~Student() {
	delete[] this->fullname;
	delete[] this->address;
}

std::string Student::toString() const {
	std::ostringstream ss;
	ss << this->id  << ',';
	ss << (this->fullname == nullptr ? "" : this->fullname) << ',';
	ss << (this->address == nullptr ? "" : this->address) << ',';
	ss << this->gpa;
	return ss.str();
}

Student Student::clone() {
	return Student{*this};
}

int Student::getID() const { return this->id; }
double Student::getGPA() const { return this->gpa; }

std::string Student::getFullName() const {
	std::string r = this->fullname;
	return r;
}

std::string Student::getAddress() const {
	std::string r = this->address;
	return r;
}



