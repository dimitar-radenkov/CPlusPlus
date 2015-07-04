#include "DoublyLinkedList.hpp"

int main()
{
	DoublyLinkedList<int> list;

	int n = 1;
	list.addLast(n);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	list.addFirst(11);
	list.addFirst(22);

	list.removeLast();
	list.removeFirst();

	list.traverse();

	return 0;
}