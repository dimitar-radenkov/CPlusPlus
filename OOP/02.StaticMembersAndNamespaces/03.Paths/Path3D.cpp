#include "Path3D.h"

Path3D::Path3D()
{
}

Path3D::~Path3D()
{
}

bool Path3D::AddPoint(const Point3D& point)
{
	this->points.push_back(point);

	return true;
}

bool Path3D::RemovePoint(const Point3D& point)
{
	auto itFind = std::find(this->points.begin(), this->points.end(), point);
	if (itFind != this->points.end())
	{
		return false;
	}

	this->points.erase(itFind);

	return true;
}