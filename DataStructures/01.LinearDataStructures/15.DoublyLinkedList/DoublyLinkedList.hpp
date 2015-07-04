#pragma once
#include <iostream>
#include <exception>
#include "ListItem.hpp"

template<typename T>
class DoublyLinkedList
{
	int _count;
	std::shared_ptr<ListItem<T>> _first;
	std::shared_ptr<ListItem<T>> _last;

	void throwIfEmpty()
	{
		if (isEmpty())
		{
			throw new std::exception("cannot remove item from empty list");
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

	virtual ~DoublyLinkedList()
	{
	}

	int size() const
	{
		return _count;
	}

	bool isEmpty() const
	{
		return (_count == 0);
	}

	void addLast(T item)
	{	
		auto listItem = std::make_shared<ListItem<T>>(std::move(item));

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

	void addFirst(T item)
	{
		auto listItem = std::make_shared<ListItem<T>>(std::move(item));

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

	void traverse() const 
	{
		auto current = _first;
		while (current != nullptr)
		{
			std::cout << current->value() << " ";
			current = current->next();
		}
	}
	
};

