#include <iostream>
#include "Location.h"

int main()
{
	Location location(18.555, 195.5555, Planet::Earth);

	std::cout << location.toString() << std::endl;

	system("pause");
	return 0;
}