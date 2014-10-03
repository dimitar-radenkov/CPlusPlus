#pragma once
#include <string>
#include <cstdint>

#include "Models/ProjectState.h"

class Project
{
private:
	std::string name;
	uint32_t startDate;
	std::string details;
	ProjectState state;

public:

	Project(const std::string& name,
		const uint32_t startDate,
		const std::string& details,
		const ProjectState state = ProjectState::Open)
	{
		this->name = name;
		this->startDate = startDate;
		this->details = details;
		this->state = state;
	}

	virtual ~Project()
	{
	}

	std::string getName() const
	{
		return this->name;
	}

	uint32_t getStartDate() const
	{
		return this->startDate;
	}

	std::string getDetails() const
	{
		return this->details;
	}

	void ChangeState(const ProjectState state)
	{
		this->state = state;
	}
};