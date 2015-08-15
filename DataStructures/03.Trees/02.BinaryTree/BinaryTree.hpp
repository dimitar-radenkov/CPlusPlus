#ifndef __BINARY_TREE_HPP__
#define __BINARY_TREE_HPP__

#include <memory>
#include <tuple>
#include <iostream>

template <typename T>
class BinaryTree
{
	T _value{ 0 };
	std::shared_ptr<BinaryTree<T>> _left{ nullptr };
	std::shared_ptr<BinaryTree<T>> _right{ nullptr };

public:

	template <typename UR>
	BinaryTree(UR&& value, 
		std::shared_ptr<BinaryTree<T>> left = nullptr,
		std::shared_ptr<BinaryTree<T>> right = nullptr)
	{
		_value = std::forward<UR>(value);
		_left = left;
		_right = right;
	}

	void traverse(int depth = 1) const
	{
		std::cout << std::string(depth, '-').c_str() << _value << std::endl;

		if (_left)
		{
			_left->traverse(depth + 1);
		}

		if (_right)
		{
			_right->traverse(depth + 1);
		}	
	}
};

#endif //__BINARY_TREE_HPP__


