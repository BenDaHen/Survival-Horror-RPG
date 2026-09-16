#include "Item.h"

//Item Constructor
Item::Item(const std::string_view name) :
	m_name{ name }
{
}

//Key Item Constructor
KeyItem::KeyItem(const std::string_view name, const std::string_view useLocation) :
	Item{ name },
	m_useLocation{ useLocation }
{
}

//Weapon Constructor
Weapon::Weapon(const std::string_view name, const int ammoCount, const int maxAmmoCount, const int damage) :
	Item{ name },
	m_ammoCount{ammoCount},
	m_maxAmmoCount{maxAmmoCount},
	m_damage{ damage }
{
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