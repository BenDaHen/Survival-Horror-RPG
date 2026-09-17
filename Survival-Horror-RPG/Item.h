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

public:
	//Default constructor
	Item() = default;

	//Constructor
	Item(const std::string_view name);

	std::string_view getName() const { return m_name; } 

	//Overload output operator
	friend std::ostream& operator<<(std::ostream& out, Item& item);
};

//Key Item class (derives from Item)
class KeyItem final : public Item {
private:
	std::string m_useLocation{};

public:
	//Constructor
	KeyItem(const std::string_view name, const std::string_view useLocation);

	std::string_view getUseLocation() const { return m_useLocation; }

	//Overload output operator
	friend std::ostream& operator<<(std::ostream& out, KeyItem& item);
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

	//Overload output operator
	friend std::ostream& operator<<(std::ostream& out, Weapon& item);
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

	void printCompatibleWeapons() const;

	//Overload output operator
	friend std::ostream& operator<<(std::ostream& out, Ammo& item);
};

#endif