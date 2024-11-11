#ifndef INC_23127255_W05_SAVING_BANK_ACCOUNT_H
#define INC_23127255_W05_SAVING_BANK_ACCOUNT_H

#include <cmath>
#include "bank_account.h"

class SavingBankAccount : BankAccount{
	double annualInterestRate;
	unsigned int period;
	unsigned int savedMonths;
public:
	SavingBankAccount();
	SavingBankAccount(const std::string &number, const std::string &owner, const std::string &socialId, double balance, double annualInterestRate, unsigned int period, unsigned int savedMonths);
	SavingBankAccount &input() override;
	SavingBankAccount &output() override;
	SavingBankAccount &deposit(double amount) override;
	double withdraw(double amount) override;
	double withdrawImmediately();
	double getAnnualInterestRate() const;
};

#endif //INC_23127255_W05_SAVING_BANK_ACCOUNT_H
