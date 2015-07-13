#include <iostream>

#include "CircularQueue.hpp"

int main()
{
	CircularQueue<int> queue;

	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);

	auto ss = queue.dequeue();
	auto sss = queue.dequeue();

	queue.enqueue(5);
	queue.enqueue(6);
	queue.enqueue(7);
	queue.enqueue(8);

	ss = queue.dequeue();
	ss = queue.dequeue();
	ss = queue.dequeue();
	ss = queue.dequeue();
	ss = queue.dequeue();
	ss = queue.dequeue();

	return 0;
}