#pragma once

#include <list>
#include <mutex>
#include <algorithm>

class CustomList
{
private:
	std::mutex mutex;
	std::list<int> list;
public:

	CustomList()
	{
	}

	virtual ~CustomList()
	{
	}

	void add(int number)
	{
		this->mutex.lock();
		this->list.push_back(number);
		this->mutex.unlock();
	}

	bool contains(int number)
	{
		this->mutex.lock();		
		auto it = std::find(this->list.begin(), this->list.end(), number);
		this->mutex.unlock();

		return it != this->list.end();
	}
};