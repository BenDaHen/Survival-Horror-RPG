#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <string_view>

//Item class
class Item {
protected: 
	std::string m_name{}; //All items have a name

public:
	//Default constructor
	Item() = default;

	//Constructor
	Item(const std::string_view name);

	std::string_view getName() const { return m_name; }
};

//Key Item class (derives from Item)
class KeyItem final : public Item {
private:
	std::string m_useLocation{};

public:
	//Constructor
	KeyItem(const std::string_view name, const std::string_view useLocation);

	std::string_view getUseLocation() const { return m_useLocation; }
};

//Weapon (Item) class 
class Weapon final : public Item {
private:
	int m_damage{};

public:
	//Constructor
	Weapon(const std::string_view name, const int damage);

	int getDamage() const { return m_damage; }
};

#endif