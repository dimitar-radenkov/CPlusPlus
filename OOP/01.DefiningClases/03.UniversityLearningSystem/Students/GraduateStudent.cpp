#include "GraduateStudent.h"

GraduateStudent::GraduateStudent(const std::string& firstName,
								 const std::string& lastName,
								 const int age,
								 const std::string& studentNumber,
								 const double averageGrade)
	:Student(firstName, 
			 lastName, 
			 age, 
			 StudentType::Graduate,
			 studentNumber, 
			 averageGrade)
{
}

GraduateStudent::~GraduateStudent()
{
}
