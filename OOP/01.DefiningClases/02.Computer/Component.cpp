#include "Component.h"

Component::Component(const std::string& name, 
					 const double price)
	:name(name), 
	 price(price)
{
}

Component::~Component()
{
}

std::string Component::toString() const
{
	std::stringstream ss;

	ss << "-- Component --" << std::endl;
	ss << "Name : " << this->name << std::endl;
	ss << "Price : " << this->price << std::endl;

	return ss.str();
}
