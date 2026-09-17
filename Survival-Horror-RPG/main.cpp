#include <iostream>
#include "newGame.h"
#include "loadGame.h"
#include "Player.h"
#include "Item.h"
#include "Inventory.h"
#include "ItemData.h"

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
	Item test{ Item{itemData[green_herb]} };

	KeyItem keyTest{ KeyItem{keyItemData[armor_key]} };

	Weapon weapon{ Weapon{weaponData[handgun]} };

	Ammo handgunAmmo{ Ammo{ammoData[handgun_bullets]} };
	Ammo shotgunAmmo{ Ammo{ammoData[shotgun_shells]} };

	std::cout << "The " << keyTest.getName() << " is used in " << keyTest.getUseLocation();

	std::cout << "The " << weapon.getName() << " does " << weapon.getDamage() << " damage";

	Inventory playerInventory{"Player's Inventory", 8};

	Inventory itemBox{ "Item Box", 20 };

	playerInventory.add(test);
	playerInventory.add(test);
	playerInventory.add(test);
	playerInventory.add(keyTest);
	playerInventory.add(weapon);
	playerInventory.add(handgunAmmo);
	playerInventory.add(shotgunAmmo);

	std::cout << playerInventory;

	std::cout << "Length: " << playerInventory.getLength() << '\n' << "Capacity: " << playerInventory.getCapacity() << '\n';

	playerInventory.remove(2);

	std::cout << playerInventory;

	std::cout << "Length: " << playerInventory.getLength() << '\n' << "Capacity: " << playerInventory.getCapacity() << '\n';

	playerInventory.transfer(2, itemBox);
	playerInventory.transfer(1, itemBox);

	std::cout << playerInventory;
	std::cout << itemBox;

	handgunAmmo.printCompatibleWeapons();
	shotgunAmmo.printCompatibleWeapons();

	std::cout << test;
	std::cout << keyTest;
	std::cout << weapon;
	std::cout << handgunAmmo;

	return 0;
}