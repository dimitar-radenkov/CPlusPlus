#pragma once
#include "Contracts\Human.h"

class Student : public Human
{
private:
	std::string facultyNumber;

public:
	Student(const std::string& firstName,
			const std::string& lastName,
			const std::string& facultyNumber);

	virtual ~Student();

	std::string getFacultyNumber() const
	{
		return this->facultyNumber;
	}
};

