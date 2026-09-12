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
Weapon::Weapon(const std::string_view name, const int damage) :
	Item{ name },
	m_damage{ damage }
{
}