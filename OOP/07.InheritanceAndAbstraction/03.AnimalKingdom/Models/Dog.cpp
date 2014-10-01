#include "Dog.h"


Dog::Dog(const std::string& name,
		 const int age,
		 const bool isMale)
	:Animal(name, age, isMale)
{
}


Dog::~Dog()
{
}

void Dog::ProduceSound() const
{
	std::cout << "Bau Bau" << std::endl;
}