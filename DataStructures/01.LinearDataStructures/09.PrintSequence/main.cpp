#include <iostream>
#include <queue>
#include <vector>
#include <functional>

void addSequence(std::queue<int>& queue, int num)
{
	//s2
	queue.push(num + 1);

	//s3
	queue.push((num * 2) + 1);

	//s4
	queue.push(num + 2);
}

int main()
{
	std::vector<int> numbers;
	std::queue<int> queue;
	queue.push(2);

	//get sequence
	while (queue.size() <= 50)
	{
		int num = queue.front();
		queue.pop();
		
		//collect number
		numbers.push_back(num);

		addSequence(queue, num);	
	}

	//collect rest numbers
	while (numbers.size() < 50)
	{
		int num = queue.front();
		numbers.push_back(num);
		queue.pop();
	}

	//print numbers
	std::for_each(numbers.begin(), numbers.end(),
		[](const int& n) { std::cout << "  " << n; });


	system("pause");
	return 0;
}