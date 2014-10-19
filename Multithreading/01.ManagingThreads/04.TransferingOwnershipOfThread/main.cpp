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

void otherSimpleOperation()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "otherSimpleOperation operation..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main()
{
	std::thread t1(simpleOperation);
	std::cout << "move" << std::endl;
	std::thread t2 = std::move(t1);
	
	std::thread t3(simpleOperation);
	t1 = std::thread(otherSimpleOperation);

	t3 = std::move(t1);//this will cause exception

	//wait for threads to finish
	t3.join();
	t2.join();
	t1.join();
	

	return 0;
}