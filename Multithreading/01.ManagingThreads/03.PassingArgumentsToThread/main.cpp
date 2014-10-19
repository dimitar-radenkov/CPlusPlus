#include <iostream>
#include <thread>
#include <string>
#include <chrono>

void simpleOperation(int a, std::string& str)
{
	for (size_t i = 0; i < 10; i++)
	{			
		std::cout << a << " " << str << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	str = "other value";
	std::cout << "operation finished !" << std::endl;
}

int main()
{
	std::string strToPass = "test";
	std::thread t(simpleOperation, 5, strToPass);

	//if join is missing exception is raised, because program finished 
	//but thread is not ready
	t.join();
	std::cout << strToPass << std::endl; //prints test (string is NOT changed)

	//pass string as ref
	std::thread t2(simpleOperation, 5, std::ref(strToPass));
	t2.join();
	std::cout << strToPass << std::endl; //prints other value (string IS changed)

	int a = 5;

	return 0;
}