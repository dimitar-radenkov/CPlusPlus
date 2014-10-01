#pragma once
#include <string>

//abstract class
class Animal
{
protected:
	std::string name;
	int age;
	bool isMale;

	Animal(const std::string& name,
		   const int age,
		   const bool isMale)
	{
		this->name = name;
		this->age = age;
		this->isMale = isMale;
	}

public:
	virtual ~Animal()
	{
	}

	std::string getName() const
	{
		return this->name;
	}

	int getAge() const
	{
		return this->age;
	}

	bool getIsMale() const
	{
		return this->isMale;
	}
};

