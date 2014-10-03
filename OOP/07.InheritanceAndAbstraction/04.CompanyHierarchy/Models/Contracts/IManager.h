#pragma once
#include <vector>
#include <memory>

#include "Models/Contracts/IEmployee.h"

class IManager : public IEmployee
{
protected:
	std::vector<std::shared_ptr<IEmployee>> employees;

	IManager(const int id,
		const std::string& firstName,
		const std::string& lastName,
		const double salary,
		const Department department,
		const std::vector<std::shared_ptr<IEmployee>> employees)
		:IEmployee(id, firstName, lastName, salary, department)
	{
		this->employees = employees;
	}

public:
	virtual ~IManager()
	{
	}

	virtual std::vector<std::shared_ptr<IEmployee>> getEmployees() const = 0;
};

