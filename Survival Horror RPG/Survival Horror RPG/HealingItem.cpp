//HealingItem.cpp

//Includes
#include "HealingItem.h"

HealingItem::HealingItem(string newName, int newHealValue) {
	name = newName;
	healValue = newHealValue;
} //HealingItem Constructor

string HealingItem::getName() {
	return name;
} //getName

int HealingItem::useHeal() {
	return healValue;
} //useHeal