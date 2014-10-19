#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;

/* example with lock_guard */
void Bar()
{
	std::lock_guard<std::mutex> guard(mtx);
	// mutex is locked now
}   // mutex is unlocked when lock guard goes out of scope


/* example with unique_lock */
std::unique_lock<std::mutex> Foo()
{
	std::unique_lock<std::mutex> lock(mtx);
	return lock;
	// mutex isn't unlocked here!
}

void FooBar()
{
	auto lock = Foo();
}   // mutex is unlocked when lock goes out of scope


int main()
{

	return 0;
}