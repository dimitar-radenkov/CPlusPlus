#pragma once
#include <string>
#include <cstdint>

class SaleEntity
{
private:
	std::string name;
	uint32_t date;
	double price;

public:

	SaleEntity(const std::string& name,
		const uint32_t date,
		const double price)
	{
		this->name = name;
		this->date = date;
		this->price = price;
	}

	virtual ~SaleEntity()
	{
	}

	std::string getName() const
	{
		return this->name;
	}

	uint32_t getDate() const
	{
		return this->date;
	}

	double getPrice() const
	{
		return this->price;
	}
};

