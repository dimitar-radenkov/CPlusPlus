#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>

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

	//sort method1
	std::sort(numbers.begin(), numbers.end());

	//sort by functor
	std::sort(numbers.begin(), numbers.end(),
		[](const int& a, const int& b) {return a < b; });


	return 0;
}