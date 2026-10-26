#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <limits>

template <typename T>
T getInput() {
	T choice{};

	while (true) {
		std::cout << "Enter input for type " << typeid(choice).name() << ":\n";
		std::cin >> choice;

		//Validate that input was the requested type
		if (!std::cin) {
			std::cin.clear(); //Return to normal operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clear extra input
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clear extra input
		return choice;
	}
}//getPlayerChoice

#endif