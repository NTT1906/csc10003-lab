#include "office_employee.h"

OfficeEmployee::OfficeEmployee() : Employee(), workingDays(0), payPerDay(0) {}
OfficeEmployee::OfficeEmployee(const std::string &id, const std::string &fullName, const std::string &hireDate, const std::string &address, int workingDays, double payPerDay) : Employee(id, fullName, hireDate, address), workingDays(workingDays), payPerDay(payPerDay) {}
OfficeEmployee::OfficeEmployee(const OfficeEmployee &other) : Employee(other), workingDays(other.workingDays), payPerDay(other.payPerDay) {}

OfficeEmployee::OfficeEmployee(const std::string &s) : workingDays(0), payPerDay(0) {
	std::istringstream ss(s);
	std::getline(ss, id, ';');
	std::getline(ss, fullName, ';');
	std::getline(ss, hireDate, ';');
	std::getline(ss, address, ';');

	std::string tmp;
	if (std::getline(ss, tmp, ';') && !tmp.empty()) {
		workingDays = std::stoi(tmp);
	}
	if (std::getline(ss, tmp)) {
		tmp = tmp.substr(0, tmp.find(';'));
		if (!tmp.empty()) {
			payPerDay = std::stoi(tmp);
		}
	}
}

OfficeEmployee::OfficeEmployee(OfficeEmployee &&other) noexcept : Employee(std::move(other)), workingDays(other.workingDays), payPerDay(other.payPerDay) {
	std::cout << workingDays << ":" << payPerDay << "\n";
	other.workingDays = 0;
	other.payPerDay = 0;
}

void OfficeEmployee::input() {
	Employee::input();
	std::cout << "Input office employee's working days: "; std::cin >> workingDays;
	std::cout << "Input office employee's pays per day: "; std::cin >> payPerDay;
	std::cin.ignore();
}

void OfficeEmployee::output() const {
	Employee::output();
	std::cout << "\nOffice employee's working days: " << workingDays << "\nOffice employee's pay per day: " << payPerDay << '\n';
}

std::ostream &operator<<(std::ostream &os, const OfficeEmployee &employee) {
	os << employee.id << ';' << employee.fullName << ';' << employee.hireDate << ';' << employee.address << ';' << employee.workingDays << ';' << employee.payPerDay;
	return os;
}

double OfficeEmployee::computeSalary() {
	return workingDays * payPerDay;
}

int OfficeEmployee::getType() { return EmployeeType::TYPE_OFFICE; }
