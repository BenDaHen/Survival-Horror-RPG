#include <iostream>
#include "newGame.h"
#include "loadGame.h"

int main() {
	//Title Screen starts here

	std::cout << "SURVIVAL HORROR RPG\n\n";
	std::cout << "(1) NEW GAME\n";
	std::cout << "(2) LOAD GAME\n\n";

	int choice{};
	std::cin >> choice;

	if (choice == 1) {
		newGame();
	}
	else if(choice == 2) {
		loadGame();
	}

	return 0;
}