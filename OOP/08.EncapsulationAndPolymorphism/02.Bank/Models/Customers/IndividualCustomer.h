#pragma once
#include "Models/Contracts/Customer.h"

class IndividualCustomer : public Customer
{
public:
	IndividualCustomer(const std::string& name);

	virtual ~IndividualCustomer();
};

