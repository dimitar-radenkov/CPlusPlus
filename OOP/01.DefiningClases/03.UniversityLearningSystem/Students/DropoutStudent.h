#pragma once
#include <iostream>
#include "Contracts\Student.h"

class DropoutStudent : public Student
{
private:
	std::string dropoutReason;

public:
	DropoutStudent(const std::string& firstName,
				   const std::string& lastName,
				   const int age,
				   const std::string& studentNumber,
				   const double averageGrade,
				   const std::string& dropoutReason);

	~DropoutStudent();

	void Reapply() const;
};

