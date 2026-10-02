#include <iostream>
#include <cassert>

#include "newGame.h"
#include "loadGame.h"
#include "Player.h"
#include "Item.h"
#include "Inventory.h"
#include "ItemData.h"

//Testing
void testing() {
	Item test{ Item{itemData[green_herb]} };

	//Item Class Tests
	std::cout << "Testing Item Class... ";
	assert(test.getName() == "Green Herb");
	assert(!test.isStackable());
	std::cout << "SUCCESS\n";

	KeyItem keyTest{ KeyItem{keyItemData[armor_key]} };

	//KeyItem Class Tests
	std::cout << "Testing Key Item Class... ";
	assert(keyTest.getName() == "Armor Key");
	assert(!keyTest.isStackable());
	assert(keyTest.getUseLocation() == "Room 1");
	std::cout << "SUCCESS\n";

	Weapon weapon{ Weapon{weaponData[handgun]} };

	Ammo handgunAmmoSmall{ Ammo{ammoData[handgun_bullets_small]} };
	Ammo handgunAmmoMedium{ Ammo{ammoData[handgun_bullets_medium]} };
	Ammo handgunAmmoMax{ Ammo{ammoData[handgun_bullets_max]} };
	Ammo shotgunAmmo{ Ammo{ammoData[shotgun_shells]} };

	std::cout << "The " << keyTest.getName() << " is used in " << keyTest.getUseLocation();

	std::cout << "The " << weapon.getName() << " does " << weapon.getDamage() << " damage";

	Inventory playerInventory{ "Player's Inventory", 8 };

	Inventory itemBox{ "Item Box", 20 };

	//Test that items can be added to the inventory

	playerInventory.add(test);
	playerInventory.add(test);
	playerInventory.add(test);
	playerInventory.add(keyTest);
	playerInventory.add(weapon);
	playerInventory.add(handgunAmmoSmall);
	playerInventory.add(handgunAmmoMedium);
	playerInventory.add(handgunAmmoMax);

	playerInventory.printInventory();

	std::cout << "Length: " << playerInventory.getLength() << '\n' << "Capacity: " << playerInventory.getCapacity() << '\n';

	playerInventory.remove(2);

	playerInventory.printInventory();

	std::cout << "Length: " << playerInventory.getLength() << '\n' << "Capacity: " << playerInventory.getCapacity() << '\n';

	playerInventory.transfer(2, itemBox);
	playerInventory.transfer(1, itemBox);

	playerInventory.printInventory();
	itemBox.printInventory();

	playerInventory.stackItems();
	playerInventory.printInventory();

	playerInventory.stackItems();
	playerInventory.printInventory();

	//No more stacking possible here
	playerInventory.stackItems();
}//testing

void titleScreen() {
	//Title Screen starts here
	std::cout << "SURVIVAL HORROR RPG\n\n";
	std::cout << "(1) NEW GAME\n";
	std::cout << "(2) LOAD GAME\n";
	std::cout << "(3) Skip\n";

	int choice{};
	std::cin >> choice;

	if (choice == 1) {
		newGame();
	}
	else if (choice == 2) {
		loadGame();
	}

	//Create a player
	Player player{ "Chris", 50, 50, 100, 5, 0, 150 };

	std::cout << "Welcome to the game " << player.getName();
}

int main() {
//Testing Block for Debugging
#define TESTING
#ifdef TESTING
	testing();
#endif

	std::cout << "Main here";

	return 0;
}