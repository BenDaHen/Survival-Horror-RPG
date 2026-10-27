#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <string_view>
#include <vector>
#include <iostream>

class Enemy {
private:
	std::string m_name{};
	int m_currentHealth{};
	int m_maxHealth{};
	int m_damage{};
	std::vector<std::string> m_weakness{}; //Array that holds the enemy's weaknesses
	std::vector<std::string> m_resistances{}; //Array that holds the enemy's resistances
	int m_turnValue{}; //Number of turns until the enemy attacks the player

public:
	//Constructor
	Enemy(std::string_view name, int maxHealth, int damage, std::vector<std::string> weakness, std::vector<std::string> resistances, int turnValue);

	std::string getName() const { return m_name; }
	int getCurrentHealth() const { return m_currentHealth; }
	int getMaxHealth() const { return m_maxHealth; }
	bool isDead();
	void takeDamage(int damage);
	void takeTurn();
};//Enemy

#endif