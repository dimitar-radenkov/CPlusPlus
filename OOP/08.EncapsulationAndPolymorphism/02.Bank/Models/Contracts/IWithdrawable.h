#pragma once
class IWithdrawable
{
public:
	IWithdrawable()
	{}

	virtual ~IWithdrawable()
	{}

	virtual void withdraw(const double money) = 0;
};