#include "Manager.h"


Manager::Manager(const int id,
	const std::string& firstName,
	const std::string& lastName,
	const double salary,
	const Department department,
	const std::vector<std::shared_ptr<IEmployee>> employees)
	:IManager(id, firstName, lastName, salary, department, employees)
{
}


Manager::~Manager()
{
}


std::string Manager::toString() const
{
	std::stringstream ss;

	ss << "Id " << IPerson::id << std::endl;
	ss << "FirstName " << IPerson::firstName << std::endl;
	ss << "LastName " << IPerson::lastName << std::endl;
	ss << "Salary " << IEmployee::salary << std::endl;
	ss << "Department " << "Production " << std::endl;

	ss << "Projects : [";
	std::for_each(this->employees.begin(), this->employees.end(),
		[&ss](const std::shared_ptr<IEmployee> emp){ss << emp->toString() << "  "; });
	ss << "]" << std::endl;

	return ss.str();
}
