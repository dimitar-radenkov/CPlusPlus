#include "stdafx.h"
#include "CppUnitTest.h"
#include "../16.CircularQueue/CircularQueue.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDataStructures
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			CircularQueue<int> queue;
			for (int i = 0; i < 10; i++)
			{
				queue.enqueue(i);
			}

			int actual = queue.capacity();
			int expected = 16;

			Assert::AreEqual<int>(actual, expected);
		}

	};
}