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

	TEST_CLASS(WeaponTests) {
	public:

		TEST_METHOD(TestWeaponName) {
			Weapon handgun = Weapon("Handgun", 5);

			string expected = "Handgun";
			string actual = handgun.getName();

			Assert::AreEqual(expected, actual);
		} //testWeaponName

		TEST_METHOD(TestWeaponDamage) {
			Weapon handgun = Weapon("Handgun", 5);

			int expected = 5;
			int actual = handgun.getDamage();

			Assert::AreEqual(expected, actual);
		} //testWeaponDamage

		TEST_METHOD(TestWeaponUpgradeTracker) {
			Weapon handgun = Weapon("Handgun", 5);

			int expected = 1;
			int actual = handgun.getUpgradeTracker();

			Assert::AreEqual(expected, actual);
		} //testWeaponUpgradeTracker

		TEST_METHOD(TestWeaponUpgradeTrackerIncrement) {
			Weapon handgun = Weapon("Handgun", 5);
			handgun.updateTracker();

			int expected = 2;
			int actual = handgun.getUpgradeTracker();

			Assert::AreEqual(expected, actual);
		}//testWeaponUpgradeTrackerIncrement

		TEST_METHOD(TestWeaponAmmoType) {
			Weapon handgun = Weapon("Handgun", 5);

			string expected = "None";
			string actual = handgun.getAmmo();

			Assert::AreEqual(expected, actual);
		}//testWeaponAmmoType

		TEST_METHOD(TestWeaponAmmoChange) {
			Weapon handgun = Weapon("Handgun", 5);

			//Change ammo
			handgun.changeAmmo("Regular");

			string expected = "Regular";
			string actual = handgun.getAmmo();

			Assert::AreEqual(expected, actual);
		}//TestWeaponAmmoChange
	};//WeaponTests

} //SurvivalHorrorRPGTests
