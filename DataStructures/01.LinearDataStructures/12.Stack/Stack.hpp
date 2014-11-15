#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <iostream>

static const int initialSize = 2;

template < typename TData >
class Stack
{
	int count;
	int upperBound;
	int multiplier;
	std::shared_ptr<TData> arr;

	void resize()
	{
		//set upper bound
		this->upperBound *= this->multiplier;

		//create temp array
		std::shared_ptr<TData> tempArr(new TData[upperBound]);

		//copy item from old to new one
		for (size_t i = 0; i < this->count; i++)
		{
			tempArr.get()[i] = this->arr.get()[i];
		}

		arr = tempArr;
	}

	void throwIfEmpty()
	{
		if (this->count == 0)
		{
			throw std::exception("stack is empty");
		}
	}

public:

	Stack()
		:count(0), multiplier(2)
	{
		this->upperBound = initialSize;
		this->arr.reset(new TData[initialSize]);
	}

	void push(TData item)
	{
		if (this->count == this->upperBound)
		{
			this->resize();
		}
		
		this->arr.get()[count] = item;
		this->count++;
	}

	void pop()
	{
		this->throwIfEmpty();

		this->count--;
	}

	TData& top()
	{
		this->throwIfEmpty();

		return this->arr.get()[this->count - 1];
	}

	int size()
	{
		return this->count;
	}

	void print()
	{
		for (size_t i = 0; i < this->count; i++)
		{
			std::cout << "  " << this->arr.get()[i];
		}
		std::cout << std::endl;
	}
};

#endif //STACK_HPP