#include "bank_account.h"

BankAccount &BankAccount::input() {
	std::cout << "Input number      : ";
	std::getline(std::cin, number);
	std::cout << "Input owner's name: ";
	std::getline(std::cin, owner);
	std::cout << "Input social ID   : ";
	std::getline(std::cin, socialId);
	std::cout << "Input balance     : ";
	std::cin >> balance;
	std::cin.ignore();
	return *this;
}

BankAccount &BankAccount::output() {
	std::cout << "Number      : " << number << '\n';
	std::cout << "Owner's name: " << owner << '\n';
	std::cout << "Social ID   : " << socialId << '\n';
	std::cout << "Balance     : " << balance << '\n';
	return *this;
}

BankAccount &BankAccount::deposit(double amount) {
	balance += amount;
	return *this;
}

double BankAccount::withdraw(double amount) {
	if (amount - balance >= 50000.0) {
		balance -= amount;
		return amount;
	}
	return 0.0;
//	else if (balance < 50000.0) {
//		return 0.0;
//	}
//	balance = 50000.0f;
//	return amount - balance;
}

BankAccount::BankAccount(const std::string &_number, const std::string &_owner, const std::string &_socialId, double _balance) : number(_number), owner(_owner), socialId(_socialId), balance{_balance} {}
BankAccount::BankAccount() : balance{} {}

double BankAccount::getBalance() const { return balance; }
std::string BankAccount::getNumber() const { return number; }
std::string BankAccount::getOwner() const { return owner; }
std::string BankAccount::getSocialId() const { return socialId; }

BankAccount &BankAccount::setNumber(const std::string &_number) {
	number = _number;
	return *this;
}

BankAccount &BankAccount::setOwner(const std::string &_owner) {
	owner = _owner;
	return *this;
}

BankAccount &BankAccount::setSocialId(const std::string &_socialId) {
	socialId = _socialId;
	return *this;
}

BankAccount &BankAccount::setBalance(double _balance) {
	balance = _balance;
	return *this;
}
