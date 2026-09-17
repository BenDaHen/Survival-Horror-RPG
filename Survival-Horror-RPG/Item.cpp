#include "Item.h"

//Item Constructor
Item::Item(const std::string_view name) :
	m_name{ name }
{
}

//Print out item attributes
std::ostream& operator<<(std::ostream& out, Item& item) {
	out << "Item: " << item.getName() << '\n';

	return out;
}

//Key Item Constructor
KeyItem::KeyItem(const std::string_view name, const std::string_view useLocation) :
	Item{ name },
	m_useLocation{ useLocation }
{
}

//Print out key item attributes
std::ostream& operator<<(std::ostream& out, KeyItem& item) {
	out << "Key Item: " << item.getName() << '\n';

	return out;
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
std::ostream& operator<<(std::ostream& out, Weapon& item) {
	out << "Weapon: " << item.getName() << '\n';

	return out;
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
std::ostream& operator<<(std::ostream& out, Ammo& item) {
	out << "Ammo: " << item.getName() << '\n';

	return out;
}