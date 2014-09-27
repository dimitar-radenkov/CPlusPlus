#include <iostream>
#include <vector>
#include "GenericList.h"

int main()
{	
	//tested - no memory leaks
	GenericList<int> list;

	for (size_t i = 1; i <= 1000; i++)
	{
		list.add(i);
	}

	std::cout << list.min() << std::endl; //   1
	std::cout << list.max() << std::endl; //1000

	list.insert(9999, 2);
	std::cout << list[1] << std::endl; // 9999

	std::cout << list.min() << std::endl; //   1
	std::cout << list.max() << std::endl; //9999

	list[15] = 6969;

	std::cout << list.contains(6969) << std::endl;  //true  (1)
	std::cout << list.contains(-9897) << std::endl; //false (0)

	std::cout << list.size() << std::endl; //1001
	list.clear();
	std::cout << list.size() << std::endl; //0

	std::cout << list[10] << std::endl; // exception

	
	system("pause");
	return 0;
}