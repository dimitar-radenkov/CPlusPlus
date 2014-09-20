#pragma once
#include "Students/CurrentStudent.h"

class OnsiteStudent : public CurrentStudent
{
public:
	OnsiteStudent(const std::string& firstName,
				  const std::string& lastName,
				  const int age,
				  const std::string& studentNumber,
				  const double averageGrade);

	virtual ~OnsiteStudent();

	std::string toString() const override;
};

