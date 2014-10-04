#include "IndividualCustomer.h"


IndividualCustomer::IndividualCustomer(
	const std::string& name)
	:Customer(CustomerType::Individuals, name)
{
}


IndividualCustomer::~IndividualCustomer()
{
}
