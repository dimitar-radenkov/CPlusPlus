#include "Person.h"

Person::Person(const std::string& firstName,
			   const std::string& lastName,
			   const int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}

Person::~Person()
{
}

std::string Person::toString() const
{
	std::stringstream ss;

	ss << "First name : " << this->firstName << std::endl;
	ss << "Last name : " << this->firstName << std::endl;
	ss << "Age : " << this->firstName << std::endl;

	return ss.str();
}
