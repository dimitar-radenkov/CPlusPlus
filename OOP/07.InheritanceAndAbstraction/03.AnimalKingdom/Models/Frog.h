#pragma once
#include <iostream>

#include "Models/Contracts/Animal.h"
#include "Models/Contracts/ISound.h"

class Frog : public Animal, ISound
{
public:
	Frog(const std::string& name,
		 const int age,
		 const bool isMale);

	virtual ~Frog();

	void ProduceSound() const override;
};

