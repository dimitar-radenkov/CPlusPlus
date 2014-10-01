#pragma once
#include <iostream>

#include "Models/Contracts/Animal.h"
#include "Models/Contracts/ISound.h"

//abstract class
class Cat : public Animal, ISound
{
protected:
	Cat(const std::string& name,
		const int age,
		const bool isMale)
		: Animal(name, age, isMale)
	{

	}

public:
	virtual ~Cat()
	{
	}

	void ProduceSound() const override
	{
		std::cout << "meuuu" << std::endl;
	}
};

