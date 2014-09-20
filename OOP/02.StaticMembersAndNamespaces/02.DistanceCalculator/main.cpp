#include <iostream>
#include "Point3D.h"
#include "DistanceCalculator.h"

int main()
{
	Point3D p1(1, 1, 1);
	Point3D p2(2, 2, 2);

	double distance = DistanceCalculator::Calculate(p1, p2);

	std::cout << "Distance between p1 and p2 = " << distance << std::endl;

	system("pause");
	return 0;
}