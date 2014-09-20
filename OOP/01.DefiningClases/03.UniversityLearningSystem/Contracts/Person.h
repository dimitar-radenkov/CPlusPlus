#pragma once
#include <string>
#include <sstream>

//This is an abstract class
class Person
{
protected:
	std::string firstName;
	std::string lastName;
	int age;

	Person(const std::string& firstName,
		   const std::string& lastName,
		   const int age);

	virtual ~Person();

public:
	virtual std::string getFirstName() const
	{
		return this->firstName;
	}

	virtual std::string getLastName() const
	{
		return this->lastName;
	}

	virtual int getAge() const
	{
		return this->age;
	}

	virtual std::string toString() const;
};

