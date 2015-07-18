#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "Models/LinkedList.hpp"

template < typename T >
class LinkedQueue
{
	LinkedList<T> _linkList;

	void throwIfEmpty()
	{
		if (linkList.size() == 0)
		{
			throw std::exception("queue is empty");
		}
	}

public:

	T& back()
	{
		throwIfEmpty();

		return _linkList.back();
	}

	T& front()
	{
		throwIfEmpty();

		return _linkList.front();
	}

	void push(const T item)
	{
		_linkList.pushBack(item);
	}

	void pop()
	{
		_linkList.popFront();
	}

	std::size_t size()
	{
		return _linkList->size();
	}

	bool empty()
	{
		return _linkList.size() == 0;
	}

};

#endif //LINKED_QUEUE_HPP