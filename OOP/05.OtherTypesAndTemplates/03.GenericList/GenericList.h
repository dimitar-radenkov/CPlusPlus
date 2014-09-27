#pragma once
#include <algorithm>

static const int InitialSize = 4;
static int CurrentCapacity = InitialSize;

template <class T>
class GenericList
{
private:
	int* buffer;
	int count;

	void checkBoundaries(const int index)
	{
		if (index >= this->count ||
			index < 0)
		{
			throw std::exception("index is outside boundries");
		}
	}

	void resize()
	{
		//double buffer size
		int* newbuffer = new T[CurrentCapacity * 2];
		CurrentCapacity *= 2;

		//copy elements to new buffer
		int index = 0;
		std::for_each(this->buffer, 
					  this->buffer + this->count, 
					  [newbuffer, &index](T& item)
					  {
					 	 newbuffer[index] = item;
					 	 ++index;
					  });

		//release old used memory
		delete[] buffer;

		//set new buffer to point to old one
		buffer = newbuffer;
	}

	bool needResize()
	{
		if (this->count == CurrentCapacity)
		{
			return true;
		}

		return false;
	}


public:
	GenericList()
	{
		this->count = 0;
		this->buffer =  new T[InitialSize];
	}

	virtual ~GenericList()
	{	
		delete[] buffer;
	}

	void add(const T item)
	{
		this->buffer[this->count] = item;
		this->count++;

		if (this->needResize())
		{
			this->resize();
		}
	}

	void remove(const T item)
	{
		auto it = std::find(
			this->buffer, 
			this->buffer + this->count, 
			item);

		if (it != this->buffer + this->count)
		{
			int distance = std::distance(it, this->buffer + this->count);
			int index = this->count - distance;

			for (size_t i = index; i < this->count - 1; i++)
			{
				arr[i] = this->buffer[i + 1];
			}

			this->count--;
		}
	}

	void insert(const T item, const int pos)
	{
		int index = pos - 1;
		this->checkBoundaries(index);

		for (int i = this->count; i >= index; i--)
		{
			this->buffer[i] = this->buffer[i - 1];
		}

		this->buffer[index] = item;
		this->count++;

		if (this->needResize())
		{
			this->resize();
		}
	}

	T& operator[](const int index)
	{
		this->checkBoundaries(index);

		return this->buffer[index];
	}

	void clear()
	{
		this->count = 0;
	}

	const bool contains(const T item) const
	{
		auto it = std::find(
			this->buffer, 
			this->buffer + this->count, 
			item);

		if (it != this->buffer + this->count)
		{
			return true;
		}

		return false;
	}

	const int size() const
	{
		return this->count;
	}

	const std::string toString() const
	{
		std::stringstream ss;

		std::for_each(
			this->buffer, 
			this->buffer + count, 
			[&ss](T item)
		{
			ss << "  " << item;
		});

		return ss.str();
	}

	T min() const
	{
		auto it = std::min_element(
			this->buffer, 
			this->buffer + this->count);

		return *it;
	}

	T max() const
	{
		auto it = std::max_element(
			this->buffer, 
			this->buffer + this->count);

		return *it;
	}
};