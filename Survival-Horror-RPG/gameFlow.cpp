//Game Flow

#include "gameFlow.h"
#include "Player.h"
#include "Inventory.h"
#include "Enemy.h"
#include "EnemyData.h"

void createEnemy(std::vector<Enemy*>& enemyVector) {
	Enemy* newEnemy{ new Enemy{enemyData[zombie]} }; //Dynamically allocate an enemy on the stack
	enemyVector.push_back(newEnemy);
}

void printBattleUI() {
	std::cout << "--------------------\n";
	std::cout << "ATTACK\nITEM\nRUN\n";
	std::cout << "--------------------\n";
}//printBattleUI

void enterBattle() {
	std::cout << "You are now in a battle!\n";

	std::vector<Enemy*> enemyvector{};
	createEnemy(enemyvector);
	createEnemy(enemyvector);

	for (auto const enemy : enemyvector) {
		std::cout << "A " << enemy->getName() << " appears!\n";
	}

	std::cout << "What will you do?\n";

	printBattleUI();

	//Get the player's choice here and do what needs to be done

	//Free memory
	for (auto enemy : enemyvector) {
		delete enemy;
	}
}//enterBattle

void gameFlow() {
	//Create a player
	Player player{ "Chris", 50, 50, 100, 5, 0, 150 };

	std::cout << "Welcome to the game " << player.getName() << '\n';

	enterBattle();
}//gameFlow