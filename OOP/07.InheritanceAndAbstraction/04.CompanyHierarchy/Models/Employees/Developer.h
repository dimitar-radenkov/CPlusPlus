#pragma once
#include <vector>

#include "Models/Department.h"
#include "Models/Project.h"
#include "Models/Contracts/IEmployee.h"

class Developer : public IEmployee
{
private:
	std::vector<Project> projects;

public:
	Developer(const int id,
		const std::string& firstName,
		const std::string& lastName,
		const double salary,
		const std::vector<Project>& projects);

	virtual ~Developer();

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

	std::vector<Project> getProjects() const
	{
		return this->projects;
	}
};

