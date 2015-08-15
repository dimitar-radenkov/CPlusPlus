#ifndef __LINKED_STACK_HPP__
#define __LINKED_STACK_HPP__

#include "Models/ListItem.hpp"

template<typename T>
class LinkedStack
{
	std::shared_ptr<ListItem<T>> _top{ nullptr };
	std::size_t _count{ 0 };

public:
	LinkedStack()
	{}

	~LinkedStack() 
	{}
	
	template<typename UR>
	void push(UR&& item)
	{
		auto current = std::make_shared<ListItem<UR>>(item);
		if (_count == 0)
		{
			_top = current;
		}
		else
		{
			current->next(_top);
			_top = current;
		}

		++_count;
	}

	T pop()
	{
		if (isEmpty())
		{
			throw std::exception("empty stack");
		}

		T value = _top->value();
		_top = _top->next();
		--_count;

		return value;
	}

	std::size_t size()
	{
		return _count;
	}

	bool isEmpty() const
	{
		return _count == 0;
	}
};

#endif // __LINKED_STACK_HPP__