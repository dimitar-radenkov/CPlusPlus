#pragma once
#include <string>
#include <sstream>

class Point3D
{
private:
	double x;
	double y;
	double z;

public:
	static Point3D StartingPoint;

	Point3D(const double x,
			const double y,
			const double z);

	virtual ~Point3D();

	std::string toString() const;

	double getX() const
	{
		return this->x;
	}

	double getY() const
	{
		return this->y;
	}

	double getZ() const
	{
		return this->z;
	}
};

