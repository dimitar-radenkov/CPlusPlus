#pragma once
#include "Models/Human.h"

class Student : public Human
{
private:
	std::string uniqueNumber;

public:
	Student(const std::string& name,
			const std::string& uniqueNumber);

	virtual ~Student();
};

