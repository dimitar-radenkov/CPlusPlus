#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

template<typename T>
class ThreadSafeQueue
{
private:
	mutable std::mutex mtx;
	std::queue<T> queue;
	std::condition_variable condition;

public:
	ThreadSafeQueue()
	{}

	ThreadSafeQueue(const ThreadSafeQueue& other)
	{
		std::lock_guard<std::mutex> lk(other.mtx);
		queue = other.queue;
	}

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mtx);
		queue.push(new_value);
		condition.notify_one();
	}

	void wait_and_pop(T& value)
	{
		std::unique_lock<std::mutex> lk(mtx);
		queue.wait(lk,
			[this]{return !data_queue.empty(); });
		value = queue.front();
		queue.pop();
	}

	std::shared_ptr<T> wait_and_pop()
	{
		std::unique_lock<std::mutex> lk(mtx);
		condition.wait(lk, 
			[this]{return !data_queue.empty(); });
		std::shared_ptr<T> res(std::make_shared<T>(queue.front()));
		queue.pop();

		return res;
	}

	bool try_pop(T& value)
	{
		std::lock_guard<std::mutex> lk(mtx);
		if (queue.empty())
		{
			return false;
		}

		value = queue.front();
		queue.pop();

		return true;
	}

	std::shared_ptr<T> try_pop()
	{
		std::lock_guard<std::mutex> lk(mtx);
		if (queue.empty())
		{
			return std::shared_ptr<T>();
		}

		std::shared_ptr<T> res(std::make_shared<T>(queue.front()));
		queue.pop();

		return res;
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mtx);
		return queue.empty();
	}
};