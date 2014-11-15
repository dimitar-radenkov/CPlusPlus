#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "LinkedList.hpp"

template < typename TData >
class LinkedQueue
{
	LinkedList<TData> linkList;

	void throwIfEmpty()
	{
		if (linkList.size() == 0)
		{
			throw std::exception("queue is empty");
		}
	}

public:

	TData& back()
	{
		this->throwIfEmpty();

		return this->linkList.back();
	}

	TData& front()
	{
		this->throwIfEmpty();

		return this->linkList.front();
	}

	void push(const TData item)
	{
		this->linkList.pushBack(item);
	}

	void pop()
	{
		this->linkList.popFront();
	}

	int size()
	{
		return return->linkList->size();
	}

	bool empty()
	{
		return this->linkList.size() == 0 ? true : false;
	}

};

#endif //LINKED_QUEUE_HPP