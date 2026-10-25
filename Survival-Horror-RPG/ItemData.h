#ifndef ITEMDATA_H
#define ITEMDATA_H

#include "Item.h"

enum ItemType {
	//Standard Items (0 - 2)
	green_herb,
	red_herb,
	blue_herb,

	//Key Items (3 - 5)
	armor_key,
	helmet_key,
	some_key,

	//Weapons (6 - 8)
	handgun,
	shotgun,
	grenade_launcher,

	//Ammo (9 - 14)
	handgun_bullets_small,
	handgun_bullets_medium,
	handgun_bullets_max,
	shotgun_shells,
	flame_rounds,
	acid_rounds,

	max_items, //15
};

static inline Item itemData[]{
	Item{"Green Herb", false},
	Item{"Red Herb", false},
	Item{"Blue Herb", false}
};

static inline KeyItem keyItemData[]{
	KeyItem{"Armor Key", "Room 1"},
	KeyItem{"Helmet Key", "Room 2"},
	KeyItem{"Some Key", "Room 3"}
};

static inline Weapon weaponData[]{
	Weapon{"Handgun", 10, 10, 10},
	Weapon{"Shotgun", 5, 5, 50},
	Weapon{"Grenade Launcher", 10, 10, 40}
};

static inline Ammo ammoData[]{
	Ammo{"Handgun Bullets", 5, 60, {"Handgun"}},
	Ammo{"Handgun Bullets", 15, 60, {"Handgun"}},
	Ammo{"Handgun Bullets", 60, 60, {"Handgun"}},
	Ammo{"Shotgun Shells", 5, 30, {"Shotgun"}},
	Ammo{"Flame Rounds", 3, 15, {"Grenade Launcher"}},
	Ammo{"Acid Rounds", 3, 15, {"Grenade Launcher"}},
};

#endif