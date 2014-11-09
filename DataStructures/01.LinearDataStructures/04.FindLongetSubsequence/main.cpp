#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <exception>

std::vector<int> getLongestSubsequence(const std::vector<int>& sequence)
{
	if (sequence.empty())
	{
		throw std::invalid_argument("empty sequence.");
	}

	std::map<int, int> numberCountPair;

	auto itSeq = sequence.begin();
	for (; itSeq != sequence.end(); ++itSeq)
	{
		numberCountPair[*itSeq]++;
	}

	//get max count from map
	auto itMax = numberCountPair.begin();
	auto it = numberCountPair.begin();
	for (; it != numberCountPair.end(); ++it)
	{
		if (itMax->second < it->second)
		{
			itMax = it;
		}
	}

	std::vector<int> longestSeq(itMax->second, itMax->first);

	return longestSeq;
}

int main()
{
	std::vector<int> numbers{  };

	std::vector<int> result = getLongestSubsequence(numbers);
	std::for_each(result.begin(), result.end(),
		[](const int& a){ std::cout << a << "  "; });

	system("pause");
	return 0;
}