#include <iostream>
#include <vector>

#include "company.h"
#include "office_employee.h"
#include "worker.h"

using namespace std;

int main() {
	Company abc;
//	vector<Employee *> list;
//	int i = 0;
//	string j = "A";
//	list.push_back(new OfficeEmployee("1", "User 1", "11/11/24", "Home 1", 12, 12));
//	list.push_back(new OfficeEmployee("2", "User 2", "13/01/24", "Home 2", 22, 12));
//	list.push_back(new Worker("3", "User 3", "13/12/24", "Home 3", 22, 12));
//	list.push_back(new Worker("4", "User 4", "13/12/22", "Home 4", 222, 2));
//	list.push_back(new OfficeEmployee("5", "User 5", "13/01/23", "Beach 1", 10, 24));
//	abc.addEmployees(list);
//	abc.printEmployeeInfo();
	int choice;
	do {
		cout << "--- EMPLOYEE MANAGER ---\n";
		cout << "1) Add employee to database.\n"
				"2) Load data from file path.\n"
				"3) Save data to file path.\n"
				"4) Print information of all employees.\n"
				"5) Print total salary of all employees.\n"
				"6) Print information of all employees with highest salary. \n"
				"0) Exit\n";
		cin >> choice;
		switch (choice) {
			case 0: {
				choice = -1;
				cout << "Exiting...\n";
				break;
			}
			case 1: {
				cout << "[ADD EMPLOYEE]\n";
				cout << "Type of employee: \n"
						" + office: 0\n"
						" + worker: 1\n";
				int eType;
				do {
					cout << "Enter employee type: ";
					cin >> eType;
					if (eType != 0 && eType != 1) {
						cout << "Invalid employee type! Please retype...\n";
					}
				} while (eType != 0 && eType != 1);
				if (eType == 0) {
					OfficeEmployee office;
					office.input();
					if (abc.addEmployee(office)) {
						cout << "Added office employee with the following information\n";
						office.output();
					} else {
						cout << "Employee with the same ID already existed!\n";
					}
				} else {
					Worker worker;
					worker.input();
					if (abc.addEmployee(worker)) {
						cout << "Added worker with the following information's\n";
						worker.output();
					} else {
						cout << "Employee with the same ID already existed!\n";
					}
				}
				break;
			}
			case 2: {
				cin.ignore();
				cout << "Enter file path: ";
				std::string filePath;
				getline(cin, filePath);
				abc.loadFromFile(filePath);
				break;
			}
			case 3: {
				cin.ignore();
				cout << "Enter file path: ";
				std::string filePath;
				getline(cin, filePath);
				abc.saveToFile(filePath);
				break;
			}
			case 4: {
				cout << "[PRINT INFORMATION OF ALL EMPLOYEES]\n";
				abc.printEmployeeInfo();
				break;
			}
			case 5: {
				cout << "[PRINT TOTAL SALARY OF ALL EMPLOYEES]\n";
				abc.printTotalSalary();
				break;
			}
			case 6: {
				cout << "[PRINT INFORMATION OF ALL EMPLOYEES WITH HIGHEST SALARY]\n";
				abc.printBiggestSalaryEmployees();
				break;
			}
			default: {
				cout << "Invalid choice! Please choose other choices.\n";
			}
		}
	} while (choice != -1);
	return 0;
}