#include "OnsiteStudent.h"

OnsiteStudent::OnsiteStudent(const std::string& firstName,
							 const std::string& lastName,
							 const int age,
							 const std::string& studentNumber,
							 const double averageGrade)
	:CurrentStudent(firstName,
					lastName,
					age,
					studentNumber,
					averageGrade,
					"onsite")
{
}

OnsiteStudent::~OnsiteStudent()
{
}

std::string OnsiteStudent::toString() const
{
	return this->CurrentStudent::toString();
}
