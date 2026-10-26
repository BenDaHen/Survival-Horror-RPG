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
void enterBattle();
void gameFlow();

#endif