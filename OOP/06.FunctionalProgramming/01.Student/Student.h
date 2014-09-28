#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Student
{
private:
	std::string firstName;
	std::string lastName;
	int age;
	std::string phone;
	std::string email;
	std::vector<int> marks;

public:

	Student()
	{
		this->age = 0;
	}

	Student(const std::string& firstName,
			const std::string& lastName,
			const int age,
			const std::string& phone,
			const std::string& email,
			const std::vector<int>& marks)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
		this->phone = phone;
		this->email = email;
		this->marks = marks;
	}

	virtual ~Student()
	{
	}

	std::string getFirstName() const
	{
		return this->firstName;
	}

	std::string getLastName() const
	{
		return this->lastName;
	}

	int getAge() const
	{
		return this->age;
	}

	std::string getPhone() const
	{
		return this->phone;
	}

	std::string getEmail() const
	{
		return this->email;
	}

	std::vector<int> getMarks() const
	{
		return this->marks;
	}

	bool operator==(const Student& s1)
	{
		return (s1.getFirstName() == this->getFirstName() &&
			s1.getLastName() == this->getLastName() &&
			s1.getAge() == this->getAge() &&
			s1.getPhone() == this->getPhone() &&
			s1.getEmail() == this->getEmail() &&
			s1.getMarks() == this->getMarks());
	}

	std::string toString() const
	{
		std::stringstream ss;

		ss << "First name " << this->firstName << std::endl;
		ss << "Last name " << this->lastName << std::endl;
		ss << "Age " << this->age << std::endl;
		ss << "Phone " << this->phone << std::endl;
		ss << "E-mail " << this->email << std::endl;

		ss << "Marks ";
		std::for_each(this->marks.begin(), this->marks.end(),
			[](int mark)
		{
			std::cout << mark;
		});
		ss << std::endl;

		return ss.str();
	}
};

