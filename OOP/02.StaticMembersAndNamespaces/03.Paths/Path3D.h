#pragma once
#include <vector>
#include "Point3D.h"

class Path3D
{
private:
	std::vector<Point3D> points;

public:
	Path3D();
	virtual ~Path3D();

	bool AddPoint(const Point3D& point);

	bool RemovePoint(const Point3D& point);

	std::vector<Point3D> getPoints() const
	{
		return this->points;
	}
};

