//HealingItem.h
#ifndef HEALINGITEM_H
#define HEALINGITEM_H

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
	int getHealValue(); //Get the heal value of the item
}; //HealingItem

#endif // HEALINGITEM_H