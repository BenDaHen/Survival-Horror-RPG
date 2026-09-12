#include "Inventory.h"

//Constructor
Inventory::Inventory(std::string_view name) :
	m_name{name}
{
	//Update the capacity to 10 and the length to 8 (length will go up to 10 eventually)
	m_inventory.reserve(10);
	m_inventory.resize(8);
}

void Inventory::add(const Item& item) {
	std::cout << "Adding a " << item.getName() << " to the inventory.\n";
	m_inventory.push_back(item);
}