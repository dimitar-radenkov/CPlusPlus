#include "Point3D.h"

Point3D Point3D::StartingPoint(0, 0, 0);

Point3D::Point3D(const double x,
				const double y,
				const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3D::~Point3D()
{
}

std::string Point3D::toString() const
{
	std::stringstream ss;

	ss << "Point { ";
	ss << this->getX() << ", ";
	ss << this->getY() << ", ";
	ss << this->getZ() << " }" << std::endl;

	return ss.str();
}