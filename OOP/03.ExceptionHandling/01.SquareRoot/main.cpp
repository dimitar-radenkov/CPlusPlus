#include <iostream>
#include <sstream>
#include <algorithm>
#include "MathException.h"

double SquareRoot(std::string input)
{
	std::for_each(input.begin(), 
				  input.end(), 
				  [](char c)
	{
		if (isalpha(c))
		{
			throw MathException("Invalid number");
		}
	});

	std::stringstream ss;
	ss << input;

	double d = 0;
	ss >> d;

	if (d < 0)
	{
		throw MathException("Invalid number");
	}
}

int main()
{	
	std::string input;
	std::cin >> input;

	try
	{
		double result = SquareRoot(input);
	}
	catch (MathException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (std::exception)
	{
		std::cout << "Good bye " << std::endl;
	}

	system("pause");
	return 0;
}