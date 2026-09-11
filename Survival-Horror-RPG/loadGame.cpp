#include "loadGame.h"

using json = nlohmann::json;

void loadGame() {
	std::cout << "Loading the game.\n";

	//Open the save file for reading
	std::ifstream save("save.json");

	json data{ json::parse(save) };

	int number{ data["test"] };

	std::cout << number;
}//newGame