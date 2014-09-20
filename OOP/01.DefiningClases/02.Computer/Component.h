#pragma once
#include <string>
#include <sstream>

class Component
{
private:
	std::string name;
	double price;

public:
	Component(const std::string& name, const double price);
	~Component();

	std::string getName() const
	{
		return this->name;
	}

	double getPrice() const
	{
		return this->price;
	}

	std::string toString() const;
};

