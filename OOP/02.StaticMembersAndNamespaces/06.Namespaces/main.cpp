#include <iostream>
#include "Geometry2D\Circle.h"
#include "Geometry2D\DistanceCalulator.h"
#include "Geometry3D\DistanceCalculator.h"
#include "Storage\GeometrySVGStorage.h"
#include "UI\Screen3D.h"

int main()
{
	Geometry::Geometry2D::Circle cirle;

	Geometry::Geometry2D::DistanceCalculator calc2D;
	Geometry::Geometry3D::DistanceCalculator calc3D;

	Geometry::Storage::GeometrySVGStorage storage;

	Geometry::UI::Screen3D screen;

	return 0;
}