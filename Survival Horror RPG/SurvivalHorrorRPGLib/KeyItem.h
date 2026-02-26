//KeyItem.h
#ifndef KEYITEM_H
#define HEYITEM_H

//KeyItem Class
class KeyItem {
private:
	string name;
	string interactLocation;
public:
	KeyItem(string newName, string newInteractLocation);
	string getName();
	string getInteractLocation();
	//Function to use the item

};//KeyItem

#endif //! KEYITEM_H