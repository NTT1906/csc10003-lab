#ifndef INC_23127255_W05_BANK_ACCOUNT_H
#define INC_23127255_W05_BANK_ACCOUNT_H

#include <iostream>

class BankAccount{
protected:
	std::string number;
	std::string owner;
	std::string socialId;
	double balance;
public:
	BankAccount();
	BankAccount(const std::string &number, const std::string &owner, const std::string &socialId, double balance);
	double getBalance() const;
	std::string getNumber() const;
	std::string getOwner() const;
	std::string getSocialId() const;
	BankAccount &setNumber(const std::string &number);
	BankAccount &setOwner(const std::string &owner);
	BankAccount &setSocialId(const std::string &socialId);
	BankAccount &setBalance(double balance);
	virtual BankAccount &input();
	virtual BankAccount &output();
	virtual BankAccount &deposit(double amount);
	virtual double withdraw(double amount);
};

#endif //INC_23127255_W05_BANK_ACCOUNT_H
