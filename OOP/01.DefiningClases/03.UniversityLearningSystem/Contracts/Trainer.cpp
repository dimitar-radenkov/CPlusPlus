#include "Trainer.h"


Trainer::Trainer(const std::string& firstName,
				 const std::string& lastName,
				 const int age,
				 TrainerType type) 
	: Person(firstName, lastName, age)
{
	this->type = type;
}


Trainer::~Trainer()
{
}
