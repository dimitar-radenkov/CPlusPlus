#include "Frog.h"


Frog::Frog(const std::string& name,
		   const int age,
		   const bool isMale)
	:Animal(name, age, isMale)
{
}


Frog::~Frog()
{
}


void Frog::ProduceSound() const
{
	std::cout << "Kvak Kvak" << std::endl;
}
