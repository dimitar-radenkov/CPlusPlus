#include <iostream>
#include "Fraction.h"

int main()
{
	
	Fraction fraction1(22, 7);
	Fraction fraction2(10, 5);
	
	Fraction sum = fraction1 + fraction2;
	Fraction substract = fraction1 - fraction2;

	std::cout << sum.toString() << std::endl;
	std::cout << substract.toString() << std::endl;

	system("pause");
	return 0;
}