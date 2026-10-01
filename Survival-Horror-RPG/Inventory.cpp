#include "Inventory.h"

//Constructor
Inventory::Inventory(std::string_view name, const std::size_t capacity) :
	m_name{name}
{
	//Set the capacity to 8 for player inventory, item box will be larger
	//Player inventory capacity will be upgraded later
	m_inventory.reserve(capacity);
}

void Inventory::add(Item& item) {
	//Ensure that length stays within capacity
	if (m_inventory.size() < m_inventory.capacity()) {
		std::cout << "Adding a " << item.getName() << " to the inventory.\n";
		m_inventory.push_back(&item); //Pass address for pointer vector
		return;
	}
	
	//Inventory full
	std::cout << "The inventory is full. Could not add an item.\n";
}

Item* Inventory::remove(const std::size_t slotNumber) {
	//Ensure that the given slot has an item
	if (slotNumber >= 1 && slotNumber <= m_inventory.size()) {
		std::size_t index{ slotNumber - 1 };

		std::cout << "Removing the item at slot #" << slotNumber << " (" << m_inventory[index]->getName() << ")\n";

		Item* removed{ std::move((m_inventory[index])) }; //Pointer to the removed item

		//Move everything back in the inventory by 1 starting at the item to be removed (Squish)
		for (std::size_t i{ index }; i < m_inventory.size() - 1; ++i) {
			m_inventory[i] = std::move(m_inventory[i + 1]); //Uses move semantics to avoid expensive copies
		}

		//Remove the last item in the inventory (it is an extra copy), decrement length
		m_inventory.resize(m_inventory.size() - 1);

		std::cout << "The removed Item: ";
		removed->printItem();

		//Return the item that was removed in the event of a transfer
		return removed;
	}	

	//Return item at index 0 if failed
	Item* ptr{ m_inventory[0] };
	return ptr;
}//Inventory::remove

//Current issue with pointers lies here
//toTransfer is a temp object that gets destroyed at the end of transfer, creating a dangling reference in the item box
void Inventory::transfer(const std::size_t slotNumber, Inventory& destination) {
	Item* toTransfer{ std::move(remove(slotNumber)) };

	std::cout << "Transfering the " << toTransfer->getName() << " from " << m_name << " to " << destination.getName() << '\n';

	destination.add(*toTransfer);
}//Inventory::transfer

//Print out the inventory
void Inventory::printInventory() const {
	std::cout << "Printing " << m_name << '\n';

	int index{ 1 };

	for (const auto* item : m_inventory) {
		std::cout << "(" << index << ") ";
		item->printItem();
		
		++index;
	}

	std::cout << index - 1 << "/" << m_inventory.capacity() << '\n';
}//Inventory::operator<<

//Stack similar items together
void Inventory::stackItems() {
	//Stacking just ammo together

	//Check for similarly named ammo in the inventory (names are the same regardless of stack size)
	for (std::size_t item_i{ 0 }; item_i < m_inventory.size(); ++item_i) {
		for (std::size_t item_j{ item_i }; item_j < m_inventory.size(); ++item_j) {
			//If the names are equal then stack the items
			if (m_inventory[item_i]->getName() == m_inventory[item_j]->getName() && m_inventory[item_i] != m_inventory[item_j]) {
				//Just ammo that gets stacked for now
				std::cout << "Item " << m_inventory[item_i]->getName() << " equals item " << m_inventory[item_j]->getName();
			}
		}
	}

}//Inventory::stackItems