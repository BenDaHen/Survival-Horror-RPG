#include "newGame.h"

using json = nlohmann::json;

void newGame() {
	std::cout << "Starting a new game.\n";

	std::cout << "Creating save data...\n";

	//Create a save file
	std::ofstream save("save.json");

	//If the file could not be opened
	if (!save) {
		// Print an error and exit
		std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
		return;
	}

	//Create the .json format
	json j{ 
		{
			{"test", 67}
		} 
	};

	//Write a line into the file
	save << j;

	std::cout << "Save data created.\n";

	//The file will automatically be closed when save goes out of scope
}//newGame