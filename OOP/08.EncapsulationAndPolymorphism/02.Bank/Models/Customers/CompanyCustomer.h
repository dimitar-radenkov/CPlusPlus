#pragma once
#include "Models/Contracts/Customer.h"

class CompanyCustomer : public Customer
{
public:
	CompanyCustomer(const std::string& name);

	virtual ~CompanyCustomer();
};

