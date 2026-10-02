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

	KeyItem keyTest{ KeyItem{keyItemData[armor_key]} };

	Weapon weapon{ Weapon{weaponData[handgun]} };

	Ammo handgunAmmoSmall{ Ammo{ammoData[handgun_bullets_small]} };
	Ammo handgunAmmoMedium{ Ammo{ammoData[handgun_bullets_medium]} };
	Ammo handgunAmmoMax{ Ammo{ammoData[handgun_bullets_max]} };
	Ammo shotgunAmmo{ Ammo{ammoData[shotgun_shells]} };

	std::cout << "Item Getters: \n\n";

	std::cout << "The " << keyTest.getName() << " is used in " << keyTest.getUseLocation();

	std::cout << "The " << weapon.getName() << " does " << weapon.getDamage() << " damage";

	Inventory playerInventory{ "Player's Inventory", 8 };

	Inventory itemBox{ "Item Box", 20 };

	//Test that items can be added to the inventory

	std::cout << "Adding items to the inventory: \n\n";

	playerInventory.add(test);
	playerInventory.add(test);
	playerInventory.add(test);
	playerInventory.add(keyTest);
	playerInventory.add(weapon);
	playerInventory.add(handgunAmmoSmall);
	playerInventory.add(handgunAmmoSmall);
	//playerInventory.add(handgunAmmoMax);

	std::cout << "Printing the inventory: \n\n";

	playerInventory.printInventory();

	std::cout << "Length: " << playerInventory.getLength() << '\n' << "Capacity: " << playerInventory.getCapacity() << '\n';

	std::cout << "Removing an item from the inventory: \n\n";

	playerInventory.remove(2);

	playerInventory.printInventory();

	std::cout << "Length: " << playerInventory.getLength() << '\n' << "Capacity: " << playerInventory.getCapacity() << '\n';

	std::cout << "Transfering items between two inventories: \n\n";

	playerInventory.transfer(2, itemBox);
	playerInventory.transfer(1, itemBox);

	playerInventory.printInventory();
	itemBox.printInventory();

	std::cout << "Stacking items in an inventory: \n\n";

	playerInventory.stackItems();
	playerInventory.printInventory();

	playerInventory.stackItems();
	playerInventory.printInventory();

	//No more stacking possible here
	playerInventory.stackItems();

	itemBox.add(shotgunAmmo);
	itemBox.add(shotgunAmmo);
	itemBox.add(shotgunAmmo);

	itemBox.printInventory();

	itemBox.stackItems();

	itemBox.printInventory();
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