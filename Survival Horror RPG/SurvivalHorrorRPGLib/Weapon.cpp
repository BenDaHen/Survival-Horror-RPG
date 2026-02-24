//Weapon.cpp

#include "pch.h"
#include "Weapon.h"

string Weapon::getName() {
	return name;
}//getName

int Weapon::getDamage() {
	return damage;
}//getDamage

void Weapon::updateTracker() {
	upgradeTracker++;
}//updateTracker