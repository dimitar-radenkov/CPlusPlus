#pragma once

#include <list>
#include <mutex>
#include <algorithm>

class BetterCustomList
{
private:
	std::mutex mutex;
	std::list<int> list;
public:

	BetterCustomList()
	{
	}

	virtual ~BetterCustomList()
	{
	}

	void add(int number)
	{
		std::lock_guard<std::mutex> guard(mutex); //no need to call unlock()
		this->list.push_back(number);
	}

	bool contains(int number)
	{
		std::lock_guard<std::mutex> guard(mutex); //no need to call unlock()
		auto it = std::find(this->list.begin(), this->list.end(), number);
		return it != this->list.end();
	}
};

