#include "Item.h"

enum ItemType {
	green_herb, 
	red_herb, 
	blue_herb,
	max_items
};

enum KeyItemType {
	armor_key, 
	helmet_key, 
	some_key,
	max_key_items
};

enum WeaponType {
	handgun, 
	shotgun,
	grenade_launcher
};

enum AmmoType {
	handgun_bullets_small,
	handgun_bullets_medium,
	shotgun_shells,
	flame_rounds, 
	acid_rounds, 
};

static inline Item itemData[]{
	Item{"Green Herb"},
	Item{"Red Herb"},
	Item{"Blue Herb"}
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
	Ammo{"Shotgun Shells", 5, 30, {"Shotgun"}},
	Ammo{"Flame Rounds", 3, 15, {"Grenade Launcher"}},
	Ammo{"Acid Rounds", 3, 15, {"Grenade Launcher"}},
};