#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> sequence{ 12, 33, 4, 5, -1, -22, 16 };

	//remove all negative numbers;
	sequence.erase(
		std::remove_if(sequence.begin(), sequence.end(), [](const int& a){ return a < 0; }), 
		sequence.end());

	std::for_each(sequence.begin(), sequence.end(),
		[](const int& a) { std::cout << a << "  "; });

	system("pause");
	return 0;
}