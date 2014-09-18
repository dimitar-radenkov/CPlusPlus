#include <iostream>
#include "Laptop.h"""

int main()
{
	Battery battery;
	const double screenSize = 15.5;
	const double price = 988;

	Laptop acer("V5-573G", 
				"Acer", 
				"Intel i7", 
				"NVidia", 
				battery, 
				screenSize, 
				price);

	std::cout << acer.toString() << std::endl;


	const double sonyScreenSize = 17.5;
	const double sonyPrice = 1988;
	Laptop sony("T-859",
		"Sony",
		"AMD",
		"GeForce",
		battery,
		sonyScreenSize,
		sonyPrice);

	std::cout << sony.toString() << std::endl;

	system("pause");

	return 0;
}