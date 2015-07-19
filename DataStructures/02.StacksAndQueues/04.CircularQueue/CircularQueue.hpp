#ifndef __CIRCULAR_QUEUE_HPP__
#define __CIRCULAR_QUEUE_HPP__

#include <memory>
#include <iostream>
#include <exception>

template <typename T>
class CircularQueue
{
	std::size_t _capacity{ 2 };
	std::size_t _count{ 0 };
	int _headIndex{ 0 };
	int _tailIndex{ 0 };
	T* _data;

	void grow()
	{
		T* doubledData = new T[_capacity * 2];

		_tailIndex = 0;
		while (!empty())
		{
			doubledData[_tailIndex++] = dequeue();
		}

		delete[] _data;

		_headIndex = 0;
		_data = doubledData;
		_count = _capacity;
		_capacity *= 2;
	}

	void throwIfEmpty()
	{
		if (empty())
		{
			throw std::exception("Queue is empty");
		}
	}

public:

	CircularQueue()
	{
		_data = new T[_capacity];
	}

	~CircularQueue()
	{
		delete[] _data;
	}

	template<typename UR>
	void enqueue(UR&& item)
	{
		if (_count >= _capacity)
		{
			grow();
		}

		if (_tailIndex >= static_cast<decltype(_tailIndex)>(_capacity))
		{
			_tailIndex = 0;
		}

		_data[_tailIndex++] = std::forward<T>(item);
		++_count;
	}

	T dequeue()
	{
		throwIfEmpty();

		if (_headIndex >= static_cast<decltype(_headIndex)>(_capacity) )
		{
			_headIndex = 0;
		}

		--_count;

		return _data[_headIndex++];
	}

	bool empty() const
	{
		return (_count == 0);
	}

	std::size_t capacity() const
	{
		return _capacity;
	}

	std::size_t count() const
	{
		return _count;
	}
};

#endif // __CIRCULAR_QUEUE_HPP__