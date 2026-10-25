#ifndef ENEMYDATA_H
#define ENEMYDATA_H

#include "Enemy.h"

enum EnemyType {
	zombie,
	big_zombie,

	max_enemies, //2
};

static inline Enemy enemyData[]{
	Enemy{"Zombie", 20, 5, {"Handgun"}, {"Shotgun"}, 3},
	Enemy{"Big Zombie", 50, 10, {"Shotgun"}, {"Handgun"}, 3}
};

#endif