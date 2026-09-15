#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <iostream>
#include <string>
#include <string_view>
#include <utility> //For std::move
#include <optional> //For std::optional
#include "Item.h"

class Inventory {
private:
	std::string m_name{};
	std::vector<Item> m_inventory{}; //Create an empty vector of Items

public:
	//Constructor
	Inventory(std::string_view name);

	void add(const Item& item); //Add something to the inventory

	Item remove(const std::size_t slotNumber); //Remove something from the inventory

	void transfer(const std::size_t slotNumber, Inventory& destination); //Transfer one item to another inventory

	std::string_view getName() const { return m_name; }
	std::size_t getLength() const { return m_inventory.size(); }
	std::size_t getCapacity() const { return m_inventory.capacity(); }

	void upgradeInventory() { m_inventory.reserve(10); } //Upgrade the inventory to 10 slots

	//Print out the inventory
	friend std::ostream& operator<<(std::ostream& out, const Inventory& inventory) {
		out << "Printing " << inventory.m_name << '\n';

		int index{1};

		for (const auto& item : inventory.m_inventory) {
			out << "(" << index << ") Item: " << item.getName() << '\n';
			++index;
		}

		return out;
	}
};

#endif