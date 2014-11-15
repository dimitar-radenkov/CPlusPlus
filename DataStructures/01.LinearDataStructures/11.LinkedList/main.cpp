#include <iostream>
#include "LinkedList.hpp"

int main()
{
	LinkedList<int> list;

	list.pushBack(1);
	list.print();

	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;

	list.popFront();
	list.print();

	list.pushBack(2);
	list.print();

	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;

	list.pushBack(3);
	list.print();

	list.pushBack(4);
	list.print();

	list.popBack();
	list.print();

	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;

	int a = 5;

}