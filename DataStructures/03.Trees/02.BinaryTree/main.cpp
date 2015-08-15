#include "BinaryTree.hpp"

int main()
{
	BinaryTree<int> tree(1, 
		std::make_shared<BinaryTree<int>>(2), 
		std::make_shared<BinaryTree<int>>(3));

	tree.traverse();
	
	return 0;
}