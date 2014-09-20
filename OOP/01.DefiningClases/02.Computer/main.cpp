#include <iostream>
#include <vector>
#include <algorithm>

#include "Computer.h"



int main()
{
	std::shared_ptr<Component> processor(
		new Component("intel", 520));

	std::shared_ptr<Component> motherboard(
		new Component("chipset", 111));

	std::shared_ptr<Component> graphicCard(
		new Component("NVidia", 333));

	Computer pc("Acer",
				processor,
				motherboard,
				graphicCard);

	std::shared_ptr<Component> processor1(
		new Component("intel", 11));

	std::shared_ptr<Component> motherboard1(
		new Component("chipset", 22));

	std::shared_ptr<Component> graphicCard1(
		new Component("NVidia", 33));

	Computer pc1("Asus",
				processor1,
				motherboard1,
				graphicCard1);

	std::shared_ptr<Component> processor2(
		new Component("intel", 55));

	std::shared_ptr<Component> motherboard2(
		new Component("chipset", 66));

	std::shared_ptr<Component> graphicCard2(
		new Component("NVidia", 77));

	Computer pc2("Sony",
		processor2,
		motherboard2,
		graphicCard2);

	std::vector<Computer> computers{ pc, pc1, pc2 };
	
	std::sort(computers.begin(), 
			  computers.end(), 
			  [](Computer c1, Computer c2)
	{
		return c1.getPrice() < c2.getPrice();
	});

	std::for_each(computers.begin(),
				  computers.end(),
				  [](Computer c)
	{
		std::cout << c.toString();
		std::cout << std::endl;
	});

	system("pause");

	return 0;
}