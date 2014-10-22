#include <iostream>
#include <string>
#include <future>

class Student
{
public:
	void sayHello(const std::string& greet)
	{
		std::cout << "Hello, " << greet << std::endl;
	}

	int getLastGrade(const std::string& course)
	{
		if (course == "Math")
		{
			return 6;
		}
		else
		{
			return 5;
		}
	}
};

int main()
{
	Student mitko;

	auto future1 = std::async(&Student::sayHello, mitko, "people"); 
	//calls mitko.sayHello("people");
	//mitko is copy of Student object 'mitko'


	auto future2 = std::async(&Student::getLastGrade, &mitko, "Math");
	//calls mitko->getLastGrade("Math")
	//mitko is passed by ref


	return 0;
}