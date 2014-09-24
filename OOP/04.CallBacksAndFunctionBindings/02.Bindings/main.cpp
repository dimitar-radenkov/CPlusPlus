#include <iostream>
#include <vector>
#include <functional>
#include <string>

void show(const std::string& str1, const std::string& str2)
{
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::function<void(std::string, std::string)> f;

	f = std::bind(show, std::placeholders::_1, std::placeholders::_2);
	f("hello", "world"); // prints 'hello world'

	f = std::bind(show, std::placeholders::_2, std::placeholders::_1);
	f("hello", "world"); // prints 'world hello'


	auto changedF = std::bind(show, "hello", "world");
	changedF(); // prints 'hello world'

	//with lambda
	auto lf = std::bind([](std::string str)
	{
		std::cout << "lambda function " << std::endl;
		std::cout << str << std::endl;
		std::cout << std::endl;

	}, std::placeholders::_1);

	lf("Mitko");

	system("pause");
	return 0;
}