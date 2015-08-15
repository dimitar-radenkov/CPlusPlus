#ifndef LIST_ITEM_HPP
#define LIST_ITEM_HPP

#include <memory>

template < typename T >
class ListItem
{
	T _value;
	std::shared_ptr<ListItem<T>> _nextItem{ nullptr };

public:

	template<typename UR>
	ListItem(UR&& value)		
	{
		_value = std::forward<UR>(value);
	}
	

	T value() const
	{
		return _value;
	}


	template<typename UR>
	void value(UR&& value)
	{
		_value = std::forward<UR>(value);
	}


	std::shared_ptr<ListItem> next() const
	{
		return _nextItem;
	}


	void next(std::shared_ptr<ListItem<T>> nextItem)
	{
		_nextItem = nextItem;
	}
};

#endif //LIST_ITEM_HPP