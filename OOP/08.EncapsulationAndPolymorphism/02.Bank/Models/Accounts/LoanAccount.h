#pragma once
#include "Models/Contracts/Account.h"

class LoanAccount : public Account
{
public:
	LoanAccount(
		std::shared_ptr<Customer> customer,
		const double balance,
		const double interestRate);

	virtual ~LoanAccount();

	virtual void deposit(const double money) override;

	virtual void withdraw(const double money) override;

	virtual double calculateInterestRate(const int months) const override;
};

