#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void makeSomeCalculations(int n)
{
	std::cout << n << " " << std::endl;
}

int main()
{
	std::vector<std::thread> threads;
	for (size_t i = 0; i < 20; i++)
	{
		threads.push_back(std::thread(makeSomeCalculations, i));
	}

	//call join to all threads
	std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join));

	return 0;
}