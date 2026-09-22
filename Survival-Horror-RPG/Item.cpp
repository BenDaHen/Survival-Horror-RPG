#include "Item.h"

//Item Constructor
Item::Item(const std::string_view name) :
	m_name{ name }
{
}

//Print out item attributes
void Item::printItem() const {
	std::cout << "Item: " << m_name << '\n';
}

//Key Item Constructor
KeyItem::KeyItem(const std::string_view name, const std::string_view useLocation) :
	Item{ name },
	m_useLocation{ useLocation }
{
}

//Print out key item attributes
void KeyItem::printItem() const {
	std::cout << "Key Item: " << m_name << m_useLocation << '\n';
}

//Weapon Constructor
Weapon::Weapon(const std::string_view name, const int ammoCount, const int maxAmmoCount, const int damage) :
	Item{ name },
	m_ammoCount{ammoCount},
	m_maxAmmoCount{maxAmmoCount},
	m_damage{ damage }
{
}

//Print out weapon attributes
void Weapon::printItem() const {
	std::cout << "Weapon: " << m_name << '\n';
}


//Ammo Constructor
Ammo::Ammo(const std::string_view name, const int ammoCount, const int maxAmmoCount, const std::array<std::string_view, 1> compatibleWeapons) :
	Item{name},
	m_ammoCount{ammoCount},
	m_maxAmmoCount{maxAmmoCount},
	m_compatibleWeapons{compatibleWeapons}
{
}

void Ammo::printCompatibleWeapons() const {
	std::cout << "Compatible weapons for " << m_name << '\n';
	for (auto& weapon : m_compatibleWeapons) {
		std::cout << weapon << '\n';
	}
}

//Print out ammo attributes
void Ammo::printItem() const {
	std::cout << "Ammo: " << m_name << '\n';
}