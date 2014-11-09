#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main()
{
	std::vector<int> numbers{ 4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2 };

	//get odd or even occurencess
	std::map<int, int> numberCountPair;
	
	auto itNumbers = numbers.begin();
	for (; itNumbers != numbers.end(); ++itNumbers )
	{
		numberCountPair[*itNumbers]++;
	}

	//remove all odd number occurencess from vector
	numbers.erase(
		std::remove_if(numbers.begin(), numbers.end(), 
		[&numberCountPair](const int& a){ return (numberCountPair[a] % 2) != 0; }),
		numbers.end());

	//print
	std::for_each(numbers.begin(), numbers.end(),
		[](const int& a){ std::cout << a << " "; });

	system("pause");
	return 0;
}