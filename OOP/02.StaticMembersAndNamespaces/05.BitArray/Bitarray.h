#pragma once
#include <stdint.h>
#include <algorithm>
#include <string>

class Bitarray
{
private:
	int bitsCount;
	bool arr[];

public:
	Bitarray(int bitsCount)
	{
		this->bitsCount = bitsCount;
		this->arr[bitsCount];

		for (size_t i = 0; i < bitsCount; i++)
		{
			this->arr[i] = false;
		}
	}

	virtual ~Bitarray()
	{}

	bool& operator[](int index)
	{
		return this->arr[index];
	}

	std::string toString()
	{
		//will NOT work with big numbers
		uint64_t number = 0;
		for (size_t i = 0; i < this->bitsCount; ++i)
		{
			if (this->arr[i])
			{
				number += std::pow(2, i);
			}
		}

		return std::to_string(number);
	}
};

