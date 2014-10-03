#include <iostream>
#include "Models/Contracts/IEmployee.h"
#include "Models/Contracts/IManager.h"
#include "Models/Employees/SalesEmployee.h"
#include "Models/Employees/Manager.h"
#include "Models/Employees/Developer.h"

int main()
{
	std::shared_ptr<IEmployee> emp(
		new SalesEmployee(5, "Dimitar", "Radenkov", 1200, 
			std::vector < SaleEntity > {}));

	std::shared_ptr<IManager> manager(
		new Manager(1, "Tencho", "Tenchev", 5000, Department::Marketing,
			std::vector < std::shared_ptr<IEmployee> > {}));

	std::shared_ptr<IPerson> dev(
		new Developer(55, "Bill", "Gates", 999999, std::vector < Project > {}));

	
	std::vector<std::shared_ptr<IPerson>> persons{ emp, manager, dev };

	std::for_each(persons.begin(), persons.end(),
		[](std::shared_ptr < IPerson > person){std::cout << person->toString() << std::endl; });

	system("pause");
	return 0;
}