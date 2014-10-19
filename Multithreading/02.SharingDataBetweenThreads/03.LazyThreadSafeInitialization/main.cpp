#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
#include <algorithm>

class Student
{
public :
	void sayHello()
	{
		std::cout << "hello " << std::endl;
	}
};

std::shared_ptr<Student> student;
std::mutex mutex;

//option1
void LazyInit()
{
	std::cout << "try to init" << std::endl;
	std::lock_guard<std::mutex> guard(mutex);
	if (student == nullptr)
	{
		std::cout << "initialized..." << std::endl;
		student.reset(new Student);
	}
}

//option2
std::shared_ptr<Student> LazyInit2()
{
	//this is also thread safe
	static std::shared_ptr<Student> s;
	return s;
}

int main()
{
	std::vector<std::thread> threads;

	for (size_t i = 0; i < 20; i++)
	{	
		threads.push_back(std::thread(LazyInit));
	}

	//wait for all threads to finish
	std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join));

	return 0;
}