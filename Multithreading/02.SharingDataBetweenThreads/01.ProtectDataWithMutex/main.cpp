#include <iostream>
#include "CustomList.hpp"
#include "BetterCustomList.hpp"

int main()
{
	std::mutex mutex;
	std::list<int> numbersList;

	//using classic lock - unlock way
	mutex.lock();
	numbersList.push_back(5);
	mutex.unlock();

	//using (better) lock guard
	std::lock_guard<std::mutex> guard(mutex);
	numbersList.push_back(10);
	//no need to call unlock explicitly

	return 0;
}