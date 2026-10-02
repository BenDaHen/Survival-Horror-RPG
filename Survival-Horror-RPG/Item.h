#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <string_view>
#include <array>
#include <iostream>

//Item class
class Item {
protected:
	std::string m_name{}; //All items have a name
	bool m_stackable{}; //Is the item stackable in the inventory

public:
	//Default constructor
	Item() = default;

	//Default virtual destructor
	virtual ~Item() = default;

	//Constructor
	Item(const std::string_view name, const bool stackable);

	std::string_view getName() const { return m_name; } 
	bool isStackable() const { return m_stackable; }

	//Overload printing for the inventory
	virtual void printItem() const;
};

//Key Item class (derives from Item)
class KeyItem final : public Item {
private:
	std::string m_useLocation{};

public:
	//Constructor
	KeyItem(const std::string_view name, const std::string_view useLocation);

	std::string_view getUseLocation() const { return m_useLocation; }

	//Overload printing for the inventory
	void printItem() const override;
};

//Weapon (Item) class 
class Weapon final : public Item {
private:
	int m_damage{};
	int m_level{1};
	int m_ammoCount{};
	int m_maxAmmoCount{};

public:
	//Constructor
	Weapon(const std::string_view name, const int ammoCount, const int maxAmmoCount, const int damage);

	int getDamage() const { return m_damage; }
	int getLevel() const { return m_level; }
	int getAmmo() const { return m_ammoCount; }
	int getMaxAmmo() const { return m_maxAmmoCount; }

	//Overload printing for the inventory
	void printItem() const override;
};

//Ammo (Item) class
class Ammo final : public Item {
private:
	int m_ammoCount{};
	int m_maxAmmoCount{};
	std::array<std::string_view, 1> m_compatibleWeapons{};

public:
	//Constructor
	Ammo(const std::string_view name, const int ammoCount, const int maxAmmoCount, const std::array<std::string_view, 1> compatibleWeapons);

	int getAmmo() const { return m_ammoCount; } //Get the current ammo of a stack
	int getMaxAmmo() const { return m_maxAmmoCount; } //Get the max possible ammo for a stack

	void setAmmo(const int newAmmo); //Set the current ammo of a stack

	void printCompatibleWeapons() const; //Print out what weapons are compatible with the ammo type

	//Overload printing for the inventory
	void printItem() const override;
};

#endif