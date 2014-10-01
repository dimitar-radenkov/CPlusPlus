#include <iostream>
#include <memory>
#include <vector>
#include <numeric>
#include <algorithm>

#include "Models\Kitten.h"
#include "Models\TomCat.h"
#include "Models\Dog.h"

int main()
{
	std::shared_ptr<Animal> kitten1(new Kitten("Didi", 5));
	std::shared_ptr<Animal> kitten2(new Kitten("Mimi", 4));
	std::shared_ptr<Animal> kitten3(new Kitten("Titi", 3));

	std::shared_ptr<Animal> tomcat1(new TomCat("Tom", 15));
	std::shared_ptr<Animal> tomcat2(new TomCat("Garfield", 14));
	std::shared_ptr<Animal> tomcat3(new TomCat("Fred", 13));

	std::shared_ptr<Animal> dog1(new Dog("Lasi", 15, false));
	std::shared_ptr<Animal> dog2(new Dog("Sharo", 14, true));
	std::shared_ptr<Animal> dog3(new Dog("Roki", 9, true));

	std::shared_ptr<Animal> dog4(new Dog("Roxy", 15, false));
	std::shared_ptr<Animal> dog5(new Dog("Rexy", 14, true));
	std::shared_ptr<Animal> dog6(new Dog("Arni", 9, true));

	std::vector<std::shared_ptr<Animal>> animals
	{
		kitten1, kitten2, kitten3,
		tomcat1, tomcat2, tomcat3,
		dog1, dog2, dog3,
		dog4, dog5, dog6
	};

	//get average age
	double sum = std::accumulate(animals.begin(),animals.end(),0,
		[](double currentSum, std::shared_ptr<Animal> a1){return currentSum + a1->getAge();});	
	int size = animals.size();
	double average = sum / size;

	return 0;
}