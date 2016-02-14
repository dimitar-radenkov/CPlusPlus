#include "stdafx.h"
#include "CppUnitTest.h"

#include <chrono>
#include <thread>

#include "../Stopwatch/Stopwatch.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UtilsTests
{		
	TEST_CLASS(StopwatchTests)
	{
	public:
		
		TEST_METHOD(Measure_Two_Second_Should_Return_2s)
		{
			const uint64_t expectedDelay = 2;

			Stopwatch<std::chrono::system_clock> stopwatch;
			stopwatch.start();

			std::this_thread::sleep_for(std::chrono::seconds(expectedDelay));
			stopwatch.stop();

			const auto elapsed = stopwatch.elapsed<std::chrono::seconds>();

			Assert::AreEqual<uint64_t>(expectedDelay, elapsed.count());
		}

		TEST_METHOD(Measure_When_Not_Started_Should_Return_0)
		{
			Stopwatch<std::chrono::system_clock> stopwatch;			
			std::this_thread::sleep_for(std::chrono::seconds(1));

			stopwatch.stop();
			const auto elapsed = stopwatch.elapsed<std::chrono::seconds>();

			Assert::AreEqual<uint64_t>(0, elapsed.count());
		}

		TEST_METHOD(Measure_When_Not_Stopped_Should_Return_Correct)
		{
			Stopwatch<std::chrono::system_clock> stopwatch;

			stopwatch.start();
			std::this_thread::sleep_for(std::chrono::seconds(1));

			const auto elapsed = stopwatch.elapsed<std::chrono::seconds>();

			Assert::AreEqual<uint64_t>(0, elapsed.count());
		}
	};
}