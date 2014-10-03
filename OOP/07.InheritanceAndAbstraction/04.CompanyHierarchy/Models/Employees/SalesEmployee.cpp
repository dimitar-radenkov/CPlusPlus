#include "SalesEmployee.h"


SalesEmployee::SalesEmployee(const int id,
	const std::string& firstName,
	const std::string& lastName,
	const double salary,
	const std::vector<SaleEntity>& sales)
	:IEmployee(id,firstName, lastName,salary, Department::Sales)
{
	this->sales = sales;
}


SalesEmployee::~SalesEmployee()
{
}


std::string SalesEmployee::toString() const
{
	std::stringstream ss;

	ss << "Id " << IPerson::id << std::endl;
	ss << "FirstName " << IPerson::firstName << std::endl;
	ss << "LastName " << IPerson::lastName << std::endl;
	ss << "Salary " << IEmployee::salary << std::endl;
	ss << "Department " << "Production " << std::endl;

	ss << "Projects : [";
	std::for_each(this->sales.begin(), this->sales.end(),
		[&ss](const SaleEntity& sale){ss << sale.getName() << "  "; });
	ss << "]" << std::endl;

	return ss.str();
}
