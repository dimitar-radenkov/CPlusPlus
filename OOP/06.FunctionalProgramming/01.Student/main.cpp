#include <iostream>
#include <algorithm>
#include <string>

#include "Student.h"

std::vector<Student> createStudents()
{
	Student s1("Dimitar",
		"Radenkov",
		28,
		"08889793457",
		"dimitar.radenkov1@gmail.com",
		std::vector < int > {1, 2, 3, 5});

	Student s2("Ralica",
		"Vaskova",
		32,
		"088998899889",
		"ralinaa@abv.bg",
		std::vector < int > {4, 2, 3, 4});

	Student s3("Nikol",
		"Georgieva",
		18,
		"08989898989",
		"nikol4eto@abv.bg",
		std::vector < int > {2, 2, 2, 2});

	Student s4("Alexander",
		"Radenkov",
		19,
		"08989898989",
		"alex@abv.bg",
		std::vector < int > {6, 6, 6, 6});

	std::vector<Student> students{ s1, s2, s3, s4 };

	return students;
}

int main()
{	
	auto students = createStudents();

	//sort by first name
	std::sort(students.begin(), students.end(), [](Student&s1, Student& s2)
	{
		return s1.getFirstName() < s2.getFirstName();
	});

	//show only students whose first name is before their last name alphabetically
	std::for_each(students.begin(), students.end(), [](Student& s)
	{
		if (s.getFirstName() < s.getLastName())
		{
			std::cout << s.getFirstName() << "  " << s.getLastName() << std::endl;
		}
	});
	std::cout << std::endl;

	//show only students that have email @abv.bg
	std::for_each(students.begin(), students.end(), [](Student& s)
	{
		if (s.getEmail().find("@abv.bg") != std::string::npos)
		{
			std::cout << s.getFirstName() << "  " << s.getEmail() << std::endl;
		}
	});
	std::cout << std::endl;



	system("pause");
	return 0;
}