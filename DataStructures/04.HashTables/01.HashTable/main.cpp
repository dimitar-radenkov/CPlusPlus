#include "HashTable.hpp"

#include <map>


int main()
{

	std::map<int, std::string> sss;
	auto ss = sss[2];

	HashTable<int, std::string> table(2);
	table.add(1, "1");
	table.add(2, "2");
	table.add(3, "3");
	table.add(4, "4");

	table.remove(1);

	auto aa = table[2];
	table[5] = "5";
	auto aaa = table[5];
	

	return 0;
}