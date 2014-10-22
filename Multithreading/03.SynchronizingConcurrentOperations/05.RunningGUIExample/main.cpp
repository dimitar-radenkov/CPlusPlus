#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>

std::mutex mtx;
std::deque<std::packaged_task<void()> > tasks;

bool guiShutdownMessageReceived()
{
	return false;
}

void getAndProcessGuiMessage()
{}

void guiThread()
{
	while (!guiShutdownMessageReceived())
	{
		getAndProcessGuiMessage();
		std::packaged_task<void()> task;
		{
			std::lock_guard<std::mutex> lk(mtx);
			if (tasks.empty())
			{
				continue;
			}

			task = std::move(tasks.front());
			tasks.pop_front();
		}
		task();
	}
}

std::thread guiBackgroundThread(guiThread);

template<typename TFunc>
std::future<void> postTaskForGuiThread(TFunc f)
{
	std::packaged_task<void()> task(f);
	std::future<void> res = task.get_future();
	std::lock_guard<std::mutex> lk(mtx);
	tasks.push_back(std::move(task));

	return res;
}

int main()
{


	return 0;
}