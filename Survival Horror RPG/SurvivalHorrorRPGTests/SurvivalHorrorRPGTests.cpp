#include "pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SurvivalHorrorRPGTests
{
	TEST_CLASS(HealingItemTests)
	{
	public:
		
		TEST_METHOD(TestHealingItemName)
		{
			HealingItem herb = HealingItem("Herb", 1);

			string expected = "Herb";
			string actual = herb.getName();

			Assert::AreEqual(expected, actual);
		}//TestHealingItemName

		TEST_METHOD(TestHealingItemValue)
		{
			HealingItem herb = HealingItem("Herb", 1);

			int expected = 1;
			int actual = herb.getHealValue();

			Assert::AreEqual(expected, actual);
		}//TestHealingItemValue

	}; //HealingItemTests

} //SurvivalHorrorRPGTests
