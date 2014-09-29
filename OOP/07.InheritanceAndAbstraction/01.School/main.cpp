#include <iostream>
#include <algorithm>

#include "Models\Student.h"
#include "Models\Teacher.h"

int main()
{
	Student mitko("Dimitar", "F400292");
	Student ralica("Ralica", "F40082");
	Student nikol("Nikol", "F01055");

	std::vector<Student> students { mitko, ralica, nikol };

	Discipline math("Math", 6, students);
	Discipline computerScience("Computer Science", 10, students);
	std::vector<Discipline> disciplines = { math, computerScience };

	Teacher profDimov("Dimov", "T5858", disciplines);

	std::vector<Human> people = { mitko, ralica, nikol, profDimov };

	std::for_each(people.begin(), people.end(), [](Human h)
	{
		std::cout << h.getName() << std::endl;
	});

	system("pause");
	return 0;
}