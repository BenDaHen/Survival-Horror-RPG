//KeyItem.cpp

#include "pch.h"
#include "KeyItem.h"

KeyItem::KeyItem(string newName, string newInteractLocation) {
	name = newName;
	interactLocation = newInteractLocation;
}//KeyItem Constructor

string KeyItem::getName() {
	return name;
}//getName

string KeyItem::getInteractLocation() {
	return interactLocation;
}//getInteractLocation