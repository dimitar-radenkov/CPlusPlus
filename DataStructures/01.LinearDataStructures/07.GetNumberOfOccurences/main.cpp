#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	std::vector<int> numbers{ 3, 4, 4, 2, 3, 3, 4, 3, 2 };
	
	std::map<int, int> numberCountPair;
	std::for_each(numbers.begin(), numbers.end(),
		[&numberCountPair](const int& a){ numberCountPair[a]++; });

	//print 
	std::for_each(numberCountPair.begin(), numberCountPair.end(),
		[](std::pair<int, int> pair){ std::cout << pair.first << " --> " << pair.second << " time(s)." << std::endl; });

	system("pause");
	return 0;
}