#include "LoanAccount.h"


LoanAccount::LoanAccount(
	std::shared_ptr<Customer> customer,
	const double balance,
	const double interestRate)
	:Account(AccountType::Loan, customer, balance, interestRate)
{
}


LoanAccount::~LoanAccount()
{
}


void LoanAccount::deposit(const double money)
{
	Account::balance += money;
}


void LoanAccount::withdraw(double money)
{
}


double LoanAccount::calculateInterestRate(const int months) const
{
	int monthsForIndividuals = 3;
	int monthsForCompanies = 2;

	if (this->type == CustomerType::Individuals)
	{
		if (months - monthsForIndividuals <= 0)
		{
			int m = months - monthsForIndividuals;
			double interest = Account::calculateRate(m);
			return interest;
		}

		return 0;
	}
	else
	{
		if (months - monthsForCompanies <= 0)
		{
			int m = months - monthsForCompanies;
			double interest = Account::calculateRate(m);
			return interest;
		}

		return 0;
	}
}
