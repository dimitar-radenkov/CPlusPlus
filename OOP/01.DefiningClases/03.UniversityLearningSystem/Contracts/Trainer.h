#pragma once

#include "Person.h"
#include "TrainerType.h"

//This is an abstract Trainer class
class Trainer : public Person
{
private:
	TrainerType type;

protected:
	Trainer(const std::string& firstName,
			const std::string& lastName,
			const int age, 
			TrainerType type);

	virtual ~Trainer();

	TrainerType getType() const
	{
		return this->type;
	}
};

