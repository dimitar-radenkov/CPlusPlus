#pragma once
#include <string>

class IPerson
{
protected:
	int id;
	std::string firstName;
	std::string lastName;

	IPerson(const int id,
		const std::string& firstName,
		const std::string& lastName)
	{
		this->id = id;
		this->firstName = firstName;
		this->lastName = lastName;
	}

public:
	virtual ~IPerson()
	{}

	virtual int getId() const = 0;

	virtual std::string getFirstName() const = 0;

	virtual std::string getLastName() const = 0;

	virtual std::string toString() const = 0;
};

