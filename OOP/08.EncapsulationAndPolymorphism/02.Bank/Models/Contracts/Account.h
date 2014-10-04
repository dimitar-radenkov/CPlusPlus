#pragma once
#include <memory>
#include "Models/Contracts/Customer.h"
#include "Models/Contracts/IDepositable.h"
#include "Models/Contracts/IWithdrawable.h"
#include "Models/Accounts/AccountType.h"

//abstract class
class Account : public IDepositable,
				public IWithdrawable
{
protected:
	AccountType type;
	std::shared_ptr<Customer> customer;
	double balance;
	double interestRate;

	Account(const AccountType& type,
		std::shared_ptr<Customer> customer,
		const double balance,
		const double interestRate)
	{
		this->type = type;
		this->customer = customer;
		this->balance = balance;
		this->interestRate = interestRate;
	}

	double calculateRate(const double months) const
	{
		return Account::balance * (1 + (this->interestRate * months));
	}

public:
	virtual ~Account()
	{}

	virtual void deposit(const double money) = 0;

	virtual void withdraw(const double money) = 0;

	virtual double calculateInterestRate(const int months) const = 0;
};