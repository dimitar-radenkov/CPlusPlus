#pragma once
#include <thread>

class ThreadGuard
{
	std::thread& t;
public:
	explicit ThreadGuard(std::thread& t) :
		t(t)
	{}
	~ThreadGuard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	//forbid copy ctor
	ThreadGuard(ThreadGuard const&) = delete;

	//forbid assign operator
	ThreadGuard& operator=(ThreadGuard const&) = delete;
};