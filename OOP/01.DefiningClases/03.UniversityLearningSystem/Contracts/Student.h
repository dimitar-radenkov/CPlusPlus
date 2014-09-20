#pragma once
#include "Contracts\Person.h"
#include "Contracts\StudentType.h"

class Student : public Person
{
private:
	StudentType type;

protected:
	std::string studentNumber;
	double averageGrade;

	Student(const std::string& firstName,
			const std::string& lastName,
			const int age,
			const StudentType type,
			const std::string studentNumber,
			const double averageGrade);

	virtual ~Student();

public:
	std::string getStudentNumber() const
	{
		return this->studentNumber;
	}

	double getAverageGrade() const
	{
		return this->averageGrade;
	}

	virtual std::string toString() const override;
};

