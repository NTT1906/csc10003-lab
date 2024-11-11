#include "saving_bank_account.h"

SavingBankAccount &SavingBankAccount::input() {
	return *this;
}

SavingBankAccount &SavingBankAccount::output() {
	return *this;
}

double SavingBankAccount::withdraw(double amount) {
	if (savedMonths < period) {
		std::cout << "You are not allowed to withdraw from this account as the saved months hasn't surpassed the initiated period!\n";
		return 0.0;
	}
	double r = BankAccount::withdraw(amount);
	unsigned cycle = savedMonths / period;
	savedMonths = savedMonths % period;
	double rate = 1 + (annualInterestRate * 12 / period);
	return r * pow(rate, cycle);
}

double SavingBankAccount::withdrawImmediately() {
	double r = BankAccount::withdraw(balance);
	unsigned cycle = savedMonths / period;
	savedMonths = savedMonths % period;
	double rate = 1 + (annualInterestRate * 12 / period);
	return r * pow(rate, cycle);
}

double SavingBankAccount::getAnnualInterestRate() const {
	return annualInterestRate;
}

SavingBankAccount &SavingBankAccount::deposit(double amount) {
	if (savedMonths < period) {
		std::cout << "You are not allowed to deposit to this account as the saved months hasn't surpassed the initiated period!\n";
		return *this;
	}
	BankAccount::deposit(amount);
	return *this;
}

SavingBankAccount::SavingBankAccount() : BankAccount(), annualInterestRate{}, period{}, savedMonths{} {}
SavingBankAccount::SavingBankAccount(const std::string &_number, const std::string &_owner, const std::string &_socialId, double _balance, double _annualInterestRate, unsigned int _period, unsigned int _savedMonths) : BankAccount(_number, _owner, _socialId, _balance), annualInterestRate{_annualInterestRate}, period{_period}, savedMonths{_savedMonths} {}