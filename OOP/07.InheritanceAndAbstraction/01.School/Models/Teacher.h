#pragma once
#include <vector>
#include "Models/Human.h"
#include "Models/Discipline.h"

class Teacher : public Human
{
private:
	std::string uniqueIdentifier;
	std::vector<Discipline> disciplines;

public:
	Teacher(const std::string& name,
			const std::string& uniqueIdentifier,
			const std::vector<Discipline>& disciplines);

	virtual ~Teacher();

	std::string getUniqueIdentifier() const
	{
		return this->uniqueIdentifier;
	}

	std::vector<Discipline> getDisciplines() const
	{
		return this->disciplines;
	}
};

