#include <iostream>
#include <stack>
#include <functional>
#include <sstream>

int main()
{
	std::cout << "How many numbers do you like to read : ";
	int n = 0;
	std::cin >> n;

	std::stack<int> numbers;
	while (n--)
	{
		std::string input("");
		std::getline(std::cin, input);

		try
		{
			int number = std::stoi(input);
			numbers.push(number);
		}
		catch (...)
		{
			std::cout << "You have entered invalid number. " << std::endl;
			std::cout << "Enter another one : " << std::endl;
			++n;
		}
	}

	//print 
	while (!numbers.empty())
	{
		std::cout << "  " << numbers.top() ;

		//remove element
		numbers.pop();
	}

	system("pause");
	return 0;
}