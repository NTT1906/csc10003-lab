#include <iostream>
#include <vector>

#include "company.h"
#include "office_employee.h"
#include "worker.h"

using namespace std;

int main() {
	Company abc;
	vector<Employee *> list;
	int i = 0;
	string j = "A";
	list.push_back(new OfficeEmployee(to_string(i++) + "\n" + j));
	j[0]++;
	list.push_back(new Worker(to_string(i++) + "\n" + j));
	j[0]++;
	list.push_back(new Worker(to_string(i++) + "\n" + j));
	j[0]++;
	list.push_back(new Worker(to_string(i++) + "\n" + j));
	j[0]++;
	list.push_back(new Worker(to_string(i++) + "\n" + j));
	abc.addEmployees(list);
	abc.printEmployeeInfo();
	return 0;
}