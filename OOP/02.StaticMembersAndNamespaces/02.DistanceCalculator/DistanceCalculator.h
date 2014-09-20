#pragma once
#include <cmath>
#include "Point3D.h"

class DistanceCalculator
{
	DistanceCalculator()
	{}

public:

	virtual ~DistanceCalculator()
	{}

	static double Calculate(const Point3D& p1, const Point3D& p2)
	{
		double x = std::pow(p2.getX() - p1.getX(), 2);
		double y = std::pow(p2.getY() - p1.getY(), 2);
		double z = std::pow(p2.getZ() - p1.getZ(), 2);

		double distance = 0;
		distance = std::sqrt(x + y + z);

		return distance;
	}
};

