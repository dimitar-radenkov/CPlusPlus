#include <iostream>
#include <thread>

void doSomething(unsigned i)
{
	//do some job
	std::cout << i << std::endl;
}

struct func
{
	int& i;
	func(int& i) : i(i)
	{}

	void operator()()
	{
		for (unsigned j = 0; j<100; ++j)
		{
			doSomething(j); //this is potential danger.(dangling pointer)
		}

		std::cout << "thread finished !" << std::endl;
	}
};

int main()
{
	int someLocalState = 0;

	func f(someLocalState);
	std::thread my_thread(f); //thread starts here
	my_thread.detach(); //don't wait to finish

	std::cout << "Exiting program..." << std::endl;

	//you will see that the thread doesn't terminate

	return 0;
}