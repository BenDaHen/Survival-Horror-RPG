#include "Item.h"

//Item Constructor
Item::Item(const std::string_view name, const bool stackable) :
	m_name{ name },
	m_stackable{stackable}
{
}

//Print out item attributes
void Item::printItem() const {
	std::cout << m_name << '\n';
}

//Key Item Constructor
KeyItem::KeyItem(const std::string_view name, const std::string_view useLocation) :
	Item{ name, false }, //All key items are not stackable
	m_useLocation{ useLocation }
{
}

//Print out key item attributes
void KeyItem::printItem() const {
	std::cout << m_name << '\n';
}

//Weapon Constructor
Weapon::Weapon(const std::string_view name, const int ammoCount, const int maxAmmoCount, const int damage) :
	Item{ name, false }, //All weapons are not stackable
	m_ammoCount{ammoCount},
	m_maxAmmoCount{maxAmmoCount},
	m_damage{ damage }
{
}

//Print out weapon attributes
void Weapon::printItem() const {
	std::cout << m_name << ' ' << m_ammoCount << "/" << m_maxAmmoCount << '\n';
}


//Ammo Constructor
Ammo::Ammo(const std::string_view name, const int ammoCount, const int maxAmmoCount, const std::array<std::string_view, 1> compatibleWeapons) :
	Item{ name, true }, //All ammo is stackable
	m_ammoCount{ammoCount},
	m_maxAmmoCount{maxAmmoCount},
	m_compatibleWeapons{compatibleWeapons}
{
}

//Set the current value of an ammo box
void Ammo::setAmmo(const int newAmmo) {
	m_ammoCount = newAmmo;
}

void Ammo::printCompatibleWeapons() const {
	std::cout << "Compatible weapons for " << m_name << '\n';
	for (auto& weapon : m_compatibleWeapons) {
		std::cout << weapon << '\n';
	}
}

//Print out ammo attributes
void Ammo::printItem() const {
	std::cout << m_name << " x" << m_ammoCount << '\n';
}