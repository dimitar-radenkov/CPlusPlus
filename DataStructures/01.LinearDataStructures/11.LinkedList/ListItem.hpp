#ifndef LIST_ITEM_HPP
#define LIST_ITEM_HPP

#include <memory>

template < typename TData >
class ListItem
{
	TData value;
	std::shared_ptr<ListItem> nextItem;

public:
	ListItem(TData value)
		:value(value)
	{}

	ListItem()
		:value(0)
	{}

	TData getValue() const
	{
		return this->value;
	}

	void setValue(TData value)
	{
		this->value = value;
	}

	std::shared_ptr<ListItem> getNextItem() const
	{
		return this->nextItem;
	}

	void setNextItem(std::shared_ptr<ListItem> nextItem)
	{
		this->nextItem = nextItem;
	}
};

#endif //LIST_ITEM_HPP