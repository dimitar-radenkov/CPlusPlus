#pragma once
#include <iostream>
#include "Contracts\Student.h"

class CurrentStudent : public Student
{
protected:
	std::string status;

	CurrentStudent(const std::string& firstName,
				   const std::string& lastName,
				   const int age,
				   const std::string& studentNumber,
				   const double averageGrade,
				   const std::string& status);

	virtual ~CurrentStudent();

public:
	virtual std::string toString() const;
};

