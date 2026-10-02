#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <iostream>
#include <string>
#include <string_view>
#include <utility> //For std::move
#include "Item.h"

class Inventory {
private:
	std::string m_name{};
	std::vector<Item*> m_inventory{}; //Create an empty vector of pointers to Items

public:
	//Constructor
	Inventory(std::string_view name, const std::size_t capacity);

	void add(Item& item); //Add something to the inventory

	Item* remove(const std::size_t slotNumber); //Remove something from the inventory

	void transfer(const std::size_t slotNumber, Inventory& destination); //Transfer one item to another inventory

	std::string_view getName() const { return m_name; }
	std::size_t getLength() const { return m_inventory.size(); }
	std::size_t getCapacity() const { return m_inventory.capacity(); }
	std::vector<Item*> getInventory() const { return m_inventory; }

	void upgradeInventory() { m_inventory.reserve(10); } //Upgrade the inventory to 10 slots

	void printInventory() const;

	void getStackIndexes(std::size_t& index_i, std::size_t& index_j); //Get the indexes of the items to be stacked 
	void stackItems(); //Function that stacks similar items together (i.e. ammo)
};

#endif