#include "Enemy.h"

//Constructor
Enemy::Enemy(std::string_view name, int maxHealth, int damage, std::vector<std::string> weakness, std::vector<std::string> resistances, int turnValue) :
	m_name{ name },
	m_currentHealth{maxHealth},
	m_maxHealth{maxHealth},
	m_damage{damage},
	m_weakness{weakness},
	m_resistances{resistances},
	m_turnValue{turnValue}
{
}

bool Enemy::isDead() {
	if (m_currentHealth <= 0) {
		return true;
	}
	return false;
}

void Enemy::takeDamage(int damage) { 
	m_currentHealth -= damage; 
}

void Enemy::takeTurn() {
	--m_turnValue;
}