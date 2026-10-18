#include "Inventory.h"

//Constructor
Inventory::Inventory(std::string_view name, const std::size_t capacity) :
	m_name{name}
{
	//Set the capacity to 8 for player inventory, item box will be larger
	//Player inventory capacity will be upgraded later
	m_inventory.reserve(capacity);
}

//Destructor
Inventory::~Inventory() {
	//Deallocate memory for every item in the inventory
	for (auto Item : m_inventory) {
		delete Item;
		Item = nullptr;
	}

	std::cout << "The " << m_name << " has been successfuly deleted.\n";
}//Inventory::~Inventory

void Inventory::add(Item* transferedItem, ItemType itemType, bool transfer) { //Pass in an item pointer for transfer, or a type to create something
	//Ensure that length stays within capacity
	if (m_inventory.size() < m_inventory.capacity()) {
		//Transfer an item from another inventory
		if (transfer) {
			m_inventory.push_back(transferedItem); //Send the item as is
			return;
		}
		//Create a new item
		else {
			//Check which type the item really is, then dynamically allocate a new item
			//Range of Items
			if (itemType >= 0 && itemType <= 2) {
				Item* newItem{ new Item {itemData[itemType]} }; //No need for relative index here since it is the first set in the enum
				newItem->setAddress(&newItem); //Save the address in the item for later use
				std::cout << "Created a " << newItem->getName() << ", adding it to the inventory.\n";
				m_inventory.push_back(newItem); //Push raw pointer to the inventory
				return;
			}
			//Range of Key Items
			else if (itemType >= 3 && itemType <= 5) {
				int relativeKeyItemIndex{ itemType - 3 }; //Get the relative index of key items (i.e. item 3 in the enum would be item 0 in keyItemData)

				KeyItem* newItem{ new KeyItem {keyItemData[relativeKeyItemIndex]} }; //itemType is out of bounds for keyItemData here
				//newItem->setAddress(&newItem); //Save the address in the item for later use
				std::cout << "Created a " << newItem->getName() << ", adding it to the inventory.\n";
				m_inventory.push_back(newItem); //Push raw pointer to the inventory
				return;
			}
			//Range of Weapons
			else if (itemType >= 6 && itemType <= 8) {
				int relativeWeaponIndex{ itemType - 6 }; //Get the relative index of weapons (i.e. item 6 in the enum would be item 0 in weaponData)

				Weapon* newItem{ new Weapon {weaponData[relativeWeaponIndex]} }; //itemType is out of bounds for keyItemData here
				//newItem->setAddress(&newItem); //Save the address in the item for later use
				std::cout << "Created a " << newItem->getName() << ", adding it to the inventory.\n";
				m_inventory.push_back(newItem); //Push raw pointer to the inventory
				return;
			}
			//Range of Ammo
			else if (itemType >= 9 && itemType <= 14) {
				int relativeAmmoIndex{ itemType - 9 }; //Get the relative index of ammo (i.e. item 9 in the enum would be item 0 in ammoData)

				Ammo* newItem{ new Ammo {ammoData[relativeAmmoIndex]} }; //itemType is out of bounds for keyItemData here
				//newItem->setAddress(&newItem); //Save the address in the item for later use
				std::cout << "Created a " << newItem->getName() << ", adding it to the inventory.\n";
				m_inventory.push_back(newItem); //Push raw pointer to the inventory
				return;
			}
		}
	}
	
	//Inventory full
	std::cout << "The inventory is full. Could not add an item.\n";

	//Let the dynamically allocated item go out of scope, it's location is known in the inventory, and the address has been saved
}//Inventory::add

Item* Inventory::remove(const std::size_t slotNumber, bool transfer) {
	//Ensure that the given slot has an item
	if (slotNumber >= 1 && slotNumber <= m_inventory.size()) {
		std::size_t index{ slotNumber - 1 };

		std::cout << "Removing the item at slot #" << slotNumber << " (" << m_inventory[index]->getName() << ")\n";

		Item* removed{ std::move(m_inventory[index]) }; //Pointer to the removed item (not new memory)

		//Move everything back in the inventory by 1 starting at the item to be removed (Squish)
		for (std::size_t i{ index }; i < m_inventory.size() - 1; ++i) {
			m_inventory[i] = std::move(m_inventory[i + 1]); //Uses move semantics to avoid expensive copies
		}

		//Remove the last item in the inventory (it is an extra copy), decrement length
		m_inventory.resize(m_inventory.size() - 1);

		std::cout << "The removed Item: ";
		removed->printItem();

		//In the event of a transfer, return the item that was removed so it can be added to the other inventory
		if (transfer) {
			return removed;
		}
		
		//Otherwise delete the item that was removed
		std::cout << "Deleting the " << removed->getName() << '\n';
		delete removed;
		removed = nullptr;
	}	

	//Return empty item pointer if failed or no transfer
	Item* ptr{};
	return ptr;
}//Inventory::remove

