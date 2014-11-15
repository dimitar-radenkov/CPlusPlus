#include <iostream>
#include <algorithm>
#include <array>
#include <map>

int main()
{
	std::array<int, 10> arr = { 2, 2, 3, 3, 2, 3, 4, 3, 3 };
	std::map<int, int> valueCountPair;

	//find number of occurencess
	std::for_each(arr.begin(), arr.end(),
		[&](const int& a){ valueCountPair[a]++; });
	
	
	//get majorant
	auto it = std::find_if(valueCountPair.begin(), valueCountPair.end(),
		[&](const std::pair<int, int>& pair) { return pair.second >= (arr.size() / 2); });

	if (it != valueCountPair.end())
	{
		std::cout << "Majorant is " << it->first << std::endl;
	}
	else
	{
		std::cout << "There aren't majorant" << std::endl;
	}

	system("pause");
	return 0;
}