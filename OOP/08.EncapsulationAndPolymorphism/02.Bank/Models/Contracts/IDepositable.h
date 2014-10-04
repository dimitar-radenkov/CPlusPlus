#pragma once
class IDepositable
{
public:
	IDepositable()
	{}

	virtual ~IDepositable()
	{}

	virtual void deposit(const double money) = 0;
};