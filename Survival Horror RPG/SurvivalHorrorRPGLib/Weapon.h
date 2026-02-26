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
	Weapon(string newName, int newDamage, int newUpgradeTracker = 1, string newCurrentAmmo = "None"); //Constructor
	string getName(); //Get the name of the weapon
	int getDamage(); //Get the damage value of the weapon
	int getUpgradeTracker(); //Get the current value of the upgrade tracker
	void updateTracker(); //Increment the upgrade tracker
	string getAmmo(); //Get the current ammo type
	void changeAmmo(string newAmmo); //Change the current ammo for the weapon
	//Ammo class?
}; //Weapon

#endif //! WEAPON_H