#include "Teacher.h"

Teacher::Teacher(const std::string& name,
				 const std::string& uniqueIdentifier,
				 const std::vector<Discipline>& disciplines)
	:Human(name)
{
	this->uniqueIdentifier = uniqueIdentifier;
	this->disciplines = disciplines;
}

Teacher::~Teacher()
{
}
