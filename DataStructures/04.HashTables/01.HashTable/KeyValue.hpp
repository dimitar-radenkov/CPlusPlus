#ifndef __KEY_VALUE_HPP__
#define __KEY_VALUE_HPP__

template<typename TKey, typename TValue>
class KeyValue
{
public:

	template<typename URKey, typename URValue>
	KeyValue(URKey&& key, URValue&& value)
	{
		_key = std::forward<URKey>(key);
		_value = std::forward<URValue>(value);
	}

	~KeyValue()
	{}

	const TKey& key() const
	{
		return _key;
	}

	TKey& key()
	{
		return _key;
	}

	const TValue& value() const
	{
		return _value;
	}

	TValue& value()
	{
		return _value;
	}



private:

	TKey _key;
	TValue _value;
};

#endif // !__KEY_VALUE_HPP__


