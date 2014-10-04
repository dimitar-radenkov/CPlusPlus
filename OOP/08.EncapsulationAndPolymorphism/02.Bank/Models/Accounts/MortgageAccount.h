#pragma once
#include "Models/Contracts/Account.h"

class MortgageAccount : public Account
{
public:
	MortgageAccount(
		std::shared_ptr<Customer> customer,
		const double balance,
		const double interestRate);

	~MortgageAccount();

	virtual void deposit(const double money) override;

	virtual void withdraw(const double money) override;

	virtual double calculateInterestRate(const int months) const override;
};

