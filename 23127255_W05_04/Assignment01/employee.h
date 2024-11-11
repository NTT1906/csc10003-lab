#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <sstream>

class Employee {
protected:
	std::string id;
	std::string fullName;
	std::string hireDate;
	std::string address;
	~Employee() = default;
public:
	Employee();
	Employee(const std::string &id, const std::string &fullName, const std::string &hireDate, const std::string &address);
	Employee(const Employee &other);
	Employee(const std::string &s);
	Employee(Employee &&other) noexcept;

	void input();
	void output() const;

	virtual double computeSalary() = 0;

	friend std::ostream &operator<<(std::ostream &os, const Employee &employee);
};

#endif //EMPLOYEE_H
