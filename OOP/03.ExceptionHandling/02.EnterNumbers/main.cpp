#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "ReadNumbersException.h"

int ReadNumber(int start, int end)
{
	std::string input;
	std::cin >> input;

	std::for_each(input.begin(),
			      input.end(),
				  [](char c)
	{
		if (isalpha(c))
		{
			throw ReadNumbersException("Non-number text entered.");
		}
	});

	std::stringstream ss;
	ss << input;

	int number = 0;
	ss >> number;

	if (number > end || 
		number < start)
	{
		std::stringstream errorMessageBuilder;
		errorMessageBuilder << "Invalid number. Must be between ";
		errorMessageBuilder << start << " and " << end << ". ";

		throw ReadNumbersException(errorMessageBuilder.str());
	}

	return number;
}

std::vector<int> Read10NumbersInRange(int start, int end)
{
	const int NumbersToRead = 10;
	std::vector<int> numbersList;

	for (size_t i = 0; i < NumbersToRead; i++)
	{
		int number = ReadNumber(start, end);

		if (!numbersList.empty() &&
			numbersList.back() > number)
		{
			throw ReadNumbersException("Number must be greater than last one.");
		}
		numbersList.push_back(number);
	}

	return numbersList;
}

void PrintNumbers(std::vector<int>& numbers)
{
	std::cout << "you have entered : ";
	std::for_each(numbers.begin(), numbers.end(), [](int number)
	{
		std::cout << "  " << number;
	});
	std::cout << std::endl;
}

int main()
{
	while (true)
	{
		try
		{
			auto numbers = Read10NumbersInRange(1, 100);
			PrintNumbers(numbers);
			break;
		}
		catch (ReadNumbersException& ex)
		{
			std::cout << ex.what() << std::endl;
			std::cout << "start all over again" << std::endl;
		}
		catch (std::exception)
		{
			std::cout << "unknown exception occurred." << std::endl;
			std::cout << "start all over again" << std::endl;
		}
	}

	system("pause");
	return 0;
}