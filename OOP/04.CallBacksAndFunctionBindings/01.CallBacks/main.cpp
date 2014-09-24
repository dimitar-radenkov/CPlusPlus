#include <iostream>
#include <vector>
#include <functional>
#include <string>

void ShowOnConsole(const std::string value1, const std::string value2)
{
	std::cout << "Show on console" << std::endl;
	std::cout << value1 << " ---> " << value2 << std::endl;
}

void ShowOnConsoleDecorated(const std::string value1, const std::string value2)
{
	std::cout << "\n\nShow on console decorated" << std::endl;
	std::cout << "!!!??!! " <<value1 << " ---> " << "!!??!!" << value2 << std::endl;	
}

int Sum(int a, int b)
{
	return a + b;
}

int main()
{
	std::function<void(std::string, std::string)> f = ShowOnConsole;
	f("name", "Mitko"); // will use ShowOnConsole function

	f = ShowOnConsoleDecorated;
	f("name", "Mitko"); // will use ShowOnConsoleDecorated function


	auto fSum = Sum;
	std::cout << std::endl << fSum(15, 5) << std::endl; // prints 20

	//using lambda
	auto fSumLambda = [](int a, int b) -> int
	{
		return a + b;
	};
	std::cout << std::endl << fSumLambda(66, 33) << std::endl; // prints 99

	//lambda with capture
	int capture = 5;
	auto p = [capture](int a, int b) -> int
	{
		return a + b + capture;
	};

	std::cout << p(10, 20) << std::endl; //prints 35

	system("pause");
	return 0;
}