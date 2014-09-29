#include "Student.h"

Student::Student(const std::string& name,
				 const std::string& uniqueNumber)
	:Human(name)
{
	this->uniqueNumber = uniqueNumber;
}

Student::~Student()
{
}
