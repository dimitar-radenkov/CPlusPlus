#include "MortgageAccount.h"


MortgageAccount::MortgageAccount(
	std::shared_ptr<Customer> customer,
	const double balance,
	const double interestRate)
	:Account(AccountType::Mortgage, customer, balance, interestRate)
{}


MortgageAccount::~MortgageAccount()
{}


void MortgageAccount::deposit(double money)
{
	Account::balance += money;
}


void MortgageAccount::withdraw(double money)
{
}


double MortgageAccount::calculateInterestRate(const int months) const
{
	if (this->type == CustomerType::Individuals)
	{
		int monthsWithoutRate = 6;
		if (months <= monthsWithoutRate)
		{
			return 0;
		}

		int monthsToCalculate = months - monthsWithoutRate;
		double rate = this->calculateRate(monthsToCalculate);

		return rate;
	}
	else
	{
		int monthsForHalfRate = 12;
		if (months <= monthsForHalfRate)
		{
			double m = monthsForHalfRate / 2;
			double rate = Account::calculateRate(m);
			return rate;
		}
		else
		{
			double m = (months - monthsForHalfRate) + (monthsForHalfRate / 2);
			double rate = Account::calculateRate(m);
			return rate;
		}
	}
}