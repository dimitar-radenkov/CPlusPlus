#include <iostream>
#include "Stack.hpp"

int main()
{
	Stack<int> s;

	try
	{
		s.pop();
	}
	catch (std::exception& ex)
	{
		std::cout << "exeption cought.. " << ex.what() << std::endl;
	}

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);

	s.print();

	s.pop();
	s.pop();

	std::cout << "top : " << s.top() << std::endl;
	std::cout << "size : " << s.size() << std::endl;

	s.top() = 15;
	std::cout << "top : " << s.top() << std::endl;

	system("pause");
	return 0;
}