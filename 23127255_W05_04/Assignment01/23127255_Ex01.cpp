#include <iostream>

#include "office_employee.h"
#include "worker.h"

using namespace std;

int main() {
	OfficeEmployee officeEmp;
	cout.precision(3);
	cout << fixed;
	cout << "[INPUT OFFICE EMPLOYEE]\n";
	officeEmp.input();
	cout << "[OUTPUT OFFICE EMPLOYEE]\n";
	officeEmp.output();
	cout << "Office Employee Monthly Salary: " << officeEmp.computeSalary() << " VND" << "\n\n";

	Worker worker;
	cout << "[INPUT WORKER]\n";
	worker.input();
	cout << "[OUTPUT WORKER]\n";
	worker.output();
	cout << "Worker Monthly Salary: " << worker.computeSalary() << " VND" << "\n";
	return 0;
}