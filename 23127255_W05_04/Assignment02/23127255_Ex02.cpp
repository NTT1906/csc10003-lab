#include <iostream>
using namespace std;

#include "bank_account.h"
#include "saving_bank_account.h"
#include <vector>
int main() {
	BankAccount bank;
	SavingBankAccount sbank;
	cout << "[INPUT BANK ACCOUNT]\n";
	bank.input();
	cout << "[INPUTTED BANK ACCOUNT]\n";
	cout << fixed;
	bank.output();
	cout << "[INPUT SAVING BANK ACCOUNT]\n";
	sbank.input();
	cout << "[INPUTTED SAVING BANK ACCOUNT]\n";
	sbank.output();
	cout << "Add saved months to saving bank: \n";
	sbank.addSavedMonths(10);
	return 0;
}