#include <iostream>
#include "Bitarray.h"

int main()
{
	Bitarray bits(8);
	bits[0] = 1;
	bits[1] = 1;
	bits[2] = 1;

	std::cout << bits.toString() << std::endl;

	system("pause");
	return 0;
}