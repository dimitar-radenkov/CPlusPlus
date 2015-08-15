#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <exception>
#include "Models/ListItem.hpp"

template <typename T>
class LinkedList
{
	std::shared_ptr<ListItem<T>> _last{ nullptr };
	std::shared_ptr<ListItem<T>> _first{ nullptr };
	std::size_t _count{ 0 };

	void throwIfEmpty() const
	{
		if (_count == 0)
		{
			throw std::exception("list is empty");
		}
	}

public:	

	T front() const
	{
		throwIfEmpty();
		return _first->value();
	}

	T back() const
	{
		throwIfEmpty();
		return _last->value();
	}

	template <typename UR>
	void pushBack(UR&& value)
	{
		auto current = std::make_shared<ListItem<UR>>(value);

		if (_count == 0)
		{	
			_first = current;
			_last = current;
		}
		else
		{		
			_last->next(current);
			_last = current;
		}

		++_count;
	}
	
	void popBack()
	{
		throwIfEmpty();

		if (_first->next() == nullptr)
		{
			_first = nullptr;
		}
		else
		{
			std::shared_ptr<ListItem<T>> prev;
			auto current = _first;
			while (current->next() != nullptr)
			{
				prev = current;
				auto next = current->next();
				current = next;
			}

			prev->next(nullptr);
			_last = prev;
		}

		--_count;
	}

	template <typename UR>
	void pushFront(UR&& value)
	{
		auto current = std::make_shared<ListItem<UR>>(value);

		if (_count == 0)
		{
			_first = current;
			_current = _first;
		}
		else
		{			
			current->next(_first);
			_last = current;
		}

		++_count;
	}

	void popFront()
	{
		_throwIfEmpty();

		if (_first->next() = nullptr)
		{
			_first = nullptr;
		}
		else
		{
			_first = _first->next();
		}

		--_count;
	}

	void print()
	{
		auto curr = _first;
		while (curr != nullptr)
		{
			std::cout << "  " << curr->value();

			auto next = curr->next();
			curr = next;
		}

		std::cout << std::endl;
	}

	std::size_t size() const
	{
		return _count;
	}
};

#endif //__LINKED_LIST_HPP__