#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <vector>
#include "employee.h"
#include "office_employee.h"
#include "worker.h"

class Company{
	std::vector<Employee *> employees;
public:
	Company() = default;
	~Company();
	Company(const Company &other) = default;
	Company &addEmployees(const std::vector<Employee *> &employee);
	bool addEmployee(Employee *employee);
	bool addEmployee(const OfficeEmployee &employee);
	bool addEmployee(const Worker &employee);
	void printEmployeeInfo() const;
	void printTotalSalary() const;
	void printBiggestSalaryEmployees() const;
};

#endif //COMPANY_H