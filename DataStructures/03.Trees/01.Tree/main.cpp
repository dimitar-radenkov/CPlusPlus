#include "Tree.hpp"

int main()
{
	Tree<int> t(
		1, 
		{ 
			Tree<int>(2, 
				{
					Tree<int>(21),
					Tree<int>(22)
				}),
			Tree<int>(3, 
				{
					Tree<int>(31),
					Tree<int>(32)
				})
		});


	t.traverse(1);

	return 0;
}