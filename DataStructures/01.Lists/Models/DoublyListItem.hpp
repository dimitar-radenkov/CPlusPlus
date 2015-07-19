#ifndef __DOUBLY_LIST_ITEM_HPP__
#define __DOUBLY_LIST_ITEM_HPP__

template <typename T>
class DoublyListItem
{
	T _value{ 0 };
	std::shared_ptr<DoublyListItem<T>> _prev{ nullptr };
	std::shared_ptr<DoublyListItem<T>> _next{ nullptr };

public:

	template <typename UR>
	DoublyListItem(UR&& value)
	{
		_value = std::forward<T>(value);
	}

	~DoublyListItem()
	{
	}

	T value() const
	{
		return _value;
	}

	std::shared_ptr<DoublyListItem<T>> prev()
	{
		return _prev;
	}

	void prev(std::shared_ptr<DoublyListItem<T>> listItem)
	{
		_prev = listItem;
	}

	std::shared_ptr<DoublyListItem<T>> next()
	{
		return _next;
	}

	void next(std::shared_ptr<DoublyListItem<T>> listItem)
	{
		_next = listItem;
	}
};

#endif //__DOUBLY_LIST_ITEM_HPP__