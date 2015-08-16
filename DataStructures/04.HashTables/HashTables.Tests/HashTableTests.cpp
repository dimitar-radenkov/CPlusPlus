#include "stdafx.h"
#include "CppUnitTest.h"
#include "../04.HashTables/HashTable.hpp"

#include <functional>
#include <exception>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTablesTests
{		
	TEST_CLASS(HashTableTests)
	{
	public:
		
		TEST_METHOD(Add_EmptyHashTable_NoDuplicates_ShouldAddElement)
		{
			HashTable<std::string, int> table;

			table.add("Peter", 5);
			table.add("Maria", 6);
			table.add("George", 4);
			table.add("Kiril", 5);

			int actualSize = table.size();
			int expectedSize = 4;

			Assert::AreEqual<int>(expectedSize, actualSize);
		}

		TEST_METHOD(Check_Capacity_Should_Be_32)
		{
			HashTable<int, int> table;

			for (size_t i = 0; i < 18; i++)
			{
				table.add(i, i);
			}

			int actualSize = table.size();
			int expectedSize = 18;
			Assert::AreEqual<int>(expectedSize, actualSize);

			int actualCapacity = table.capacity();
			int expectedCapacity = 32;
			Assert::AreEqual<int>(expectedCapacity, actualCapacity);
		}

		TEST_METHOD(Add_1000_Elements_Grow_ShouldWorkCorrectly)
		{
			HashTable<int, int> table;

			for (size_t i = 0; i < 1000; i++)
			{
				table.add(i, i);
			}
		
			int actualSize = table.size();
			int expectedSize = 1000;
			Assert::AreEqual<int>(expectedSize, actualSize);			
		}

		TEST_METHOD(Remove_5000_Elements_Grow_ShouldWorkCorrectly)
		{
			HashTable<int, int> table;
			std::vector<int> keys;

			std::size_t count = 5000;
			for (size_t i = 0; i < count; i++)
			{
				table.add(i, i);
				keys.emplace_back(i);
			}

			int actualSize = table.size();
			Assert::AreEqual<int>(count, actualSize);

			for (auto& key : keys)
			{
				table.remove(key);
				--count;

				Assert::AreEqual(count, table.size());
			}
		}

		TEST_METHOD(Count_Empty_Add_Remove_ShouldWorkCorrectly)
		{
			HashTable<std::string, int> table;

			Assert::AreEqual<int>(0, table.size());

			table.add("1", 1);
			table.add("2", 2);
			Assert::AreEqual<int>(2, table.size());

			table.remove("1");
			Assert::AreEqual<int>(1, table.size());

			table.remove("2");
			Assert::AreEqual<int>(0, table.size());
		}

		TEST_METHOD(Get_ExistingElement_ShouldReturnTheValue)
		{
			HashTable<std::string, int> table;	
			table.add("1", 1);
			auto actualValue = table.get("1");

			Assert::AreEqual<int>(1, actualValue);
		}


		TEST_METHOD(Get_NonExistingElement_ShouldThrowException)
		{
			HashTable<std::string, int> table;

			auto functor = [&table]() 
				{
					return table.get("1111");
				};

			Assert::ExpectException<std::exception>(functor);
		}

		
		TEST_METHOD(Indexer_ExistingElement_ShouldReturnTheValue)
		{
			HashTable<std::string, int> table;
			table.add("1", 1);

			auto actualValue = table["1"];

			Assert::AreEqual<int>(1, actualValue);
		}


		TEST_METHOD(Find_ExistingElement_ShouldReturnTrue)
		{
			HashTable<std::string, int> table;
			table.add("1", 1);

			int value = 0;
			auto actualValue = table.tryGet("1", value);

			Assert::IsTrue(actualValue);
		}


		TEST_METHOD(Find_NonExistingElement_ShouldReturnFalse)
		{
			HashTable<std::string, int> table;
			int value = 0;
			auto actualValue = table.tryGet("1", value);

			Assert::IsFalse(actualValue);
		}
	};
}