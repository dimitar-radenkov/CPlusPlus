#pragma once
#include <memory>
#include <exception>

template <typename T>
class List
{
public:
	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		T* p;
	public:
		iterator() {};
		iterator(T* x) :p(x) {}
		iterator(const iterator& mit) : p(mit.p) {}
		iterator& operator++() { ++p; return *this; }
		iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }
		bool operator==(const iterator& rhs) { return p == rhs.p; }
		bool operator!=(const iterator& rhs) { return p != rhs.p; }
		friend bool operator<(const iterator& lhs, const iterator& rhs) { return &rhs > &lhs; }
		friend bool operator>(const iterator& lhs, const iterator& rhs) { return &rhs < &lhs; }
		T& operator*() { return *p; }
	};

public:

	List()
	{
		_innerBuffer.reset(new T[InitialSize]);
	}

	List(std::initializer_list<T> iniList)
		: List()
	{
		for (auto& item : iniList)
		{
			add(item);
		}
	}

	~List()
	{
	}

	template<typename... Args>
	void add(Args&&... args)
	{
		if (_size >= _capacity)
		{
			_grow();
		}

		T* p = &_innerBuffer.get()[_size];
		::new ((void*)p) T(std::forward<Args>(args)...);

		++_size;
	}

	void remove(const T& item)
	{
		int index = -1;
		for (size_t i = 0; i < _size; i++)
		{
			if (item == _innerBuffer.get()[i])
			{
				index = i;
			}
		}

		//move elemenemts
		if (index != -1)
		{
			--_size;

			std::memcpy(
				&_innerBuffer.get()[index],
				&_innerBuffer.get()[index + 1],
				(_size - index) * sizeof(T));
		}
		else
		{
			throw std::exception("item not found");
		}
	}

	void clear()
	{
		_size = 0;
		_innerBuffer.reset(new T[_capacity]);
	}

	void reserve(int count)
	{
		_innerBuffer.reset(new T[count]);
		_capacity = count;
	}

	const T& operator[](int index) const
	{
		return _innerBuffer.get()[index];
	}

	T& operator[](int index)
	{
		return _innerBuffer.get()[index];
	}

	std::size_t size() const noexcept
	{
		return _size;
	}

	std::size_t capacity() const noexcept
	{
		return _capacity;
	}

	iterator begin() const noexcept
	{
		return iterator(&_innerBuffer.get()[0]);
	}

	iterator end() const noexcept
	{
		return iterator(&_innerBuffer.get()[_size]);
	} 

private:
	constexpr static int InitialSize{ 2 };

	std::size_t _size{ 0 };
	std::size_t _capacity{ InitialSize };

	std::unique_ptr<T[]> _innerBuffer;

	void _grow()
	{
		_capacity *= 2;

		std::unique_ptr<T[]> newArr(new T[_capacity]);
		std::memcpy(newArr.get(), _innerBuffer.get(), sizeof(T) * _size);
		_innerBuffer = std::move(newArr);
	}
};

