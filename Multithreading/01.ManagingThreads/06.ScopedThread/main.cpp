#include <iostream>
#include "ScopedThread.h"

void simpleOperation()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "simple operation..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main()
{
	//std::thread t(simpleOperation);
	//ScopedThread st(t); //compiler error, assigment operator is deleted

	//owner ship is set directly to scoped thread
	ScopedThread st(std::thread(simpleOperation)); //it's OK

	return 0;
}