//HealingItem.h
#ifndef HEALINGITEM_H
#define HEALINGITEM_H

//Includes
#include <iostream>
#include <string>
using namespace std;

//HealingItem Class
class HealingItem {
	//Members
private:
	string name;
	int healValue;

	//Function Prototypes
public:
	HealingItem(string newName, int newHealValue); //Healing Item constructor
	string getName(); //Get the name of the item
	int useHeal(); //Use the specified healing item
}; //HealingItem

#endif // HEALINGITEM_H