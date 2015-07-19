#include "BinaryTree.hpp"

int main()
{


	BinaryTree<int> tree(
		1,
		BinaryTree<int>(
			11,
			BinaryTree<int>(111),
			BinaryTree<int>(112)),
		BinaryTree<int>(
			12,
			BinaryTree<int>(121),
			BinaryTree<int>(122))
		);

	tree.traverse();


	return 0;
}