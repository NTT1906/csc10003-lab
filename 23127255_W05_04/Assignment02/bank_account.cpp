#include "bank_account.h"

BankAccount &BankAccount::input() {
	return *this;
}

BankAccount &BankAccount::output() {
	return *this;
}

BankAccount &BankAccount::deposit(double amount) {
	balance += amount;
	return *this;
}

double BankAccount::withdraw(double amount) {
	if (amount - balance >= 50.0) {
		balance -= amount;
		return amount;
	} else if (balance < 50.0) {
		return 0.0;
	}
	balance = 50.0f;
	return amount - balance;
}

double BankAccount::currentBalance() const {
	return balance;
}

BankAccount::BankAccount(const std::string &_number, const std::string &_owner, const std::string &_socialId, double _balance) : number(_number), owner(_owner), socialId(_socialId), balance{_balance} {}
BankAccount::BankAccount() : balance{} {}