//Initiate a transfer by removing frome one inventory and adding the removed item to another inventory
void Inventory::transfer(const std::size_t slotNumber, Inventory& destination) {
	Item* toTransfer{ std::move(remove(slotNumber, true)) };

	std::cout << "Transfering the " << toTransfer->getName() << " from " << m_name << " to " << destination.getName() << '\n';

	destination.add(toTransfer, {}, true); //Pass an item for transfering (not creating a new item)
}//Inventory::transfer

//Print out the inventory
void Inventory::printInventory() const {
	std::cout << "Printing " << m_name << '\n';

	int index{ 1 };

	for (const auto item : m_inventory) {
		std::cout << "(" << index << ") ";
		item->printItem();
		
		++index;
	}

	std::cout << index - 1 << "/" << m_inventory.capacity() << '\n';
}//Inventory::operator<<

//Get the indexes for item stacking
void Inventory::getStackIndexes(std::size_t& recievingIndex, std::size_t& sendingIndex) {
	//Check for similarly named ammo in the inventory (names are the same regardless of stack size)
	for (std::size_t item_i{ 0 }; item_i < m_inventory.size(); ++item_i) {
		for (std::size_t item_j{ item_i }; item_j < m_inventory.size(); ++item_j) {
			//If the names are equal, are not referencing the same index, and the item is stackable then get the locations and indexes of the items in the inventory
			if (m_inventory[item_i]->getName() == m_inventory[item_j]->getName() && item_i != item_j && m_inventory[item_i]->isStackable()) {
				std::cout << "Item #" << item_i + 1 << ' ' << m_inventory[item_i]->getName() << " can be stacked with Item #" << item_j + 1 << ' ' << m_inventory[item_j]->getName() << '\n';

				//Update the item indexes
				recievingIndex = item_i;
				sendingIndex = item_j;

				//Return to the stacking process
				return;
			}
		}
	}

	//Loop will always return early since full stack and half stack is considered "stackable"
}//getStackIndexes

//Stack similar items together
void Inventory::stackItems() {
	//Only stacking ammo together
	Ammo* recievingItem{};
	Ammo* sendingItem{};
	std::size_t recievingIndex{};
	std::size_t sendingIndex{};

	//Get the indexes of the items to be stacked
	getStackIndexes(recievingIndex, sendingIndex);

	//Update the pointers to the items in main function scope
	recievingItem = dynamic_cast<Ammo*>(m_inventory[recievingIndex]);
	sendingItem = dynamic_cast<Ammo*>(m_inventory[sendingIndex]);

	//Make sure that the dynamic casts are not null
	if (!recievingItem || !sendingItem) {
		std::cout << "Dynamic cast failed for ammo stacking (Or nothing can be stacked).\n";
		return;
	}

	//If there is space to stack the ammo (This also needs to delete the memory associated with the old stack)
	if (recievingItem->getAmmo() + sendingItem->getAmmo() <= recievingItem->getMaxAmmo()) {
		recievingItem->setAmmo(recievingItem->getAmmo() + sendingItem->getAmmo()); //Reciving ammo stack gets the sending ammo stack

		//Move everything back in the inventory by 1 starting at the item to be removed (Squish)
		for (std::size_t i{ sendingIndex }; i < m_inventory.size() - 1; ++i) {
			m_inventory[i] = std::move(m_inventory[i + 1]); //Uses move semantics to avoid expensive copies
		}

		//Remove the last item in the inventory (it is an extra copy), decrement length
		m_inventory.resize(m_inventory.size() - 1);

		return;
	}
	//If there is space to stack some of the ammo
	else if (recievingItem->getAmmo() + sendingItem->getAmmo() > recievingItem->getMaxAmmo() && recievingItem->getAmmo() < recievingItem->getMaxAmmo()) {
		int excessAmmo{recievingItem->getAmmo() + sendingItem->getAmmo() - recievingItem->getMaxAmmo()}; //Extra ammo for the second stack

		//Recieving item is maxed out, sending item keeps the excess
		recievingItem->setAmmo(recievingItem->getMaxAmmo());
		sendingItem->setAmmo(excessAmmo);

		return;
	}

	//No stacking possible
	std::cout << "No stacking possible.\n";
}//Inventory::stackItems