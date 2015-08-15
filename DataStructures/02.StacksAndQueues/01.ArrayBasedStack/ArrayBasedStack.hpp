#ifndef __ARRAY_BASED_STACK__
#define __ARRAY_BASED_STACK__

#include <exception>

template<typename T>
class ArrayBasedStack
{
	const size_t INITIAL_SIZE = 4;

	size_t _count{ 0 };
	size_t _capacity{ 0 };

	T* _top{ nullptr };
	T* _data{ nullptr };

	void grow()
	{
		_capacity *= 2;
		T* newData = new T[_capacity];

		//copy old data to newOne
		for (size_t i = 0; i < _count; ++i)
		{
			newData[i] = _data[i];
		}

		delete[] _data;

		_data = newData;
		_top = &_data[_count - 1];
	}

	void throwIfEmpty()
	{
		if (isEmpty())
		{
			throw std::exception("stack is empty");
		}
	}

public:

	ArrayBasedStack()
	{
		_data = new T[INITIAL_SIZE];
		_capacity = INITIAL_SIZE;
	}

	ArrayBasedStack(std::initializer_list<T> list)
		: ArrayBasedStack()
	{
		for (auto i : list)
		{
			push(i);
		}
	}

	ArrayBasedStack(ArrayBasedStack& stack)
	{
		_count = stack._count;
		_capacity = stack._capacity;

		_data = new T[_count];
		std::memcpy(_data, stack._data, sizeof(T) * _count);
		_top = &_data[_count - 1];
	}

	ArrayBasedStack(ArrayBasedStack&& stack)
	{
		_data = std::move(stack._data);
		_data = std::move(stack._top);
		_count = std::move(stack._count);
		_capacity = std::move(stack._capacity);
	}
		
	~ArrayBasedStack()
	{
		delete[] _data;
	}

	ArrayBasedStack& operator=(ArrayBasedStack& stack)
	{
		_count = stack._count;
		_capacity = stack._capacity;
		
		_data = new T[_count];
		std::memcpy(_data, stack._data, sizeof(T) * _count);
		_top = &_data[_count - 1];

		return *this;
	}

	ArrayBasedStack& operator=(ArrayBasedStack&& stack)
	{
		_data = std::move(stack._data);
		_top = std::move(stack._top);
		_count = std::move(stack._count);
		_capacity = std::move(stack._capacity);

		return *this;
	}

	template<typename UR>
	void push(UR&& item)
	{
		if (_count == _capacity)
		{
			grow();
		}

		if (isEmpty())
		{
			_top = _data;
		}
		else
		{
			++_top;			
		}

		*_top = std::forward<UR>(item);
		++_count;
	}

	T pop()
	{
		throwIfEmpty();

		--_count;
		return *_top--;
	}

	T top()
	{
		throwIfEmpty();

		return *_top;
	}

	bool isEmpty() const
	{
		return (_count == 0);
	}

	size_t size() const
	{
		return _count;
	}

	size_t capacity() const
	{
		return _capacity;
	}
};

#endif // __ARRAY_BASED_STACK__

