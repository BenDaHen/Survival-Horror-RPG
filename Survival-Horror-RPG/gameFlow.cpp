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

void enterBattle() {
	std::cout << "You are now in a battle!\n";

	//Create a vector to hold the dynamically allocated enemies
	std::vector<Enemy*> enemyvector{};
	createEnemy(enemyvector);
	createEnemy(enemyvector);

	for (auto const enemy : enemyvector) {
		std::cout << "A " << enemy->getName() << " appears!\n";
	}

	//Main battle loop
	while (true) {
		std::cout << "What will you do?\n";

		printBattleUI();

		int choice{};

		//Input validation
		while (choice != 1 && choice != 2 && choice != 3) {
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
			break; 
		//ITEM
		case(2): 
			std::cout << "You are using an item.\n"; 
			break;
		//RUN
		case(3): 
			std::cout << "You are running.\n"; 
			break;
		}

	}

	//Free memory
	for (auto enemy : enemyvector) {
		delete enemy;
		enemy = nullptr;
	}
}//enterBattle

void gameFlow() {
	//Create a player
	Player player{ "Chris", 50, 50, 100, 5, 0, 150 };

	std::cout << "Welcome to the game " << player.getName() << '\n';

	enterBattle();
}//gameFlow