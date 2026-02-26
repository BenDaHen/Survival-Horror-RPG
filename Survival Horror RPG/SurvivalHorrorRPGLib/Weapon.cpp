//Weapon.cpp

#include "pch.h"
#include "Weapon.h"

Weapon::Weapon(string newName, int newDamage, int newUpgradeTracker, string newCurrentAmmo) {
	name = newName;
	damage = newDamage;
	upgradeTracker = newUpgradeTracker;
	currentAmmo = newCurrentAmmo;
}//Weapon constructor

string Weapon::getName() {
	return name;
}//getName

int Weapon::getDamage() {
	return damage;
}//getDamage

int Weapon::getUpgradeTracker() {
	return upgradeTracker;
}//getUpgradeTracker

void Weapon::updateTracker() {
	upgradeTracker++;
}//updateTracker

string Weapon::getAmmo() {
	return currentAmmo;
} //getAmmo

void Weapon::changeAmmo(string newAmmo) {
	currentAmmo = newAmmo;
}//changeAmmo