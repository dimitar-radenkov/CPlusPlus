#include "DropoutStudent.h"

DropoutStudent::DropoutStudent(const std::string& firstName,
							   const std::string& lastName,
							   const int age,
							   const std::string& studentNumber,
							   const double averageGrade,
							   const std::string& dropoutReason)
	:Student(firstName, 
			 lastName, 
			 age, 
			 StudentType::Dropout,
			 studentNumber,
			 averageGrade)
{
	this->dropoutReason = dropoutReason;
}

DropoutStudent::~DropoutStudent()
{
}

void DropoutStudent::Reapply() const
{
	std::cout << this->Student::toString();
	std::cout << "Reason : " << this->dropoutReason << std::endl;
}
