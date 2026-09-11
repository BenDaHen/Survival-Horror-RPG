#include <iostream>
#include "newGame.h"
#include "loadGame.h"
#include "Player.h"

int main() {
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
	else if(choice == 2) {
		loadGame();
	}

	//Create a player
	Player player { "Chris", 50, 50, 100, 5, 0, 150 };

	std::cout << "Welcome to the game " << player.getName();

	return 0;
}