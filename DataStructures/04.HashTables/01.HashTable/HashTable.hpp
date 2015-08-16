#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__

#include <memory>
#include <list>
#include <algorithm>
#include <vector>

#include "KeyValue.hpp"

template<typename TKey, typename TValue>
class HashTable
{
	const static int INITIAL_CAPACITY = 16;
	const float LOAD_FACTOR = .75;

public:

	HashTable(int capacity = INITIAL_CAPACITY)
	{
		_slots.reset(new std::list<KeyValue<TKey, TValue>>[capacity]);
		_capacity = capacity;
	}

	~HashTable()
	{		
	}

	template<typename URKey, typename URValue>
	void add(URKey&& key, URValue&& value)
	{
		TKey currentKey = std::forward<URKey>(key);

		growIfNeeded();
		int slotNumber = findSlotNumber(currentKey);
		auto& elements = _slots[slotNumber];

		auto it = std::find_if(elements.begin(), elements.end(),
			[&currentKey](const KeyValue<TKey, TValue> kv)
		{
			return kv.key() == currentKey;
		});

		if (it != elements.end())
		{
			throw std::exception("key already exists");
		}

		_slots[slotNumber].emplace_back(KeyValue<TKey, TValue>(key, value));
		++_count;
	}


	template<typename URKey>
	bool remove(URKey&& key)
	{
		auto currentKey = std::forward<URKey>(key);

		int slotNumber = findSlotNumber(currentKey);
		auto& elements = _slots[slotNumber];

		auto it = std::find_if(elements.begin(), elements.end(),
			[&currentKey](const KeyValue<TKey, TValue> kv)
			{
				return kv.key() == currentKey;
			});

		if (it != elements.end())
		{
			elements.erase(it);
			--_count;
			return true;
		}

		return false;
	}


	void clear()
	{
		_slots.reset(new std::list<KeyValue<TKey, TValue>>[capacity]);
		_count = 0;
	}


	template<typename URKey>
	const KeyValue<TKey, TValue>& find(URKey&& key)
	{
		auto currentKey = std::forward<URKey>(key);

		int slotNumber = findSlotNumber(currentKey);
		auto& elements = _slots[slotNumber];

		auto it = std::find_if(elements.begin(), elements.end(),
			[&currentKey](const KeyValue<TKey, TValue> kv)
			{
				return kv.key() == currentKey;
			});

		if (it != elements.end())
		{
			return *it;
		}

		throw std::exception("key not found");	
	}


	template<typename URKey>
	const TValue& get(URKey&& key)
	{
		auto& element = find(key);
		return element.value();
	}


	template<typename URKey>
	bool tryGet(URKey&& key, TValue& value)
	{
		try
		{
			value = get(key);
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}


	std::vector<TKey> keys()
	{
		std::vector<TKey> keys;
		for (size_t i = 0; i < _capacity; i++)
		{
			auto elements = _slots[i];
			for (auto& e : elements)
			{
				keys.emplace_back(e.key());
			}
		}

		return keys;
	}

	
	std::vector<TValue> values()
	{
		std::vector<TValue> values;
		for (size_t i = 0; i < _capacity; i++)
		{
			auto elements = _slots[i];
			for (auto& e : elements)
			{
				values.emplace_back(e.value());
			}
		}

		return values;
	}


	TValue operator[](const TKey& key) const
	{
		int slotNumber = findSlotNumber(key);
		auto& elements = _slots[slotNumber];

		auto& it = std::find_if(elements.begin(), elements.end(),
			[&key](auto& e) { return e.key() == key; });

		if (it != elements.end())
		{
			return it->value();
		}
		
		return TValue{0};
	}


	TValue& operator[](const TKey& key)
	{
		int slotNumber = findSlotNumber(key);
		auto& elements = _slots[slotNumber];

		auto& it = std::find_if(elements.begin(), elements.end(),
			[&key](auto& e) { return e.key() == key; });

		if (it != elements.end())
		{
			return it->value();
		}
		else
		{
			add(key, TValue{});
			return const_cast<TValue&>(find(key).value());
		}
	}


	const std::size_t size() const
	{
		return _count;
	}


	const std::size_t capacity() const
	{
		return _capacity;
	}

private:

	void growIfNeeded()
	{
		if ((_count + 1) / _capacity > LOAD_FACTOR)
		{
			grow();
		}
	}

	void grow()
	{
		auto tempSlots = std::move(_slots);
		auto tempSize = _capacity;
		_count = 0;

		_slots.reset(new std::list<KeyValue<TKey, TValue>>[_capacity * 2]);
		_capacity *= 2;

		for (size_t i = 0; i < tempSize; i++)
		{
			auto& elements = tempSlots[i];
			for (auto& e : elements)
			{
				add(e.key(), e.value());
			}
		}
	}

	int findSlotNumber(const TKey& key)
	{
		std::hash<TKey> hash_fn;
		int hash = hash_fn(key) % _capacity;

		return abs(hash);
	}


	std::unique_ptr < std::list<KeyValue<TKey, TValue>>[] > _slots;
	std::size_t _count{ 0 };
	std::size_t _capacity{ 0 };

};

#endif // !__HASH_TABLE_HPP__
