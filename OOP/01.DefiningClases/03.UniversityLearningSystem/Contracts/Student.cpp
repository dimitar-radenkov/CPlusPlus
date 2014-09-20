#include "Student.h"

Student::Student(const std::string& firstName,
				 const std::string& lastName,
				 const int age,
				 const StudentType type,
				 const std::string studentNumber,
				 const double averageGrade)
	:Person(firstName, lastName, age)
{
	this->type = type;
	this->studentNumber = studentNumber;
	this->averageGrade = averageGrade;
}

Student::~Student()
{
}

std::string Student::toString() const
{
	std::stringstream ss;

	ss << this->Person::toString();
	ss << "Type : " << this->type << std::endl;
	ss << "Student number : " << this->studentNumber << std::endl;
	ss << "Average grade : " << this->averageGrade << std::endl;

	return ss.str();
}
