#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>
#include <memory>
#include <iostream>

template<typename T>
class Tree
{
	T _value{ 0 };
	std::vector<std::shared_ptr<Tree<T>>> _children;

public:

	template <typename UR>
	Tree(UR&& value, std::initializer_list<Tree<T>>&& initList = {})
	{
		_value = std::forward<T>(value);

		for (auto& li : initList)
		{
			_children.emplace_back(std::make_shared<Tree<T>>(li));
		}
	}
	 
	T& value()
	{
		return _value;
	}


	template <typename UR>
	void value(UR&& value)
	{
		_value = std::forward<T>(value);
	}


	std::vector<std::shared_ptr<Tree<T>>>& children() const
	{
		return _children;
	}

	void traverse(int depth) const
	{
		std::string pre(depth, '-');
		std::cout << pre.c_str() << _value << std::endl;

		for (auto &t : _children)
		{	
			t->traverse(depth + 1);
		}
	}
};

#endif // __TREE_HPP__
