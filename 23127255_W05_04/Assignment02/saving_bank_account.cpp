#include "saving_bank_account.h"

SavingBankAccount &SavingBankAccount::input() {
	BankAccount::input();
	std::cout << "Input annual interest rate: ";
	std::cin >> annualInterestRate;
	std::cout << "Input period              : ";
	std::cin >> period;
	std::cout << "Input saved months        : ";
	std::cin >> savedMonths;
	return *this;
}

SavingBankAccount &SavingBankAccount::output() {
	BankAccount::output();
	std::cout << "Annual interest rate: " << annualInterestRate << '\n';
	std::cout << "Period              : " << period << '\n';
	std::cout << "Saved months        : " << savedMonths << '\n';
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
	// P = A * (1 + r_p) ** (m / p) * (1 + r_f)
	// r_p is period rate, r_f is free-period rate
	// A * (1 + r_p) ** (m/p) is the moneys after m/p circles
	// The above result time (1 + r_f) is the final saving
//	double r = BankAccount::withdraw(balance);
//	unsigned cycle = savedMonths / period;
//	double periodRate = 1 + (annualInterestRate * 12 / period);
//	double leftOverRate = 1 + (0.02 * 12 / (savedMonths % period)); // (100% + 2% / 12 * leftOverMonths)^1
//	savedMonths = 0;
//	return r * pow(periodRate, cycle) * leftOverRate;
	SavingBankAccount::recalculateInterest();
	double r = BankAccount::withdraw(balance);
	double leftOverRate = 1 + (0.02 * 12 / (savedMonths % period)); // (100% + 2% / 12 * leftOverMonths)^1
	savedMonths = 0;
	return r * leftOverRate;
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

SavingBankAccount &SavingBankAccount::recalculateInterest() {
	if (savedMonths < period) {
		return *this;
	}
	double periodRate = 1 + (annualInterestRate * 12 / period);
	unsigned cycle = savedMonths / period;
	savedMonths %= period;
	balance *= pow(periodRate, cycle);
	return *this;
}

SavingBankAccount &SavingBankAccount::addSavedMonths(unsigned int _savedMonths) {
	savedMonths += _savedMonths;
	SavingBankAccount::recalculateInterest();
	return *this;
}

double SavingBankAccount::getAnnualInterestRate() const { return annualInterestRate; }
unsigned int SavingBankAccount::getPeriod() const { return period; }
unsigned int SavingBankAccount::getSavedMonths() const { return savedMonths; }

SavingBankAccount &SavingBankAccount::setSavedMonths(unsigned int _savedMonths) {
	savedMonths = _savedMonths;
	return *this;
}

SavingBankAccount &SavingBankAccount::setPeriod(unsigned int _period) {
	recalculateInterest();
	period = _period;
	return *this;
}

SavingBankAccount &SavingBankAccount::setAnnualInterestRate(double _interestRate) {
	recalculateInterest();
	annualInterestRate = _interestRate;
	return *this;
}
