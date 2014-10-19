#include <iostream>
#include <thread>
#include <string>
#include <chrono>

void simpleOperation()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "simple operation..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

std::thread foo()
{
	std::thread t(simpleOperation);
	return t;
}

void bar(std::thread t)
{
	if (t.joinable())
	{
		t.join();
	}
}

int main()
{
	auto t1 = foo();
	bar(std::move(t1));

	
	return 0;
}