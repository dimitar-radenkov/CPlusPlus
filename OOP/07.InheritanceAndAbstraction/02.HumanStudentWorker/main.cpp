#include <iostream>
#include <vector>
#include <algorithm>

#include "Models\Student.h"
#include "Models\Worker.h"

std::vector<Student> createStudents()
{
	std::vector<Student> studentsList;
	Student student1("Dimitar", "Radenkov", "F40029");
	Student student2("Ivan", "Ivanov", "M556SSS");
	Student student3("Petar", "Ganchev", "1234678");
	Student student4("Georgi", "Gospodinov", "ML550G");
	Student student5("Stanoi", "Tabakov", "A8420T");
	Student student6("Stanislav", "Kralev", "S600AMG");
	Student student7("Krali", "Marko", "CLK220");
	Student student8("Luben", "Vazov", "19TDI4X4");
	Student student9("Radan", "Petkov", "TIW595");
	Student student10("Boiko", "Trifonov", "S630MB");

	studentsList = { 
					  student1, student2, student3, student4,
					  student5, student6, student7, student8,
					  student9, student10
				   };

	return studentsList;
}

std::vector<Worker> createWorkers()
{
	std::vector<Worker> workersList;
	Worker worker1("Petar", "Petrov", 800, 8);
	Worker worker2("Simeon", "Manolov", 1000, 7);
	Worker worker3("Brus", "Lekov", 600, 8);
	Worker worker4("Slav", "Dachev", 5500, 8);
	Worker worker5("Plamen", "Petrov", 400, 8);
	Worker worker6("Dimitar", "Dimov", 800, 8);
	Worker worker7("Stanimir", "Stanimirov", 800, 8);
	Worker worker8("Georgi", "Bobev", 900, 6);
	Worker worker9("Boris", "Hristov", 1000, 8);
	Worker worker10("Detelin", "Cvetkov", 1200, 9);

	workersList = {
		worker1, worker2, worker3, worker4,
		worker5, worker6, worker7, worker8,
		worker9, worker10
	};

	return workersList;
}

int main()
{
	auto studentList = createStudents();
	//sort by faculty number ascending
	std::sort(studentList.begin(), studentList.end(), 
		[](const Student& s1, const Student& s2)
	{
		return s1.getFacultyNumber() < s2.getFacultyNumber();
	});


	auto workersList = createWorkers();
	//sort by money per hour
	std::sort(workersList.begin(), workersList.end(),
		[](const Worker& w1, const Worker& w2)
	{
		return w1.moneyPerHour() < w2.moneyPerHour();
	});

	std::vector<Human> humansList;
	humansList.insert(humansList.end(), studentList.begin(), studentList.end());
	humansList.insert(humansList.end(), workersList.begin(), workersList.end());
	

	//sort by first than by last name
	std::sort(humansList.begin(), humansList.end(),
		[](const Human& h1, const Human& h2)
	{
		if (h1.getFirstName() != h2.getFirstName())
		{
			return h1.getFirstName() < h2.getFirstName();			
		}
		else
		{
			return h1.getLastName() < h2.getLastName();
		}
	});

	system("pause");
	return 0;
}