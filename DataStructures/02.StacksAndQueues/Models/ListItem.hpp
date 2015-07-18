#ifndef LIST_ITEM_HPP
#define LIST_ITEM_HPP

#include <memory>

template < typename T >
class ListItem
{
	T _value;
	std::shared_ptr<ListItem<T>> _nextItem{ nullptr };

public:

	template<typename TItem = T>
	ListItem(TItem&& value)		
	{
		_value = std::forward<TItem>(value);
	}
	

	T value() const
	{
		return _value;
	}


	template<typename TItem = T>
	void value(TItem&& value)
	{
		_value = std::forward<T>(value);
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