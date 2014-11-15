#include <iostream>
#include "LinkedQueue.hpp"

int main()
{

	LinkedQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.front() = 15;
	
	std::cout << "first : " << queue.front() << std::endl;
	queue.pop();

	std::cout << "first : " << queue.front() << std::endl;

	system("pause");
	return 0;
}