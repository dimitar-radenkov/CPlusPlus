#include "CompanyCustomer.h"


CompanyCustomer::CompanyCustomer(
	const std::string& name)
	:Customer(CustomerType::Companies, name)
{
}


CompanyCustomer::~CompanyCustomer()
{
}
