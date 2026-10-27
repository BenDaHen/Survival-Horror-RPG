#ifndef GAMEFLOW_H
#define GAMEFLOW_H

#include <iostream>

#include "Player.h"
#include "Inventory.h"
#include "Enemy.h"
#include "EnemyData.h"
#include "Input.h"

void createEnemy(std::vector<Enemy*>& enemyVector);
void printBattleUI();
void playerAttack(Player& player, Inventory& inventory);
void enterBattle(Player& player, Inventory& inventory);
void gameFlow();

#endif