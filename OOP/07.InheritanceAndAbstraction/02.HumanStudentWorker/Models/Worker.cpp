#include "Worker.h"

Worker::Worker(const std::string& firstName,
			   const std::string& lastName,
			   const double weekSalary,
			   const double workHoursPerDay)
	:Human(firstName, lastName)
{
	this->weekSalary = weekSalary;
	this->workHoursPerDay = workHoursPerDay;
}

Worker::~Worker()
{
}

double Worker::moneyPerHour() const
{
	const int WORK_WEEK_DAYS = 5;
	double workHoursPerWeek = WORK_WEEK_DAYS * this->workHoursPerDay;

	double moneyPerHour = this->weekSalary / workHoursPerDay;

	return moneyPerHour;
}