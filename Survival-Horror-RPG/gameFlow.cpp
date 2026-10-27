//Game Flow
#include "gameFlow.h"

void createEnemy(std::vector<Enemy*>& enemyVector) {
	Enemy* newEnemy{ new Enemy{enemyData[zombie]} }; //Dynamically allocate an enemy on the stack
	enemyVector.push_back(newEnemy);
}

void printBattleUI() {
	std::cout << "--------------------\n";
	std::cout << "(1) ATTACK\n(2) ITEM\n(3) RUN\n";
	std::cout << "--------------------\n";
}//printBattleUI

//The player attacks an enemy
void playerAttack(Player& player, Inventory& inventory) {
	std::cout << "Which weapon will you use " << player.getName() << "? \n";

	inventory.printInventory();
}//playerAttack

//The player uses an item
void playerItem(Player& player, Inventory& inventory) {
	std::cout << "Which item will you use " << player.getName() << "? \n";

	inventory.printInventory();
}//playerItem

//The player tries to run
bool playerRun() {
	//Some calculation if the player can run
	bool run{ true };

	run = false;
	
	return run;
}//playerRun

void enterBattle(Player& player, Inventory& inventory) {
	std::cout << "You are now in a battle!\n";
	bool battleOngoing{ true };

	//Create a vector to hold the dynamically allocated enemies
	std::vector<Enemy*> enemyvector{};
	createEnemy(enemyvector);
	createEnemy(enemyvector);

	for (auto const enemy : enemyvector) {
		std::cout << "A " << enemy->getName() << " appears!\n";
	}

	//Main battle loop
	while (battleOngoing) {
		int choice{};

		//Input validation (Player Phase)
		while (choice != 1 && choice != 2 && choice != 3) {
			std::cout << "PLAYER PHASE\n";
			std::cout << "--------------------\n";
			std::cout << "What will you do?\n";
			printBattleUI();

			choice = getInput<int>();
			
			std::cout << "You have chosen " << choice << '\n';

			if (choice != 1 && choice != 2 && choice != 3) {
				std::cout << "Invalid input.\n";
			}
		}

		std::cout << "Input validated.\n";

		//Player Action
		switch (choice) {
		//ATTACK
		case(1): 
			std::cout << "You are attacking.\n"; 
			playerAttack(player, inventory);
			break; 
		//ITEM
		case(2): 
			std::cout << "You are using an item.\n"; 
			playerItem(player, inventory);
			break;
		//RUN
		case(3): 
			std::cout << "You are running.\n";
			battleOngoing = playerRun();
			break;
		}

		//Enemy Phase
		std::cout << "ENEMY PHASE\n";
		std::cout << "--------------------\n";

		for (auto enemy : enemyvector) {
			enemy->takeTurn();
		}

	}

	std::cout << "The battle is over!\n";

	//Free memory after the battle
	for (auto enemy : enemyvector) {
		delete enemy;
		enemy = nullptr;
	}
}//enterBattle

void gameFlow() {
	//Create a player
	Player player{ "Chris", 50, 50, 100, 5, 0, 150 };

	//Create an inventory
	Inventory playerInventory{"Player Inventory", 8};

	playerInventory.add({}, green_herb, false);
	playerInventory.add({}, green_herb, false);
	playerInventory.add({}, handgun, false);
	playerInventory.add({}, handgun_bullets_medium, false);
	playerInventory.add({}, armor_key, false);

	std::cout << "Welcome to the game " << player.getName() << '\n';

	enterBattle(player, playerInventory);
}//gameFlow