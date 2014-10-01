#pragma once
#include "Contracts\Human.h"

class Worker : public Human
{
private:
	double weekSalary;
	double workHoursPerDay;

public:
	Worker(const std::string& firstName,
		   const std::string& lastName,
		   const double weekSalary,
		   const double workHoursPerDay);

	virtual ~Worker();

	double getWeekSalary() const
	{
		return this->weekSalary;
	}

	double getWorkHoursPerDay() const
	{
		return this->workHoursPerDay;
	}

	double moneyPerHour() const;
};

