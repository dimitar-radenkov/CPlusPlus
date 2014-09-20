#include "CurrentStudent.h"


CurrentStudent::CurrentStudent(const std::string& firstName,
							   const std::string& lastName,
							   const int age,
							   const std::string& studentNumber,
							   const double averageGrade,
							   const std::string& status)
	:Student(firstName,
			 lastName,
			 age,
			 StudentType::Current,
			 studentNumber,
			 averageGrade)
{
	this->status = status;
}

CurrentStudent::~CurrentStudent()
{
}

std::string CurrentStudent::toString() const
{
	std::stringstream ss;
	ss << this->Student::toString();
	ss << "Status : " << this->status << std::endl;

	return ss.str();
}
