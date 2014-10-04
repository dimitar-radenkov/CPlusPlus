#include "DepositAccount.h"


DepositAccount::DepositAccount(
	std::shared_ptr<Customer> customer,
	const double balance,
	const double interestRate):
	Account(AccountType::Deposit, customer, balance, interestRate)
{}


DepositAccount::~DepositAccount()
{}


void DepositAccount::deposit(double money)
{
	Account::balance += money;
}


void DepositAccount::withdraw(double money)
{
	if (Account::balance - money < 0)
	{
		throw std::exception("No enougth money to withdraw");
	}

	Account::balance -= money;
}


double DepositAccount::calculateInterestRate(const int months) const
{
	double balanceLimit = 1000;
	if (Account::balance < balanceLimit)
	{
		return 0;
	}

	double rate = Account::calculateRate(months);

	return rate;
}
