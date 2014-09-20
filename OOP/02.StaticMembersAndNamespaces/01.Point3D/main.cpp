#include <iostream>
#include "Point3D.h"

int main()
{
	Point3D p1(1, 1, 1);
	Point3D p2(2, 2, 2);

	std::cout << p1.toString() << std::endl;
	std::cout << p2.toString() << std::endl;

	std::cout << "Starting point : " << Point3D::StartingPoint.toString() << std::endl;

	system("pause");
	return 0;
}