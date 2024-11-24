#include "worker.h"

Worker::Worker() : Employee(), itemsProduced(0), ratePerItem(0) {}
Worker::Worker(const std::string &id, const std::string &fullName, const std::string &hireDate, const std::string &address, int itemsProduced, double ratePerItem) : Employee(id, fullName, hireDate, address), itemsProduced(itemsProduced), ratePerItem(ratePerItem) {}
Worker::Worker(const Worker &other) : Employee(other), itemsProduced(other.itemsProduced), ratePerItem(other.ratePerItem) {}

Worker::Worker(const std::string &s) : itemsProduced(0), ratePerItem(0) {
	std::istringstream ss(s);
	std::getline(ss, id);
	std::getline(ss, fullName);
	std::getline(ss, hireDate);
	std::getline(ss, address);

	ss >> itemsProduced;
	ss >> ratePerItem;
}

Worker::Worker(Worker &&other) noexcept : Employee(std::move(other)), itemsProduced(other.itemsProduced), ratePerItem(other.ratePerItem) {
	other.itemsProduced = 0;
	other.ratePerItem = 0;
}

void Worker::input() {
	Employee::input();
	std::cout << "Input work's items produced: "; std::cin >> itemsProduced;
	std::cout << "Input rates per item: "; std::cin >> ratePerItem;
	std::cin.ignore();
}

void Worker::output() const {
	Employee::output();
	std::cout << "\nWorker's item produced: " << itemsProduced << "\nWorker's rate per item: " << ratePerItem << '\n';
}

std::ostream &operator<<(std::ostream &os, const Worker &employee) {
	os << employee.id << '\n' << employee.fullName << '\n' << employee.hireDate << '\n' << employee.address << '\n' << employee.itemsProduced << " " << employee.ratePerItem;
	return os;
}

double Worker::computeSalary() {
	return itemsProduced * ratePerItem;
}

int Worker::getType() { return EmployeeType::TYPE_WORKER; }
