#include "Player.h"

//Constructor
Player::Player(const std::string_view name, int currentHealth, int maxHealth, int money, int level, int currentXp, int nextXp) :
	m_name{ name },
	m_currentHealth{ currentHealth },
	m_maxHealth{ maxHealth },
	m_money{ money },
	m_level{ level },
	m_currentXp{ currentXp },
	m_nextXp{ nextXp }
{
}

void Player::levelUp() {
	std::cout << "You leveled up!\n";

	m_currentXp = 0;
	m_nextXp += 50;

	std::cout << "Your health increased by 10!\n";

	m_maxHealth += 10;
	m_currentHealth = m_maxHealth;
}