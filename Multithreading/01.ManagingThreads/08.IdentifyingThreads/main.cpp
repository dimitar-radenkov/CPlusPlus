#include <iostream>
#include <thread>

void doMasterWork(){}

void doCommonWork(){}

void someAlgorithm()
{
	static std::thread::id masterThreadId;
	if (std::this_thread::get_id() == masterThreadId)
	{
		doMasterWork();
	}
	doCommonWork();
}

int main()
{
	std::thread t;
	std::cout << "thread id" << t.get_id() << std::endl;

	return 0;
}