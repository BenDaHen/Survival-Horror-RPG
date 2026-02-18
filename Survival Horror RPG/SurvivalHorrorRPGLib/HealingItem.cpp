//HealingItem.cpp

//Includes (Note: pch.h comes first for every .cpp file, place common includes in pch.h)
#include "pch.h"
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