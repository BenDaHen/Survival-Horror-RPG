#include "Inventory.h"

//Constructor
Inventory::Inventory(std::string_view name) :
	m_name{name}
{
	//Set the capacity to 8 (capacity will go up to 10 eventually)
	m_inventory.reserve(8);
}

void Inventory::add(const Item& item) {
	//Ensure that length stays within capacity
	if (m_inventory.size() < m_inventory.capacity()) {
		std::cout << "Adding a " << item.getName() << " to the inventory.\n";
		m_inventory.push_back(item);
		return;
	}
	
	//Inventory full
	std::cout << "The inventory is full. Could not add an item.\n";
}

//Look into implementing move semantics (better performance)
void Inventory::remove(const std::size_t slotNumber) {
	//Ensure that the given slot has an item
	if (slotNumber >= 1 && slotNumber <= m_inventory.size()) {
		std::size_t index{ slotNumber - 1 };

		std::cout << "Removing the item at slot #" << slotNumber << "(" << m_inventory[index].getName() << ")\n";

		//Move everything back in the inventory by 1 starting at the item to be removed (Squish)
		for (std::size_t i{ index }; i < m_inventory.size() - 1; ++i) {
			m_inventory[i] = m_inventory[i + 1];
		}

		//Remove the last item in the inventory (it is an extra copy), decrement length
		m_inventory.resize(m_inventory.size() - 1);
	}	
}