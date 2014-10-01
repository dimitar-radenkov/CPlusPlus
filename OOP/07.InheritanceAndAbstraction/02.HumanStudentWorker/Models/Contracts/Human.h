#pragma once
#include <string>

//This is an abstract class
class Human
{
protected:
	std::string firstName;
	std::string lastName;

	Human(const std::string& firstName,
		  const std::string& lastName)
	{
		this->firstName = firstName;
		this->lastName = lastName;
	}

public:
	virtual ~Human()
	{
	}

	std::string getFirstName() const
	{
		return this->firstName;
	}

	std::string getLastName() const
	{
		return this->lastName;
	}
};

