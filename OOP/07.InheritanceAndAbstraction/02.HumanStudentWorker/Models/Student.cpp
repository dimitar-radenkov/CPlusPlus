#include "Student.h"


Student::Student(const std::string& firstName,
				 const std::string& lastName,
				 const std::string& facultyNumber)
	:Human(firstName, lastName)
{
	if (facultyNumber.size() > 10 ||
		facultyNumber.size() < 5)
	{
		throw std::exception("Faculty number must be in range [5...10] symbols");
	}

	this->facultyNumber = facultyNumber;
}


Student::~Student()
{
}
