#pragma once
#include <sstream>
#include <algorithm>

#include "Models/Department.h"
#include "Models/Contracts/IPerson.h"

class IEmployee : public IPerson
{
protected:
	double salary;
	Department department;

	IEmployee(const int id,
		const std::string& firstName,
		const std::string& lastName,
		const double salary,
		const Department department)
		:IPerson(id, firstName, lastName)
	{
		this->salary = salary;
		this->department = department;
	}

public:
	virtual ~IEmployee()
	{
	}

	virtual double getSalary() const = 0;

	virtual Department getDepartment() const = 0;
};

