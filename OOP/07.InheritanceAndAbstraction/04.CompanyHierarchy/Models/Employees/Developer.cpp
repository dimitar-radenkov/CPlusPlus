#include "Developer.h"


Developer::Developer(const int id,
	const std::string& firstName,
	const std::string& lastName,
	const double salary,
	const std::vector<Project>& projects)
	:IEmployee(id, firstName, lastName, salary, Department::Production)
{
	this->projects = projects;
}


Developer::~Developer()
{
}


std::string Developer::toString() const
{
	std::stringstream ss;

	ss << "Id " << IPerson::id << std::endl;
	ss << "FirstName " << IPerson::firstName << std::endl;
	ss << "LastName " << IPerson::lastName << std::endl;
	ss << "Salary " << IEmployee::salary << std::endl;
	ss << "Department " << "Production " << std::endl;

	ss << "Projects : [";
	std::for_each(this->projects.begin(), this->projects.end(),
		[&ss](const Project& project){ss << project.getName() << "  "; });
	ss << "]" << std::endl;

	return ss.str();
}
