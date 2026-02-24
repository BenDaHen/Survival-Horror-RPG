//Weapon.h
#ifndef WEAPON_H
#define WEAPON_H

//Weapon class
class Weapon {
private:
	string name;
	int damage;
	int upgradeTracker;
	string currentAmmo; //The type of ammo currently in the weapon

public:
	string getName(); //Get the name of the weapon
	int getDamage(); //Get the damage value of the weapon
	void updateTracker(); //Update the upgrade tracker
	//Ammo class?
}; //Weapon

#endif //! WEAPON_H