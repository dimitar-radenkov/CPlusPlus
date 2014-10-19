#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

#include "ThreadGuard.h"

void someOperation(int& number)
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "i ,";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		number += number;
	}
	std::cout << "operation have finished " << std::endl;
}

void badExample()
{
	int localData = 5;
	//user std::ref to pass by reference in std::bind, because std::bind use  
	//value semantics by default
	auto refLocalData = std::ref(localData);
	
	//equivalent to someOperation(localData);	
	auto funcPointer = std::bind(someOperation, refLocalData); 

	//thread starts
	std::thread t(funcPointer); 

	try
	{
		//do something in current thread
		throw std::exception("exc");
	}
	catch (...)
	{
		//ensure all paths
		t.join();		
		throw;
	}
	//ensure all paths
	t.join();
}

void goodExampleUsingRAII()
{
	//Resource Acquisition Is Initialization (RAII)idiom
	
	int localData = 5;	
	auto refLocalData = std::ref(localData);
	auto funcPointer = std::bind(someOperation, refLocalData);
	std::thread t(funcPointer);

	ThreadGuard th(t); // or ThreadGuard(std::thread(funcPointer));
	//in this case all if exception raised dtor will wait for thread to finish

	try
	{
		//do smth in current thread;
		throw std::exception("exc");
	}
	catch (...)
	{
		throw;
	}
}

int main()
{
	//badExample();

	//goodExample();

	return 0;
}