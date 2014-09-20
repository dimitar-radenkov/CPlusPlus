#pragma once
#include "Students/CurrentStudent.h"

class OnlineStudent : public CurrentStudent
{
public:
	OnlineStudent(const std::string& firstName,
				  const std::string& lastName,
				  const int age,
				  const std::string& studentNumber,
				  const double averageGrade);

	virtual ~OnlineStudent();

	std::string toString() const override;
};

