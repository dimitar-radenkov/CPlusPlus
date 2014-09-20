#include "OnlineStudent.h"

OnlineStudent::OnlineStudent(const std::string& firstName,
							 const std::string& lastName,
							 const int age,
							 const std::string& studentNumber,
							 const double averageGrade)
	:CurrentStudent(firstName,
				    lastName,
				    age,
				    studentNumber,
				    averageGrade,
				    "online")
{
}

OnlineStudent::~OnlineStudent()
{
}

std::string OnlineStudent::toString() const
{
	return this->CurrentStudent::toString();
}
