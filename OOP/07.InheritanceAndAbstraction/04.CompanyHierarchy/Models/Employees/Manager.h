#pragma once
#include "Models/Contracts/IManager.h"

class Manager : public IManager
{
public:
	Manager(const int id,
		const std::string& firstName,
		const std::string& lastName,
		const double salary,
		const Department department,
		const std::vector<std::shared_ptr<IEmployee>> employees);

	virtual ~Manager();

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

	std::string Manager::toString() const override;

	double getSalary() const override
	{
		return IEmployee::salary;
	}

	Department getDepartment() const override
	{
		return IEmployee::department;
	}

	std::vector<std::shared_ptr<IEmployee>> getEmployees() const override
	{
		return IManager::employees;
	}
};

