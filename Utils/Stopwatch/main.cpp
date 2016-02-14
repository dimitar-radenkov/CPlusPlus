#include <chrono>
#include <iostream>
#include <thread>

#include "Stopwatch.hpp"

int main()
{
	Stopwatch<std::chrono::system_clock> stopwatch;
	auto elapsed1 = stopwatch.elapsed<std::chrono::milliseconds>();

	stopwatch.start();

	//simulate long operation
	std::this_thread::sleep_for(std::chrono::seconds(2));
	auto elapsed = stopwatch.elapsed<std::chrono::milliseconds>();


	std::cout << "Elapsed time : " << elapsed.count() << "\n";

	return 0;
}