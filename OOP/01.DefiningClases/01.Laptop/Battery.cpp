#include "Battery.h"


Battery::Battery()
{
	this->life = InitialLife;
}


Battery::~Battery()
{
}

void Battery::operator = (Battery battery)
{
	this->life = battery.life;
}

std::string Battery::toString() const
{
	std::stringstream ss;
	ss << "Battery Life : " << this->life;

	return ss.str();
}