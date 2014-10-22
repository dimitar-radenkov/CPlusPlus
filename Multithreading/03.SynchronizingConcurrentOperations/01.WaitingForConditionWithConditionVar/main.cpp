#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::queue<int> queue;
std::condition_variable condition;

void preparationThread()
{
	bool hasDataToPrepare = true;
	while (hasDataToPrepare)
	{
		std::cout << "preparing..." << std::endl;
		const int data = 1;
		std::lock_guard<std::mutex> lk(mtx);
		queue.push(data);
		condition.notify_one();
	}
}
void processingThread()
{
	while (true)
	{
		std::unique_lock<std::mutex> lk(mtx); //lock mutex
		condition.wait(lk, 
			[]{return !queue.empty(); }); // wait until queue is NOT empty

		int data = queue.front();
		queue.pop();
		lk.unlock(); // unlock mutex
		
		//process data
		bool isLastData = true;
		if (isLastData)
		{
			break;
		}
	}
}

int main()
{
	
	return 0;
}