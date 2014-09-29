#pragma once
#include <string>
#include <memory>
#include <vector>

#include "Models/Student.h"

class Discipline
{
private:
	std::string name;
	int numberOfLectures;
	std::vector<Student> students;

public:
	Discipline(const std::string& name,
			   const int numberOfLectures,
			   std::vector<Student>& students)
	{
		this->name = name;
		this->numberOfLectures = numberOfLectures;
		this->students = students;
	}

	virtual ~Discipline()
	{
	}
};

