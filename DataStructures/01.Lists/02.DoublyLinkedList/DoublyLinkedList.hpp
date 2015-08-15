#pragma once
#include <iostream>
#include <exception>
#include <memory>
#include "Models/DoublyListItem.hpp"

template<typename T>
class DoublyLinkedList
{
	std::size_t _count;
	std::shared_ptr<DoublyListItem<T>> _first;
	std::shared_ptr<DoublyListItem<T>> _last;

	void throwIfEmpty()
	{
		if (isEmpty())
		{
			throw new std::exception("list is empty");
		}
	}

public:

	DoublyLinkedList()
	{}

	DoublyLinkedList(std::initializer_list<T> list)
	{
		for (auto& i : list)
		{
			addLast(i);
		}
	}

	std::size_t size() const
	{
		return _count;
	}

	bool isEmpty() const
	{
		return (_count == 0);
	}

	template <typename UR>
	void addLast(UR&& item)
	{	
		auto listItem = std::make_shared<ListItem<UR>>(item);

		if (isEmpty())
		{
			_first = listItem;
			_last = _first;
		}
		else
		{
			listItem->prev(_last);
			_last->next(listItem);		
			_last = listItem;
		}

		++_count;
	}

	template <typename UR>
	void addFirst(UR&& item)
	{
		auto listItem = std::make_shared<DoublyListItem<UR>>(item);

		if (isEmpty())
		{
			_first = listItem;
			_last = _first;
		}
		else
		{
			_first->prev(listItem);
			listItem->next(_first);
			_first = listItem;
		}

		++_count;
	}

	T removeLast()
	{
		throwIfEmpty();
		T val = _last->value();

		if (size() == 1)
		{
			_last = nullptr;
			_first = _last;
		}
		else
		{
			_last = _last->prev();
			_last->next(nullptr);
		}

		return val;
	}

	T removeFirst()
	{
		throwIfEmpty();
		T val = _first->value();

		if (size() == 1)
		{
			_first = nullptr;
			_last = _first;
		}
		else
		{
			_first = _first->next();
			_first->prev(nullptr);
		}

		return val;
	}	
};

