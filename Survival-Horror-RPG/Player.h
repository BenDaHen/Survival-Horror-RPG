#ifndef PLAYER_H //Header Guard
#define PLAYER_H

#include <iostream>
#include <string>
#include <string_view>

class Player {
private:
	std::string m_name{}; //Player name never changes
	int m_currentHealth{};
	int m_maxHealth{};
	int m_money{};
	int m_level{};
	int m_currentXp{};
	int m_nextXp{};

public:
	//Constructor
	Player(const std::string_view name, int currentHealth, int maxHealth, int money, int level, int currentXp, int nextXp);

	std::string getName() const { return m_name; }

	void levelUp();
};

#endif