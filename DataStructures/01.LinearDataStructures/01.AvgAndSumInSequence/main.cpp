#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>

namespace MathOperations
{
	template<typename TType>
	static int getSum(std::vector<TType>& numbers)
	{
		int sum = 0;
		std::for_each(numbers.begin(), numbers.end(),
			[&sum](TType num){ sum += num; });

		return sum;
	}

	template<typename TType>
	static TType getAverage(std::vector<TType>& numbers)
	{
		TType sum = getSum(numbers);

		if (numbers.empty())
		{
			throw std::invalid_argument("unable to devide by zero.");
		}

		return sum / numbers.size();
	}
}

int main()
{
	std::cout << "Enter a positive integer : ";

	//read user input
	std::string input("");
	std::getline(std::cin, input);

	std::vector<int> numbers;

	while (!input.empty())
	{
		try
		{
			int number = std::stoi(input);
			numbers.push_back(number);
		}
		catch (...)
		{
			std::cout << "You have entered invalid number. " << std::endl;
			std::cout << "Enter another one : " << std::endl;
		}

		input.clear();
		std::getline(std::cin, input);
	}

	try
	{
		std::cout << "Sum : " << MathOperations::getSum(numbers) << std::endl;
		std::cout << "Average : " << MathOperations::getAverage(numbers) << std::endl;
	}
	catch (std::invalid_argument &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	system("pause");
	return 0;
}