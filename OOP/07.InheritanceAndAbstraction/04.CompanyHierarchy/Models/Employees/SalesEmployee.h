#pragma once
#include <vector>

#include "Models/Department.h"
#include "Models/SaleEntity.h"
#include "Models/Contracts/IEmployee.h"

class SalesEmployee : public IEmployee
{
private:
	std::vector<SaleEntity> sales;

public:
	SalesEmployee(const int id,
		const std::string& firstName,
		const std::string& lastName,
		const double salary,
		const std::vector<SaleEntity>& sales);

	virtual ~SalesEmployee();

	int getId() const override
	{
		return IPerson::id;
	}

	std::string getFirstName() const override
	{
		return IPerson::firstName;
	}

	std::string getLastName() const override
	{
		return IPerson::lastName;
	}

	std::string toString() const override;

	double getSalary() const override
	{
		return IEmployee::salary;
	}

	Department getDepartment() const override
	{
		return IEmployee::department;
	}

	std::vector<SaleEntity> getSales() const
	{
		return this->sales;
	}
};

