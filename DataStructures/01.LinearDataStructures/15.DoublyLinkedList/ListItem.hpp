#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

template <typename T>
class ListItem
{
	T _value;
	std::shared_ptr<ListItem<T>> _prev{ nullptr };
	std::shared_ptr<ListItem<T>> _next{ nullptr };

public:

	ListItem(T& value)
		: _value(value)
	{}

	ListItem(T&& item)
		:_value(std::move(item))
	{}

	~ListItem()
	{
	}

	T value() const
	{
		return _value;
	}

	std::shared_ptr<ListItem<T>> prev()
	{
		return _prev;
	}

	void prev(std::shared_ptr<ListItem<T>> listItem)
	{
		_prev = listItem;
	}

	std::shared_ptr<ListItem<T>> next()
	{
		return _next;
	}

	void next(std::shared_ptr<ListItem<T>> listItem)
	{
		_next = listItem;
	}
};

