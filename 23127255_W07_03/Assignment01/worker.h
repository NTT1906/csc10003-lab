#ifndef WORKER_H
#define WORKER_H

#include "employee.h"

class Worker : public Employee{
	int itemsProduced;
	double ratePerItem;
public:
	Worker();
	Worker(const std::string &id, const std::string &fullName, const std::string &hireDate, const std::string &address, int itemsProduced, double ratePerItem);
	Worker(const Worker &other);
	Worker(const std::string &s);
	Worker(Worker &&other) noexcept;

	int getType() override;

	void input();
	void output() const;

	friend std::ostream &operator<<(std::ostream &os, const Worker &employee);

	double computeSalary() override;
};

#endif //WORKER_H
