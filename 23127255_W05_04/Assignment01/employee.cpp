#include "employee.h"

Employee::Employee() : id(), fullName(), hireDate(), address() {}
Employee::Employee(const std::string &_id, const std::string &_fullName, const std::string &_hireDate, const std::string &_address) : id(_id), fullName(_fullName), hireDate(_hireDate), address(_address) {}
Employee::Employee(const Employee &other) : id(other.id), fullName(other.fullName), hireDate(other.hireDate), address(other.address) {}
Employee::Employee(Employee &&other) noexcept {
	id = std::move(other.id);
	fullName = std::move(other.fullName);
	hireDate = std::move(other.hireDate);
	address = std::move(other.address);
}

void Employee::input() {
	std::cout << "Input employee's ID: "; std::getline(std::cin, id);
	std::cout << "Input employee's full name: "; std::getline(std::cin, fullName);
	std::cout << "Input employee's hire date: "; std::getline(std::cin, hireDate);
	std::cout << "Input employee's address: "; std::getline(std::cin, address);
}

void Employee::output() const {
	std::cout << "Employee's ID: " << id << '\n';
	std::cout << "Employee's full name: " << fullName << '\n';
	std::cout << "Employee's hire date: " << hireDate << '\n';
	std::cout << "Employee's address: " << address << '\n';
}

Employee::Employee(const std::string &s) {
	std::istringstream ss(s);
	std::getline(ss, id);
	std::getline(ss, fullName);
	std::getline(ss, hireDate);
	std::getline(ss, address);
}

std::ostream &operator<<(std::ostream &os, const Employee &employee) {
	os << employee.id << '\n' << employee.fullName << '\n' << employee.hireDate << '\n' << employee.address << '\n';
	return os;
}
