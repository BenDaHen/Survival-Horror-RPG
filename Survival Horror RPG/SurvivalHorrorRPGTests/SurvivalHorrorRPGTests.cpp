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
	}; //HealingItemTests
} //SurvivalHorrorRPGTests
