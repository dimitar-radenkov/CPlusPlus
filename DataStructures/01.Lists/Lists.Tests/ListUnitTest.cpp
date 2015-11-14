#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\3.List (ResizableArray)\List.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListsTests
{		
	TEST_CLASS(ListUnitTest)
	{
	public:
		
		TEST_METHOD(InitialCapacityMustBeTwo)
		{
			List<int> list;
			
			Assert::AreEqual<int>(2, list.capacity());
		}

		TEST_METHOD(InitialSizeMustBeZero)
		{
			List<int> list;

			Assert::AreEqual<int>(0, list.size());
		}

		TEST_METHOD(AddHundredItemMustWorkProperly)
		{
			List<int> list;

			std::size_t count = 100;
			for (size_t i = 0; i < count; i++)
			{
				list.add(i);
			}

			//size must be 100
			Assert::AreEqual<int>(count, list.size());
			//capacity must be 128
			Assert::AreEqual<int>(128, list.capacity());

			for (size_t i = 0; i < count; i++)
			{
				Assert::AreEqual<int>(i, list[i]);
			}
		}

		TEST_METHOD(ChangeValuesAtIndexMustBeTheSame)
		{
			List<int> list;

			size_t count = 100;
			for (size_t i = 0; i < count; i++)
			{
				list.add(i);
			}

			//set values at following indexes
			int value = 999;
			std::vector<int> indexes{ 10,20,40,50,60 };
			for (const auto& i : indexes)
			{
				list[i] = value;
			}

			//check values
			for (const auto& i : indexes)
			{
				Assert::AreEqual<int>(value, list[i]);
			}
		}

		TEST_METHOD(IteratorsMustWorkCorrectly)
		{
			List<int> list{ 1,2,3,4,5,6,7,8,9,10 };

			//check iterator increment
			List<int>::iterator itList = list.begin();
			for (size_t i = 0; i < list.size(); ++i, ++itList)
			{
				Assert::AreEqual<int>(*itList, list[i]);
			}

			//check for end() iterator
			auto itNumber = 
				std::find(list.begin(), list.end(), 999);

			bool areEqual = itNumber == list.end();
			Assert::AreEqual<bool>(true, areEqual);
		}

		TEST_METHOD(ClearMustWorkCorrectly)
		{
			List<int> list{ 1,2,3,4,5,6,7,8,9,10 };
			list.clear();

			Assert::AreEqual<int>(0, list.size());
		}

		TEST_METHOD(ReserveMustWorkCorrectly)
		{
			List<int> list;
			list.reserve(1000);

			Assert::AreEqual<int>(1000, list.capacity());
		}

		TEST_METHOD(RemoveMustWorkCorrectly)
		{
			List<int> list{ 1,2,3,4,5,6,7,8,9 };

			//remove several
			list.remove(1);
			list.remove(5);
			list.remove(9);			

			std::string res;
			for (const auto& i : list)
			{		
				res += std::to_string(i) + ", ";
			}

			Assert::AreEqual<int>(6, list.size());
			Assert::AreEqual<std::string>("2, 3, 4, 6, 7, 8, ", res);


			//remove rest
			list.remove(2);
			list.remove(3);
			list.remove(4);
			list.remove(6);
			list.remove(7);
			list.remove(8);

			res.clear();
			for (const auto& i : list)
			{
				res += std::to_string(i) + ", ";
			}

			Assert::AreEqual<int>(0, list.size());
			Assert::AreEqual<std::string>("", res);

			list.add(999);
			Assert::AreEqual<int>(1, list.size());
			Assert::AreEqual<int>(999, list[0]);
			Assert::AreEqual<int>(999, *list.begin());
		}

		TEST_METHOD(BeginAndEndIteratorMustBeEqualIfListIsEmpty)
		{
			List<int> list;

			//check for end() iterator
			auto itBegin = list.begin();
			auto itEnd = list.end();

			bool areEqual = itBegin == itEnd;
			Assert::AreEqual<bool>(true, areEqual);
		}
	};
}