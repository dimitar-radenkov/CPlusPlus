#pragma once
#include <string>

//This is an abstract class
class Human
{
protected:
	std::string name;

	Human(const std::string& name)
	{
		this->name = name;
	}

public:
	virtual ~Human()
	{
	}

	std::string getName() const
	{
		return this->name;
	}
};

