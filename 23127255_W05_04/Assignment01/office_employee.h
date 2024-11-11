#ifndef OFFICE_EMPLOYEE_H
#define OFFICE_EMPLOYEE_H

#include "employee.h"

class OfficeEmployee : public Employee {
	int workingDays;
	double payPerDay;
public:
	OfficeEmployee();
	OfficeEmployee(const std::string &id, const std::string &fullName, const std::string &hireDate, const std::string &address, int workingDays, double payPerDay);
	OfficeEmployee(const OfficeEmployee &other);
	OfficeEmployee(const std::string &s);
	OfficeEmployee(OfficeEmployee &&other) noexcept;

	void input();
	void output() const;

	friend std::ostream &operator<<(std::ostream &os, const OfficeEmployee &employee);
	double computeSalary() override;
};

#endif //OFFICE_EMPLOYEE_H
