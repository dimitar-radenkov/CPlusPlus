#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <exception>
#include "ListItem.hpp"

template <typename TData>
class LinkedList
{
	std::shared_ptr<ListItem<TData>> last;
	std::shared_ptr<ListItem<TData>> first;
	int count;

	void throwIfEmpty() const
	{
		if (this->count == 0)
		{
			throw std::exception("list is empty");
		}
	}

public:
	LinkedList()
	{
		this->count = 0;
		this->first = nullptr;
		this->last = nullptr;
	}

	TData& front() const
	{
		throwIfEmpty();

		return this->first->getValue();
	}

	TData& back() const
	{
		this->throwIfEmpty();

		return this->last->getValue();
	}

	void pushBack(TData value)
	{
		if (this->count == 0)
		{	
			this->first.reset(new ListItem<TData>(value));
			this->last = this->first;
		}
		else
		{
			std::shared_ptr<ListItem<TData>> nextItem(
				new ListItem<TData>(value));
			
			this->last->setNextItem(nextItem);
			this->last = nextItem;
		}

		++this->count;
	}
	
	void popBack()
	{
		this->throwIfEmpty();

		if (this->first->getNextItem() == nullptr)
		{
			this->first = nullptr;
		}
		else
		{
			std::shared_ptr<ListItem<TData>> prev;
			auto current = this->first;
			while (current->getNextItem() != nullptr)
			{
				prev = current;
				auto next = current->getNextItem();
				current = next;
			}

			prev->setNextItem(nullptr);
			this->last = prev;
		}

		--this->count;
	}

	void pushFront(TData value)
	{
		if (this->count == 0)
		{
			this->first.reset(new ListItem<TData>(value));
			this->current = this->first;
		}
		else
		{
			std::shared_ptr<ListItem<TData>> newElement(
				new ListItem<TData>(value));

			newElement->setNextItem(this->first);
			this->last = newElement;
		}

		++this->count;
	}

	void popFront()
	{
		this->throwIfEmpty();

		if (this->first->getNextItem() = nullptr)
		{
			this->first = nullptr;
		}
		else
		{
			this->first = this->first->getNextItem();
		}

		--this->count;
	}

	void print()
	{
		auto curr = this->first;
		while (curr != nullptr)
		{
			std::cout << "  " << curr->getValue();

			auto next = curr->getNextItem();
			curr = next;
		}

		std::cout << std::endl;
	}

	int size() const
	{
		return this->count;
	}
};

#endif //LINKED_LIST_HPP