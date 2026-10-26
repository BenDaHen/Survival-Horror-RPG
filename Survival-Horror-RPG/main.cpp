#include <iostream>
#include <cassert>
#include <memory> //For std::unique_ptr

#include "newGame.h"
#include "loadGame.h"
#include "Player.h"
#include "Item.h"
#include "Inventory.h" //Item data is included with the inventory
#include "gameFlow.h"

//Testing
void testing() {
	//Items on the stack
	//Item herb{ itemData[green_herb] };

	//KeyItem armorKey{ keyItemData[armor_key] };

	//Weapon handgunItem{ weaponData[handgun] };

	//Ammo handgunAmmoSmall{ ammoData[handgun_bullets_small] };
	//Ammo handgunAmmoMedium{ ammoData[handgun_bullets_medium] };
	//Ammo handgunAmmoMax{ ammoData[handgun_bullets_max] };
	//Ammo shotgunAmmo{ ammoData[shotgun_shells] };

	//std::cout << "Item Getters: \n\n";

	//std::cout << "The " << armorKey.getName() << " is used in " << armorKey.getUseLocation();

	//std::cout << "The " << handgunItem.getName() << " does " << handgunItem.getDamage() << " damage";

	Inventory playerInventory{ "Player's Inventory", 8 };

	Inventory itemBox{ "Item Box", 20 };

	//Test that items can be added to the inventory
	std::cout << "Adding items to the inventory: \n\n";

	playerInventory.add({}, green_herb, false); //Create a new Herb
	playerInventory.add({}, green_herb, false); //Create a new Herb
	playerInventory.add({}, green_herb, false); //Create a new Herb
	//playerInventory.add({}, red_herb, false);
	//playerInventory.add({}, blue_herb, false);
	playerInventory.add({}, armor_key, false);
	playerInventory.add({}, handgun_bullets_small, false);
	playerInventory.add({}, handgun_bullets_medium, false);
	playerInventory.add({}, handgun, false);
	//playerInventory.add(handgunAmmoMax);

	std::cout << "Printing the inventory: \n\n";

	playerInventory.printInventory();

	std::cout << "Length: " << playerInventory.getLength() << '\n' << "Capacity: " << playerInventory.getCapacity() << '\n';

	std::cout << "Removing an item from the inventory: \n\n";

	playerInventory.remove(2, false);

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

	itemBox.add({}, shotgun_shells, false);
	itemBox.add({}, shotgun_shells, false);
	itemBox.add({}, shotgun_shells, false);

	itemBox.printInventory();

	itemBox.stackItems();
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
		gameFlow();
	}
	else if (choice == 2) {
		loadGame();
		gameFlow();
	}
}//titleScreen

int main() {
//Testing Block for Debugging
#define TESTING
#ifdef TESTING
	testing();
#endif

	std::cout << "Main here";
	gameFlow();
	//titleScreen(); //Skip title screen

	return 0;
}