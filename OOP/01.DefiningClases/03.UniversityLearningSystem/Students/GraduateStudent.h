#pragma once
#include "Contracts\Student.h"

class GraduateStudent : public Student
{
public:
	GraduateStudent(const std::string& firstName,
					const std::string& lastName,
					const int age,
					const std::string& studentNumber,
					const double averageGrade);

	~GraduateStudent();
};

