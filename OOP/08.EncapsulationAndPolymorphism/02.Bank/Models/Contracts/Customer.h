#pragma once
#include <string>
#include "Models/Customers/CustomerType.h"

//abstract class
class Customer
{
protected:
	CustomerType type;
	std::string name;

	Customer(const CustomerType& type, 
		const std::string& name)
	{
		this->type = type;
		this->name = name;
	}

public:
	virtual ~Customer()
	{}
};

