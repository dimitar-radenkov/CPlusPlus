#pragma once
#include <iostream>

#include "Models/Contracts/Animal.h"
#include "Models/Contracts/ISound.h"

class Dog : public Animal, ISound
{
public:
	Dog(const std::string& name,
		const int age,
		const bool isMale);

	virtual ~Dog();

	void ProduceSound() const override;
};

