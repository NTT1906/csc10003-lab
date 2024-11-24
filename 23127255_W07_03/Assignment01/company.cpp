#include "company.h"

bool Company::addEmployee(const OfficeEmployee &employee) {
	Employee *e = new OfficeEmployee(employee);
	if (!addEmployee(e)) {
		delete e;
		return false;
	}
	return true;
}
bool Company::addEmployee(const Worker &employee) {
	Employee *e = new Worker(employee);
	if (!addEmployee(e)) {
		delete e;
		return false;
	}
	return true;
}

bool Company::addEmployee(Employee *employee) {
	for (auto &e : employees) {
		if (e->getId() == employee->getId()) {
			return false;
		}
	}
	employees.push_back(employee);
	return true;
}

Company::~Company() {
	for (auto &employee : employees) {
		delete employee;
	}
}

void Company::printEmployeeInfo() const {
//	std::cout << "Employee Info\n";
//	printf("%-4s | %-30s | %-10s | %-30s | %-20s | %-10s\n", "Idx", "Product Name", "Size", "Shop", "Price", "Amount");
//	for (auto &employee : employees) {
//		printf("%-4d | %-30s | %-10s | %-30s | %-20.2f | %-10d\n", i, product.getName().c_str(), product.getSize().c_str(), product.getShop().c_str(), product.getPrice(), slot.getQuantity());
//	}
	for (auto &employee : employees) {
		employee->output();
		std::cout << "\n--------------\n";
	}
}

void Company::printTotalSalary() const {
	double totalSalary = 0.0;
	for (auto &employee : employees) {
		totalSalary += employee->computeSalary();
	}
	std::cout << "TOTAL SALARY: " << totalSalary << "\n";
}

#include <algorithm>
void Company::printBiggestSalaryEmployees() const {
	std::vector<Employee *> cp = employees;
	std::sort(cp.begin(), cp.end(), [](Employee *a, Employee *b) {
		return a->computeSalary() > b->computeSalary();
	});
	unsigned int size = (int) cp.size() - 1;
	for (unsigned int i = 0; i < size; ++i) {
		employees[i]->output();
		if (employees[i]->computeSalary() != employees[i + 1]->computeSalary()) {
			break;
		}
	}
}

Company &Company::addEmployees(const std::vector<Employee *> &_employees) {
	for (auto &e : _employees) {
		if (!addEmployee(e)) {
			delete e;
		}
	}
	return *this;
}
