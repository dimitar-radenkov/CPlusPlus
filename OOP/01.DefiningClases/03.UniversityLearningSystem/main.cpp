#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include "Contracts\Student.h"
#include "Students\GraduateStudent.h"
#include "Students\OnlineStudent.h"
#include "Students\OnsiteStudent.h"
#include "Students\DropoutStudent.h"

int main()
{

	std::shared_ptr<Student> mitko(
		new GraduateStudent("Dimitar", 
							"Radenkov", 
							28, 
							"F40029", 
							5.21));

	std::shared_ptr<Student> rali(
		new OnlineStudent("Ralica",
						  "Radenkova",
						   31,
						   "MS9898",
						   6.00));

	std::shared_ptr<Student> niki(
		new OnsiteStudent("Nikol",
						  "Radenkova",
						   8,
						  "MS9898",
						   4.25));

	std::shared_ptr<Student> alex(
		new DropoutStudent("Alexander",
						   "Radenkov",
							11,
							"F41119",
							5.16,
							"Too small"));

	std::vector<std::shared_ptr<Student>> students{ mitko, rali, niki, alex };

	//sort students by grade descending
	std::sort(students.begin(), 
			  students.end(), 
			  [](std::shared_ptr<Student > s1, std::shared_ptr<Student> s2)
	{
		return s1->getAverageGrade() > s2->getAverageGrade();
	});


	//print them on console
	std::for_each(students.begin(),
				  students.end(),
				  [](std::shared_ptr<Student > s)
	{
		std::cout << s->toString() << std::endl;
	});

	system("pause");
	return 0;
}